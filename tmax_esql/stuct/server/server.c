#ifndef _TBPC_COMMON_SRC_GEN
#define _TBPC_COMMON_SRC_GEN



#define TBSQLCODE_NOTFOUND 1403



/*
==========================================
        host variable type
==========================================
*/

typedef enum esql_hostvar_type_e {

    /* string */
    ESQL_TYPE_CHARP = 0,        /* (signed) char* */
    ESQL_TYPE_UCHARP,           /* unsigned char* */
    ESQL_TYPE_CHAR_ARRAY,       /* (signed) char[n] */
    ESQL_TYPE_UCHAR_ARRAY,      /* unsigned char[n] */

    /* char */
    ESQL_TYPE_CHAR,             /* (signed) char */
    ESQL_TYPE_UCHAR,            /* unsigned char */

    /* int */
    ESQL_TYPE_INT,              /* (signed) int */
    ESQL_TYPE_UINT,             /* unsigned int */

    /* short */
    ESQL_TYPE_SHORT,            /* (signed) short (int) */
    ESQL_TYPE_USHORT,           /* unsigned short */

    /* long */
    ESQL_TYPE_LONG,             /* (signed) long (int) */
    ESQL_TYPE_ULONG,            /* unsigned long (int) */

    /* float/double */
    ESQL_TYPE_FLOAT,            /* float */
    ESQL_TYPE_DOUBLE,           /* double */

    /* VARCHAR */
    ESQL_TYPE_VARCHAR,          /* VARCHAR[n] */
    ESQL_TYPE_VARCHARP,         /* VARCHAR* */

    /* EXTERNAL DATATYPE */
    ESQL_TYPE_VARRAW,           /* VARRAW */
    ESQL_TYPE_LONG_VARRAW,      /* LONG VARRAW */

    /* EXTENED DATATYPE */
    ESQL_TYPE_NCHAR_ARRAY,      /* NCHAR */

    /* LOB */
    ESQL_TYPE_CLOB,             /* CLOB */
    ESQL_TYPE_BLOB,             /* BLOB */
    ESQL_TYPE_BFILE,            /* BFILE */

    /* COBOL COMP3 */
    ESQL_TYPE_CBL_COMP3,        /* COBOL COMP3 */
    ESQL_TYPE_EXT_VARCHAR,      /* external datatype */

    /* CURSOR */
    ESQL_TYPE_CURSOR,           /* SQL_CURSOR */

    ESQL_TYPE_LONGLONG,         /* INT64_t */ 
    ESQL_TYPE_ULONGLONG,        /* usigned INT64_t */ 

    ESQL_HVTYPE_EXT_NUMBER          = 30,
    ESQL_HVTYPE_EXT_VARNUM          = 31,
    ESQL_HVTYPE_EXT_INTEGER         = 32,
    ESQL_HVTYPE_EXT_FLOAT           = 33,
    ESQL_HVTYPE_EXT_LONG            = 34,
    ESQL_HVTYPE_EXT_UNSIGNED        = 35,
    ESQL_HVTYPE_EXT_CHAR            = 36,
    ESQL_HVTYPE_EXT_CHARZ           = 37,
    ESQL_HVTYPE_EXT_CHARF           = 38,
    ESQL_HVTYPE_EXT_STRING          = 39,
    ESQL_HVTYPE_EXT_VARCHAR         = 40,
    ESQL_HVTYPE_EXT_VARCHAR2        = 41,
    ESQL_HVTYPE_EXT_LONG_VARCHAR    = 42,
    ESQL_HVTYPE_EXT_VARRAW          = 43,
    ESQL_HVTYPE_EXT_LONG_VARRAW     = 44,
    ESQL_HVTYPE_EXT_RAW             = 45,
    ESQL_HVTYPE_EXT_ROWID           = 46,
    ESQL_HVTYPE_EXT_LONG_RAW        = 47 
} esql_hostvar_type_t;



/*
==========================================
       ESQL type 
==========================================
*/

