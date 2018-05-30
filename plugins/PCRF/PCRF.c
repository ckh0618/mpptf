#include <PCRF.hpp>
#include <ITask.h>


int New  (ObjectHandle *aHandle ) 
{
    PCRF *sHandle = new PCRF () ;
    *aHandle = sHandle; 
    return 0 ;
}

int Init (ObjectHandle aHandle, int aThreadNo , int aLoopCount) 
{

    PCRF *sHandle = (PCRF*)aHandle; 
    sHandle->Initialize (aThreadNo, aLoopCount) ;
    return 0;

}

int Run  (ObjectHandle aHandle, int aLoop ) 
{
    PCRF *sHandle = (PCRF*)aHandle; 
    sHandle->Run(aLoop);

    return 0 ; 
}

int Finalize ( ObjectHandle aHandle)
{
    PCRF *sHandle = (PCRF*)aHandle; 
    sHandle->Finalize();

    return 0;

}
