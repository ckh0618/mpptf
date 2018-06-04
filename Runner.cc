#include <iostream>
#include <cassert>
#include <string>
#include <unistd.h>
#include <thread> 
#include <string.h>
#include <dlfcn.h>
#include <functional>
#include <MultiPointTimer.hpp>

#define MAX_FILE_NAME_LEN 1024 
#define MAX_THREAD_COUNT 1024 

typedef int ( *NewFuncType )(void *) ;
typedef int ( *InitFuncType )(void *, int, int  ) ;
typedef int ( *RunFuncType )(void *, int) ;
typedef int ( *FinalizeFuncType )(void *) ;


typedef struct { 
    int  mTotalThreadCount; 
    char mLibraryFullPath [MAX_FILE_NAME_LEN];
    int  mCheck ; 
    long mLoopCount; 

    // Function Pointers 
    NewFuncType mNewFunction ; 
    InitFuncType mInitFunction ; 
    RunFuncType  mRunFunction ;
    FinalizeFuncType mFinalizeFunction ;

    // Object Handle 

    void * mHandle [ MAX_THREAD_COUNT ];
    timer_util::MultiPointTimer * mTimer [ MAX_THREAD_COUNT ] ;

} CommandLineArgument;

static  void PrintHelpMessage ( int argc, char **argv ) 
{
    std::printf("Got long argc[%d]\n", argc);
    std::printf ("Usage : %s -t [TotalThreadCount] -l [LibraryFilePath] -c [LoopCount]\n", argv[0]);
    std::printf ("Example : %s -t 10 -l ./plugin/libSelect.so -c 10000\n", argv[0]);
}

static  int ParseCommandLine ( int argc, char **argv, CommandLineArgument& aCommandLine)
{
    int sOpt; 

    while ((sOpt = getopt ( argc, argv, "t:l:c:")) != -1 ) 
    {
        switch ( sOpt )
        {
            case 't' : 
                aCommandLine.mTotalThreadCount = atoi ( optarg );
                aCommandLine.mCheck++; 
            break;

            case 'l' : 
                strncpy ( aCommandLine.mLibraryFullPath, optarg, MAX_FILE_NAME_LEN ) ;
                aCommandLine.mCheck++; 
            break; 

            case 'c' :
                aCommandLine.mLoopCount = atoi ( optarg );
                aCommandLine.mCheck ++ ;
        }
    }

    if ( aCommandLine.mCheck != 3 ) 
    { 
        PrintHelpMessage ( argc, argv );
        exit( EXIT_FAILURE);
    }
    return 0 ;
}

static  int LoadPlugin (CommandLineArgument& aCommandLine) 
{
    void * sLibraryHandle; 
    char * sError; 

 
    sLibraryHandle = dlopen ( aCommandLine.mLibraryFullPath, RTLD_LAZY );
    sError = dlerror() ;
    if ( sError != NULL ) { 
        printf("ERROR : %s \n", sError);
        exit ( EXIT_FAILURE );
    }

    NewFuncType sNewFunction  = (NewFuncType)dlsym ( sLibraryHandle, "New");

    sError = dlerror() ;
    if ( sError != NULL ) { 
        printf("ERROR : %s \n", sError);
        exit ( EXIT_FAILURE );
    }


    InitFuncType sInitFunction  = (InitFuncType)dlsym ( sLibraryHandle, "Init");

    sError = dlerror() ;
    if ( sError != NULL ) { 
        printf("ERROR : %s \n", sError);
        exit ( EXIT_FAILURE );
    }


    RunFuncType sRunFunction  = (RunFuncType)dlsym ( sLibraryHandle, "Run");

    sError = dlerror() ;
    if ( sError != NULL ) { 
        printf("ERROR : %s \n", sError);
        exit ( EXIT_FAILURE );
    }


    FinalizeFuncType sFinalizeFunction  = (FinalizeFuncType)dlsym ( sLibraryHandle, "Finalize");

    sError = dlerror() ;
    if ( sError != NULL ) { 
        printf("ERROR : %s \n", sError);
        exit ( EXIT_FAILURE );
    }

    aCommandLine.mInitFunction = sInitFunction ;
    aCommandLine.mNewFunction = sNewFunction ;
    aCommandLine.mRunFunction = sRunFunction ;
    aCommandLine.mFinalizeFunction = sFinalizeFunction;

    return 0;
}