typedef enum esql_type_t {
    /* CONNECT */
    ESQL_TYPE_CONNECT = 1,

    /* DML */
    ESQL_TYPE_SELECT,
    ESQL_TYPE_EXECUTE_DML,

    /* cursor */
    ESQL_TYPE_OPEN_CURSOR,
    ESQL_TYPE_CLOSE_CURSOR,
    ESQL_TYPE_FETCH,

    ESQL_TYPE_COMMIT,
    ESQL_TYPE_COMMIT_RELEASE,
    ESQL_TYPE_ROLLBACK,
    ESQL_TYPE_ROLLBACK_RELEASE,
    ESQL_TYPE_ROLLBACK_TO_SAVEPOINT,

    /* DDL */
    ESQL_TYPE_DDL,  

    /* PSM */
    ESQL_TYPE_PSM,  

    ESQL_TYPE_DYN_EXEC_IMMED,
    ESQL_TYPE_DYN_EXECUTE,
    ESQL_TYPE_DYN_PREPARE,
    ESQL_TYPE_DYN_OPEN_CURSOR,
    ESQL_TYPE_DYN_DESC_BIND,
    ESQL_TYPE_DYN_DESC_SELECT,

    ESQL_TYPE_ANSIDYN_ALLOC_DESC,
    ESQL_TYPE_ANSIDYN_DEALLOC_DESC,
    ESQL_TYPE_ANSIDYN_SET_DESC,
    ESQL_TYPE_ANSIDYN_GET_DESC,
    ESQL_TYPE_ANSIDYN_DESC_INPUT,
    ESQL_TYPE_ANSIDYN_DESC_OUTPUT,

    /* THREAD & CONTEXT */
    ESQL_TYPE_ENABLE_THREADS,
    ESQL_TYPE_CONTEXT_ALLOCATE,
    ESQL_TYPE_CONTEXT_USE,
    ESQL_TYPE_CONTEXT_FREE,

    /* ALLOCATE & FREE */
    ESQL_TYPE_ALLOCATE,
    ESQL_TYPE_FREE,

    /* LOB */
    ESQL_TYPE_LOB_APPEND,
    ESQL_TYPE_LOB_ASSIGN,
    ESQL_TYPE_LOB_CLOSE,
    ESQL_TYPE_LOB_COPY,
    ESQL_TYPE_LOB_CREATE_TEMP,
    ESQL_TYPE_LOB_DESCRIBE,
    ESQL_TYPE_LOB_ERASE,
    ESQL_TYPE_LOB_FREE_TEMP,
    ESQL_TYPE_LOB_OPEN,
    ESQL_TYPE_LOB_READ,
    ESQL_TYPE_LOB_TRIM,
    ESQL_TYPE_LOB_WRITE,

    /* ETC */
    ESQL_TYPE_START_SQL,
    ESQL_TYPE_END_SQL,

    ESQL_TYPE_REGISTER_CONNECT,
    ESQL_TYPE_XA_SET_CONNECTION
} esql_type_t;



/*
==========================================
       char_map 
==========================================


CHAR_MAP  fixed-length  blank-padded  null-terminated  NULL is fixed-length
(DBMS)                                                      blank-padded
---------------------------------------------------------------------------
VARCHAR2        o           o             x               o
CHARF           o           o             x               x
CHARZ           o           o             o               o
STRING          x           x             o               x
*/

typedef enum char_map_e {
    CHAR_MAP_DEFAULT = 0,
    CHAR_MAP_VARCHAR2,
    CHAR_MAP_CHARF,
    CHAR_MAP_CHARZ,
    CHAR_MAP_STRING
} char_map_t;



typedef enum esql_desc_item_e {
    ESQL_DESC_ITEM_NONE = 0,
    ESQL_DESC_ITEM_TYPE,
    ESQL_DESC_ITEM_LENGTH,
    ESQL_DESC_ITEM_INDICATOR,
    ESQL_DESC_ITEM_INDICATOR_P,
    ESQL_DESC_ITEM_DATA,
    ESQL_DESC_ITEM_DATA_P,
    ESQL_DESC_ITEM_OCTET_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH_P,
    ESQL_DESC_ITEM_RETURNED_OCTET_LENGTH,
    ESQL_DESC_ITEM_PRECISION,
    ESQL_DESC_ITEM_SCALE,
    ESQL_DESC_ITEM_NULLABLE,
    ESQL_DESC_ITEM_NAME,
    ESQL_DESC_ITEM_CHARACTER_SET_NAME,
    ESQL_DESC_COUNT
} esql_desc_item_t;



#include <string.h>


#include "sqlca.h"
typedef struct esql_cpool_env_s {
    int cpool_max;
    int cpool_min;
    int cpool_incr;
    int cpool_timeout;
    int cpool_nowait;
}esql_cpool_env_t;


typedef void * sql_context;
typedef void * SQL_CONTEXT;



typedef void * sql_cursor;
typedef void * SQL_CURSOR;



typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;




typedef struct esql_sqlctx_ext {
    unsigned short     version;
    esql_cpool_env_t  *cp_env;
    void* reserved[20];
}esql_sqlctx_ext_t;




static struct esql_sqlctx {
    esql_type_t     stmt_type;

    char           *db_name;
    char           *cursor_name;
    char           *pstmt_name;
    char           *savepoint;
    char           *stmt;

    char_map_t      char_map;
    int             stmt_cache_size;
    int             fetch_type;
    int             abs_rel_nth;
    int             flag;
    int             option;

