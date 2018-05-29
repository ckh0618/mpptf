#include <SimpleInserter.hpp>
#include <ITask.h>


int New  (ObjectHandle *aHandle ) 
{
    SimpleInserter *sHandle = new SimpleInserter () ;
    *aHandle = sHandle; 
    return 0 ;
}

int Init (ObjectHandle aHandle, int aThreadNo , int aLoopCount) 
{

    SimpleInserter *sHandle = (SimpleInserter*)aHandle; 
    sHandle->Initialize (aThreadNo, aLoopCount) ;
    return 0;

}

int Run  (ObjectHandle aHandle, int aLoop ) 
{
    SimpleInserter *sHandle = (SimpleInserter*)aHandle; 
    sHandle->Run(aLoop);

    return 0 ; 
}

int Finalize ( ObjectHandle aHandle)
{
    SimpleInserter *sHandle = (SimpleInserter*)aHandle; 
    sHandle->Finalize();

    return 0;

}
