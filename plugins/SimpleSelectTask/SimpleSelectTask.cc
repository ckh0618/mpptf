/***********************************************
 * This code is inserted automatically by gpec
 ***********************************************/
#include <goldilocksesql.h>
typedef struct {
  int mCharMap;
} zlpOption;
static zlpOption gZlpOption = {1};
/***********************************************
 * End of gpec automatic inclusion
 ***********************************************/


#line __LINE__ "SimpleSelectTask.cc"
#include <SimpleSelectTask.hpp>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <cassert>


SimpleSelectTask  :: SimpleSelectTask () { }

/* EXEC SQL INCLUDE SQLCA; */
#include "sqlca.h"
#line 10 "SimpleSelectTask.gc"



void SimpleSelectTask :: Initialize (int aThreadIndex) 
{
    /* EXEC SQL BEGIN DECLARE SECTION ; */
#line 15 "SimpleSelectTask.gc"
 
    char sUserName [MAX_STRING_LEN] ;
    char sPassword [MAX_STRING_LEN] ; 
    char sDSN [MAX_STRING_LEN] ; 
    char sConnName [ MAX_STRING_LEN ];
    /* EXEC SQL END   DECLARE SECTION ; */
#line 20 "SimpleSelectTask.gc"
 

    mThreadIndex = aThreadIndex ;


    std::strncpy ( sUserName , "test" , MAX_STRING_LEN );
    std::strncpy ( sPassword , "test" , MAX_STRING_LEN );
    std::strncpy ( sDSN , "DSN=GOLDILOCKS", MAX_STRING_LEN);

    setConnName ( sConnName ) ;

    /* EXEC SQL AT :sConnName CONNECT :sUserName IDENTIFIED BY :sPassword USING :sDSN */
{
    sqlargs_t sqlargs;
#line 56 "SimpleSelectTask.cc"
    sqlargs.sqltype    = 0;
    sqlargs.sql_ca     = NULL;
    sqlargs.conn       = NULL;
    sqlargs.sql_state  = NULL;
    sqlargs.sqlstmt    = NULL;
    sqlargs.sqlfn      = NULL;
    sqlargs.sqlln      = 0;
    sqlargs.sqlcursor  = NULL;
    sqlargs.sqlfetch   = NULL;
    sqlargs.hvc        = 0;
    sqlargs.sqlhv      = NULL;
    sqlargs.dynusing   = NULL;
    sqlargs.dyninto    = NULL;
    sqlargs.option     = (void *)&gZlpOption;
    sqlargs.conn = (char *)sConnName;
    sqlargs.sql_ca = &sqlca;
    sqlargs.sql_state = SQLSTATE;
    sqlargs.sqltype = 35;
    sqlargs.sqlfn = (char *)__FILE__;
    sqlargs.sqlln = __LINE__;
    sqlargs.sqlstmt = NULL;
    sqlargs.atomic = 0;
    sqlargs.unsafenull = 0;
    sqlargs.iters = 0;
    DBESQL_Connect(NULL, &sqlargs, sDSN, sUserName, sPassword);
}
#line 31 "SimpleSelectTask.gc"
 
    if ( sqlca.sqlcode ) {
        std::printf("Fail to connect : [%s]\n" , sqlca.sqlerrm.sqlerrmc );
    }
}