    struct sqlca   *sqlca;
    void           *sqlda;

    char           *desc_name;
    char           *desc_into;
    int             value;

    sql_context    *sql_ctx;
    char           *sqlstate;

    unsigned int    file_id;
    unsigned int    prefetch;

    int             rmid;

    unsigned int    dummy[2];

    esql_sqlctx_ext_t *sqlctx_ext;

    void           *oraca;
    void           *ep_ctx;

    unsigned int    iter_cnt;               /* count of iteration */
    unsigned int    host_var_total_cnt;     /* total # of host var */
    unsigned int    host_var_out_cnt;       /* # of out host var */

    void               **p_hostvar;         /* array of host var */
    unsigned int        *p_hostvar_len;     /* array of length of host var */
    unsigned int        *p_hostvar_stride;  /* array of stride of host var */
    esql_hostvar_type_t *p_hostvar_type;    /* array of host var type */
    unsigned int        *p_param_type;      /* array of param type */
    esql_desc_item_t    *p_ansi_dyn_type;   /* array of ansi dyn item type */
    void               **p_hostind;         /* array of host ind */
    unsigned int        *p_hostind_stride;  /* array of stride of host ind */
    long                *p_ind;             /* array of indicator */


    void                *hostvar[1];        /* array of host var */
    unsigned int         hostvar_len[1];    /* array of length of host var */
    unsigned int         hostvar_stride[1]; /* array of stride of host var */
    esql_hostvar_type_t  hostvar_type[1];   /* array of host var type */
    unsigned int         param_type[1];     /* array of param type */
    esql_desc_item_t     ansi_dyn_type[1];  /* array of ansi dyn item type */
    void                *hostind[1];        /* array of host ind */
    unsigned int         hostind_stride[1]; /* array of stride of host ind */
    long                 ind[1];            /* array of indicator */

} sqlstm;


extern void esql_do(struct esql_sqlctx *_sqlctx);
extern void esql_do_odbc(struct esql_sqlctx *_sqlctx);
extern void esql_do_oci(struct esql_sqlctx *_sqlctx);



#endif



#include <stdio.h> 
#include <sqlca.h> 
#include <string.h>
#include <usrinc/atmi.h>
#include "../../sdl/mem_sdl.h"
#define USERPASS "tibero/tmax" 




void CREATETABLE(TPSVCINFO *msg)
{
    char *sendbuf;

    	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
                                
/*	        VARCHAR userpass[20] = {strlen(USERPASS), USERPASS};	*/
struct __tag27 { unsigned short len; unsigned char arr[20]; } userpass = {strlen(USERPASS), USERPASS};
 
    	/*
		EXEC SQL END DECLARE SECTION;
	 */
 

    	/*
		EXEC SQL CONNECT :userpass;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(userpass));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(userpass.arr);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_VARCHAR;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}



    	/*
		EXEC SQL CREATE TABLE MEMBER(
        id NUMBER NOT NULL,
        name VARCHAR2(50) NOT NULL,
        dept VARCHAR2(50)
    );
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_DDL;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "CREATE TABLE MEMBER(\n\
        id NUMBER NOT NULL,\n\
        name VARCHAR2(50) NOT NULL,\n\
        dept VARCHAR2(50)\n\
    )";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}



    	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    if ((sendbuf = tpalloc("STRING", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        exit(1);
    }

    strcpy(sendbuf,"Table is created.");

    tpreturn(TPSUCCESS, 0, sendbuf, 0, TPNOFLAGS);
}



void ADDMEMBER(TPSVCINFO *msg)
{ 
    	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
                                
/*	        VARCHAR userpass[20] = {strlen(USERPASS), USERPASS};	*/
struct __tag28 { unsigned short len; unsigned char arr[20]; } userpass = {strlen(USERPASS), USERPASS};
 
    	/*
		EXEC SQL END DECLARE SECTION;
	 */
 


    	/*
		EXEC SQL CONNECT :userpass;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(userpass));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(userpass.arr);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_VARCHAR;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    char *id, *name, *dept;

    struct mem *data=(struct mem*)msg->data;

    // strcpy(id, data->id);
    // strcpy(name, data->name);
    // strcpy(dept, data->dept);
    id = data->id;
    name = data->name;
    dept = data->dept;


    	/*
		EXEC SQL INSERT INTO MEMBER(
        id,
        name,
        dept
    ) values
    (
        id,
        name,
        dept
    );
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "INSERT INTO MEMBER(\n\
        id,\n\
        name,\n\
        dept\n\
    ) values\n\
    (\n\
        id,\n\
        name,\n\
        dept\n\
    )";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 0;
    __sqlctx.host_var_out_cnt   = 0;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}



    	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 111;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

}
