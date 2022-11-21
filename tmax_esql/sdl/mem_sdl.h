
#ifndef ORA_PROC

#include <netinet/in.h>

#include <arpa/inet.h>

#endif

#include "/root/shared/OF71/OHOME/tmax/usrinc/sdl.h"


extern  char *sdl_encode_mem(char *dp1, char *dp2); 
extern  char *sdl_decode_mem(char *dp1, char *dp2); 


struct mem {
char id[50]		/* null = '\0' */;
char name[50]		/* null = '\0' */;
char dept[40]		/* null = '\0' */;
};