void SimpleSelectTask :: Run () 
{
    struct sqlca sqlca; 
    /* EXEC SQL BEGIN DECLARE SECTION ; */
#line 40 "SimpleSelectTask.gc"
 
    int   sValue; 
    char sConnName [ MAX_STRING_LEN ];
    /* EXEC SQL END   DECLARE SECTION ; */
#line 43 "SimpleSelectTask.gc"
 

    setConnName ( sConnName ) ;
    
    /* EXEC SQL AT :sConnName SELECT 1 into :sValue FROM DUAL  */
{
    sqlargs_t sqlargs;
#line 107 "SimpleSelectTask.cc"
    sqlargs.sqltype    = 0;
    sqlargs.sql_ca     = NULL;
    sqlargs.conn       = NULL;
    sqlargs.sql_state  = NULL;
    sqlargs.sqlstmt    = NULL;
    sqlargs.sqlfn      = NULL;
    sqlargs.sqlln      = 0;
    sqlargs.sqlcursor  = NULL;
    sqlargs.sqlfetch   = NULL;
    sqlargs.hvc        = 0;
    sqlargs.sqlhv      = NULL;
    sqlargs.dynusing   = NULL;
    sqlargs.dyninto    = NULL;
    sqlargs.option     = (void *)&gZlpOption;
    sqlargs.conn = (char *)sConnName;
    sqlargs.sql_ca = &sqlca;
    sqlargs.sql_state = SQLSTATE;
    sqlargs.sqltype = 2;
    sqlargs.sqlfn = (char *)__FILE__;
    sqlargs.sqlln = __LINE__;
    sqlargs.sqlstmt = (char *)"SELECT 1 into :sValue FROM DUAL \n"
;
    sqlargs.atomic = 0;
    sqlargs.unsafenull = 0;
    sqlargs.iters = 0;
    sqlhv_t sqlhv[1];
    sqlargs.sqlhv = sqlhv;
    sqlargs.hvc = 1;
    sqlhv[0].io_type = 1;
    sqlhv[0].data_type = 5;
    sqlhv[0].arr_size = 0;
    sqlhv[0].buflen = sizeof(sValue);
    sqlhv[0].precision = 0;
    sqlhv[0].scale = 0;
    sqlhv[0].el_size = sizeof(sValue);
    sqlhv[0].value = (void *)&sValue;
    sqlhv[0].ind_type = -1;
    sqlhv[0].ind_el_size = 0;
    sqlhv[0].indicator = NULL;
    sqlhv[0].ptr_size = -1;
    DBESQL_Execute(NULL, &sqlargs);
}
#line 47 "SimpleSelectTask.gc"

    if ( sqlca.sqlcode ) {
        std::printf("EXEC ERROR : [%s] [%s]\n" , sqlca.sqlerrm.sqlerrmc, sConnName );
        assert ( 0 );
    }
  
}

void SimpleSelectTask :: Finalize () 
{
    struct sqlca sqlca; 

    /* EXEC SQL BEGIN DECLARE SECTION ; */
#line 59 "SimpleSelectTask.gc"
 
    char sConnName [ MAX_STRING_LEN ];
    /* EXEC SQL END   DECLARE SECTION ; */
#line 61 "SimpleSelectTask.gc"
 

    setConnName ( sConnName ) ;

    /* EXEC SQL AT :sConnName DISCONNECT  */
{
    sqlargs_t sqlargs;
#line 176 "SimpleSelectTask.cc"
    sqlargs.sqltype    = 0;
    sqlargs.sql_ca     = NULL;
    sqlargs.conn       = NULL;
    sqlargs.sql_state  = NULL;
    sqlargs.sqlstmt    = NULL;
    sqlargs.sqlfn      = NULL;
    sqlargs.sqlln      = 0;
    sqlargs.sqlcursor  = NULL;
    sqlargs.sqlfetch   = NULL;
    sqlargs.hvc        = 0;
    sqlargs.sqlhv      = NULL;
    sqlargs.dynusing   = NULL;
    sqlargs.dyninto    = NULL;
    sqlargs.option     = (void *)&gZlpOption;
    sqlargs.conn = (char *)sConnName;
    sqlargs.sql_ca = &sqlca;
    sqlargs.sql_state = SQLSTATE;
    sqlargs.sqltype = 35;
    sqlargs.sqlfn = (char *)__FILE__;
    sqlargs.sqlln = __LINE__;
    sqlargs.sqlstmt = NULL;
    sqlargs.atomic = 0;
    sqlargs.unsafenull = 0;
    sqlargs.iters = 0;
    DBESQL_Disconnect(NULL, &sqlargs, NULL, 0);
}
#line 65 "SimpleSelectTask.gc"

    if ( sqlca.sqlcode ) {
        std::printf("EXEC ERROR : [%s] [%s]\n" , sqlca.sqlerrm.sqlerrmc, sConnName );
        assert ( 0 );
    }
}


void SimpleSelectTask :: setConnName ( char * aConnName)
{
    sprintf ( aConnName, "CONN_%d", mThreadIndex);
}
