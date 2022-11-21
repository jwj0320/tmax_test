#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
#include <usrinc/atmi.h>


void SELECTFROMTABLE(TPSVCINFO *msg)
{ 
    SQLHENV     env;    // Handle ODBC enviroment
    SQLHDBC     dbc;    // Handle connection
    SQLHSTMT    stmt;   // Handle statement
    SQLLEN      err;
    
    char *sendbuf;

    char        field1[200]={0};
    char        field2[200]={0};
    char        field3[200]={0};

    SQLCHAR* server_name=(SQLCHAR*)"tb_fix3";
    SQLCHAR* user_name=(SQLCHAR*)"tibero";
    SQLCHAR* password=(SQLCHAR*)"tmax";

    SQLRETURN ret;

    if ((sendbuf = tpalloc("STRING", NULL, 0)) == NULL)
    {
        fprintf(stderr,"Error allocation buffer\n");
        printf("%s\n",tpstrerror(tperrno));
        strcpy(msg->data,"Error allocation buffer");
        tpreturn(TPFAIL, 0, msg->data, 0, TPNOFLAGS);
    }

    if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env) < 0)
    {
        printf("SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env) Error!\n");
        strcpy(sendbuf,"SQLAllocHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);
    }
    if (SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0) < 0)
    {
        printf("SQLSetEnvAttr( env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0) Error!\n");
        strcpy(sendbuf,"SQLSetEnvAttr");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);    
    }
    if (SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc) < 0)
    {
        printf("SQLAllocHandle( SQL_HANDLE_DBC, env, &dbc) Error!\n");
        strcpy(sendbuf,"SQLAllocHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);   
    }
    if (SQLConnect(dbc, server_name, SQL_NTS, user_name, SQL_NTS, password, SQL_NTS) < 0)
    {
        printf("SQLConnect( dbc, server_name, SQL_NTS, user_name, SQL_NTS, password, SQL_NTS) Error!\n");
        strcpy(sendbuf,"SQLConnect");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }
    if (SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt) < 0)
    {
        printf("SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt) Error!\n");
        strcpy(sendbuf,"SQLAllocHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }
    if (SQLBindCol(stmt, 1, SQL_C_CHAR, field1, sizeof(field1), &err) < 0 ||
        SQLBindCol(stmt, 2, SQL_C_CHAR, field2, sizeof(field2), &err) < 0 ||
        SQLBindCol(stmt, 3, SQL_C_CHAR, field3, sizeof(field3), &err) < 0)
    {
        printf("Bind Error!\n");
        strcpy(sendbuf,"Bind");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }
    if (SQLExecDirect(stmt, (SQLCHAR *)"SELECT * FROM MEMBER", SQL_NTS) < 0)
    {
        printf("SQLExecDirect Error!\n");
        strcpy(sendbuf,"SQLExecDirect");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }

    sprintf(sendbuf,"        %36s, %20s, %20s\n", "ID", "NAME", "DEPT");
    sprintf(sendbuf+strlen(sendbuf),"----------------------------------------------------------------------------------------\n");

    while (ret = SQLFetch(stmt) != SQL_NO_DATA)
    {
        if (ret < 0)
        {
            printf("SQLFetch(stmt) Error!\n");
            strcpy(sendbuf,"SQLFetch");
            tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
        }
        sprintf(sendbuf+strlen(sendbuf),"Result: %36s, %20s, %20s\n", field1, field2, field3);

    }

    if (SQLFreeHandle(SQL_HANDLE_STMT, stmt) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_STMT, stmt) Error!\n");
        strcpy(sendbuf,"SQLFreeHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }

    if (SQLDisconnect(dbc) < 0)
    {
        printf("SQLDisconnect(dbc) Error!\n");
        strcpy(sendbuf,"SQLDisconnect");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }

    if (SQLFreeHandle(SQL_HANDLE_DBC, dbc) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_DBC, dbc) Error!\n");
        strcpy(sendbuf,"SQLFreeHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }

    if (SQLFreeHandle(SQL_HANDLE_ENV, env) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_ENV, env) Error!\n");
        strcpy(sendbuf,"SQLFreeHandle");
        tpreturn(TPFAIL, 0, sendbuf, 0, TPNOFLAGS);  
    }



    tpreturn(TPSUCCESS, 0, sendbuf, 0, TPNOFLAGS);
}

