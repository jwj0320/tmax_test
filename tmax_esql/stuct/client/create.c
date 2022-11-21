#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <usrinc/atmi.h>

int main(int argc, char *argv[])
{
    char *recvbuf;
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

    if ((recvbuf = tpalloc("STRING", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        tpend();
        exit(1);
    }

    
    if (tpcall("CREATETABLE", NULL, 0, &recvbuf, &olen, TPNOFLAGS) == -1)
    {
        fprintf(stderr,"Can’t send request to service CREATETABLE->%s !\n",
                tpstrerror(tperrno));
        tpfree(recvbuf);
        tpend();
        exit(1);
    }

    printf("Server: %s\n",recvbuf);
    tpfree(recvbuf);
    tpend();

}