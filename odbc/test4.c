#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
 
int main() 
{ 
    SQLHENV     env;    // Handle ODBC enviroment
    SQLHDBC     dbc;    // Handle connection
    SQLHSTMT    stmt;   // Handle statement
    SQLLEN      err;
    SQLLEN      rowanz;
    SQLSMALLINT colanz;

    SQLCHAR* server_name=(SQLCHAR*)"tb_fix3";
    SQLCHAR* user_name=(SQLCHAR*)"tibero";
    SQLCHAR* password=(SQLCHAR*)"tmax";
    
 
    SQLRETURN   ret;


    char        field1[200]={0};
    char        field2[200]={0};
    char        field3[200]={0};

    /*
     * 환경, 연결, 그리고 명령문 핸들을 위한 메모리를 할당하고 초기화 한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075598107&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */
    if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env) < 0)
    {
        printf("SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env) Error!\n");
        exit(1);
    }

    /*
     * ODBC: Version: Set
     * (현재 환경에 대한 환경 속성을 설정한다.)
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075614956&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */

    if (SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0) < 0)
    {
        printf("SQLSetEnvAttr( env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0) Error!\n");
        exit(1);
    }

    // DBC: Allocate
    if (SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc) < 0)
    {
        printf("SQLAllocHandle( SQL_HANDLE_DBC, env, &dbc) Error!\n");
        exit(1);
    }

    /*
     * DB와의 연결을 설정한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075600429&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */
    if (SQLConnect(dbc, server_name, SQL_NTS, user_name, SQL_NTS, password, SQL_NTS) < 0)
    {
        printf("SQLConnect( dbc, server_name, SQL_NTS, user_name, SQL_NTS, password, SQL_NTS) Error!\n");
        exit(1);
    }

    // ret=SQLDriverConnect(dbc,NULL,(SQLCHAR*) "DRIVER={tb_fix3};\
    //                                       SERVER=127.0.0.1;PORT=9274;UID=tibero;PWD=tmax;",
    //                                       SQL_NTS,
    //                                       NULL,
    //                                       0,
    //                                       NULL,
    //                                       SQL_DRIVER_NOPROMPT);
    
    printf("%d\n",ret);
    // printf("%s\n",SQLGetDiagRec())
    /*
     * 명령핸들ID 할당.
     * https://kb.askmonty.org/en/sqlallochandlesql_handle_stmt/
     */
    if (SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt) < 0)
    {
        printf("SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt) Error!\n");
        exit(1);
    }

    /*
     * 모든 데이터 타입에 대해 애플리케이션 변수들을 (application data buffers) 결과 집합의 열들에 바인드한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075598934&redirect=Dlog&widgetTypeCall=true
     */
    // SQLBindCol(stmt, 1 , SQL_C_LONG, &tmpMediaID, sizeof(tmpMediaID), &err);
    // SQLBindCol(stmt, 2 , SQL_C_CHAR, buffer, sizeof(buffer), &err);

    if (SQLBindCol(stmt, 1, SQL_C_CHAR, field1, sizeof(field1), &err) < 0 ||
        SQLBindCol(stmt, 2, SQL_C_CHAR, field2, sizeof(field2), &err) < 0 ||
        SQLBindCol(stmt, 3, SQL_C_CHAR, field3, sizeof(field3), &err) < 0)
    {
        printf("Bind Error!\n");
        exit(1);
    }

    /*
     * 주어진 SQL 문장을 직접 실행
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075604687&parentCategoryNo=77&viewDate=&currentPage=1&listtype=0
     */

    if (SQLExecDirect(stmt, (SQLCHAR *)"SELECT * FROM MEMBER", SQL_NTS) < 0)
    {
        printf("SQLExecDirect Error!\n");
        exit(1);
    }

    /*
     * 결과 집합의 열의 개수를 반환한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075611803&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */

    if (SQLNumResultCols(stmt, &colanz) < 0)
    {
        printf("SQLNumResultCols(stmt, &colanz); Error!\n");
        exit(1);
    }

    printf("컬럼 수 : %d\n", colanz);

    /*
     * Row 수 확인.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075614455&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */
    if (SQLRowCount(stmt, &rowanz) < 0)
    {
        printf("SQLRowCount(stmt, &rowanz) Error!\n");
        exit(1);
    }
    printf("로우 수 : %ld\n", rowanz);

    /*
     * 결과 집합의 다음 행으로 커서를 진행시키고 바인드된 열을 가져온다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075605741&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */

    printf("        %36s, %20s, %20s\n", "ID", "NAME", "DEPT");
    printf("----------------------------------------------------------------------------------------\n");
    while (ret = SQLFetch(stmt) != SQL_NO_DATA)
    {
        if (ret < 0)
        {
            printf("SQLFetch(stmt) Error!\n");
            exit(1);
        }
        printf("Result: %36s, %20s, %20s\n", field1, field2, field3);
    }

    /*
     * 특정한 환경, 연결, 그리고 명령문 핸들과 관련된 자원들을 해제한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075608317&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */
    if (SQLFreeHandle(SQL_HANDLE_STMT, stmt) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_STMT, stmt) Error!\n");
        exit(1);
    }

    /*
     * 특정 연결 핸들과 관련된 연결을 종료한다.
     * http://blog.naver.com/PostView.nhn?blogId=tealeoni&logNo=120075602527&parentCategoryNo=77&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
     */
    if (SQLDisconnect(dbc) < 0)
    {
        printf("SQLDisconnect(dbc) Error!\n");
        exit(1);
    }

    if (SQLFreeHandle(SQL_HANDLE_DBC, dbc) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_DBC, dbc) Error!\n");
        exit(1);
    }

    if (SQLFreeHandle(SQL_HANDLE_ENV, env) < 0)
    {
        printf("SQLFreeHandle(SQL_HANDLE_ENV, env) Error!\n");
        exit(1);
    }

    printf("\n");
    return 0;
}