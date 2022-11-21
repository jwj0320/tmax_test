#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <usrinc/atmi.h>
#include <usrinc/fbuf.h>
#include "../../fdl/mem_fdl.h"

void generateUUID( char *pUUID )
{
	int t = 0;
	char *szTemp = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";
	char *szHex = "0123456789abcdef-";
	int nLen = strlen (szTemp);

	srand (time(NULL));
	
	for (t=0; t<nLen; t++)
	{
		int r = rand () % 16;
		char c = ' ';	
	
		switch (szTemp[t])
		{
			case 'x' : 
				c = szHex [r]; 
				break;
			case 'y' : 
				c = szHex [r & 0x03 | 0x08];
				break;
			case '-' : 
				c = '-'; 
				break;
			case '4' : 
				c = '4';
				break;
			default : 
				break;
		}	
		pUUID[t] = c;
	}	
	pUUID[t] = 0;
}

int main(int argc, char *argv[])
{
    FBUF *sendbuf;
    char *recvbuf;

    char id[50]={0};
    char name[50] ={0};
    char dept[50] ={0};
    long olen;

    if (argc != 1)
    {
        fprintf(stderr, "Usage: $ %s \n", argv[0]);
        exit(1);
    }

    if (tpstart((TPSTART_T *)NULL) == -1)
    {
        fprintf(stderr,"Tpstart failed\n");
        exit(1);
    }

    if ((sendbuf = tpalloc("FIELD", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation send buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        tpend();
        exit(1);
    }
    if ((recvbuf = tpalloc("STRING", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        tpend();
        exit(1);
    }

    generateUUID(id);

    puts("Name: ");
    fgets(name,50,stdin);
    name[strcspn(name, "\n")] = 0;
    
    puts("Dept: ");
    fgets(dept,50,stdin);
    dept[strcspn(dept, "\n")] = 0;
    
    fbput(sendbuf,ID,id,0);
    fbput(sendbuf,NAME,name,0);
    fbput(sendbuf,DEPT,dept,0);
    



    if (tpcall("ADDMEMBER", (char *)sendbuf, 0, &recvbuf, &olen, TPNOFLAGS) == -1)
    {
        fprintf(stderr,"Can’t send request to service ADDMEMBER->%s !\n",
                tpstrerror(tperrno));
        tpfree(sendbuf);
        tpfree(recvbuf);
        tpend();
        exit(1);
    }

    printf("Server: %s\n",recvbuf);
    tpfree(sendbuf);
    tpfree(recvbuf);
    tpend();

}