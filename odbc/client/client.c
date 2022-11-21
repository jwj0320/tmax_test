#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/fbuf.h>
#include "../../tmax_esql/fdl/mem_fdl.h"


int main(int argc, char *argv[])
{
    // char *sendbuf;
    char *recvbuf;

    char id[50]={0};
    char name[50] ={0};
    char dept[50] ={0};
    long olen;
    int rowcount;
    int i;

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

    // if ((sendbuf = tpalloc("STRING", NULL, 0)) == NULL)
    // {
    //     fprintf(stderr,"Error allocation send buffer\n");
    //     printf("%s\n",tpstrerror(tperrno));
    //     tpend();
    //     exit(1);
    // // }
    // if ((recvbuf = tpalloc("FIELD", NULL, 0)) == NULL)
    // {
    //     fprintf(stderr,"Error allocation buffer\n");
    //     printf("%s\n",tpstrerror(tperrno));
    //     tpend();
    //     exit(1);
    // }

    // if (tpcall("GETROWCOUNTFROMTABLE", NULL, 0, &recvbuf, &olen, TPNOFLAGS) == -1)
    // {
    //     fprintf(stderr,"Can’t send request to service GETROWCOUNTFROMTABLE->%s !\n",
    //             tpstrerror(tperrno));
    //     // tpfree(sendbuf);
    //     tpfree(recvbuf);
    //     tpend();
    //     exit(1);
    // }

    // rowcount=atoi(recvbuf);

    // tpfree(recvbuf);

    if ((recvbuf = tpalloc("STRING", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        tpend();
        exit(1);
    }


    if (tpcall("SELECTFROMTABLE", NULL, 0, &recvbuf, &olen, TPNOFLAGS) == -1)
    {
        fprintf(stderr,"Can’t send request to service SELECTFROMTABLE->%s !\n",
                tpstrerror(tperrno));
        // tpfree(sendbuf);
        tpfree(recvbuf);
        tpend();
        exit(1);
    }



    // puts("Name: ");
    // fgets(name,50,stdin);
    // name[strcspn(name, "\n")] = 0;
    
    // puts("Dept: ");
    // fgets(dept,50,stdin);
    // dept[strcspn(dept, "\n")] = 0;
    
    // fbput(sendbuf,ID,id,0);
    // fbput(sendbuf,NAME,name,0);
    // fbput(sendbuf,DEPT,dept,0);
    


    printf("Server: \n%s\n",recvbuf);
    // tpfree(sendbuf);
    tpfree(recvbuf);
    tpend();

}