static int ThreadFunction ( const CommandLineArgument& aCommandLine, int aThreadIndex) 
{
    int sRC;

    void * sHandle = aCommandLine.mHandle[aThreadIndex];

    for ( int i = 0 ; i < aCommandLine.mLoopCount ; ++i )
    {
        aCommandLine.mTimer[aThreadIndex]->Start("RUN");
        sRC = (*aCommandLine.mRunFunction)(sHandle, i);
        aCommandLine.mTimer[aThreadIndex]->End("RUN");
        assert ( sRC == 0 );
    }

    sRC = (*aCommandLine.mFinalizeFunction)(sHandle);
    assert ( sRC == 0 );

    return 0 ;
}


static int CreateThread (const CommandLineArgument& aCommandLine)
{
    std::thread* sThread[MAX_THREAD_COUNT];


    for ( int i = 0 ; i < aCommandLine.mTotalThreadCount ; ++i ) 
    {
        sThread[i] = new std::thread ( std::bind ( ThreadFunction , aCommandLine, i ));
    }

    for ( int i = 0 ; i < aCommandLine.mTotalThreadCount ; ++i ) 
    {
        sThread[i]->join ();
    }

    for ( int i = 0 ; i < aCommandLine.mTotalThreadCount ; ++i ) 
    {
        delete sThread[i] ; 
    }
    return 0;

}

static int PrepareHandle (CommandLineArgument& aCommandLine) 
{
    int sRC; 

    for (int i = 0 ; i < aCommandLine.mTotalThreadCount ; ++i )
    {
        sRC = (*aCommandLine.mNewFunction)(&aCommandLine.mHandle[i]);
        assert ( sRC == 0 );
        sRC = (*aCommandLine.mInitFunction)(aCommandLine.mHandle[i], i, aCommandLine.mLoopCount);
        assert ( sRC == 0 );

        aCommandLine.mTimer[i] = new timer_util::MultiPointTimer ( timer_util::microsecond );
    }

    return 0;
}

static int PrintResult (CommandLineArgument& aCommandLine )
{
    timer_util::TimerResult sResult ;
    double  sTotalOps = 0.0;

    for ( int i = 0 ; i < aCommandLine.mTotalThreadCount ; ++i ) 
    {
        aCommandLine.mTimer[i]->GetResult ( "RUN", sResult );
        std::printf("Thread[%5d] MinLat[%9.2lf] AvgLat[%9.2f] MaxLat[%9.2lf] 99 Pct[%9.2lf] 99.9 Pct[%9.2lf] Ops[%9.2lf]\n", 
                    i, sResult.mMin, sResult.mAvg, sResult.mMax, sResult.m99, sResult.m999, sResult.mOps);
        sTotalOps+=sResult.mOps; 
        delete aCommandLine.mTimer[i] ; 
        aCommandLine.mTimer[i] = NULL ;
    }
    std::printf("------------------------------------------------------------------------------------------------------------------------\n");
    std::printf("                                                                                                    Total Ops[%9.2lf]\n", 
                sTotalOps ) ;
       
    return 0;
}

int main (int argc, char **argv ) 
{
    CommandLineArgument sCommandLine; 
    memset (&sCommandLine, 0x00, sizeof(CommandLineArgument));
    ParseCommandLine ( argc, argv, sCommandLine ) ;
    LoadPlugin (sCommandLine);
    PrepareHandle ( sCommandLine );
    CreateThread ( sCommandLine);

    PrintResult ( sCommandLine ) ;
}


