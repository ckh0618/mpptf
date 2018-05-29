#include <SimpleSelectTask.hpp>
#include <ITask.h>


int New  (ObjectHandle *aHandle ) 
{
    SimpleSelectTask *sHandle = new SimpleSelectTask () ;
    *aHandle = sHandle; 
    return 0 ;
}

int Init (ObjectHandle aHandle, int aThreadNo ) 
{

    SimpleSelectTask *sHandle = (SimpleSelectTask*)aHandle; 
    sHandle->Initialize (aThreadNo) ;
    return 0;

}

int Run  (ObjectHandle aHandle ) 
{
    SimpleSelectTask *sHandle = (SimpleSelectTask*)aHandle; 
    sHandle->Run();

    return 0 ; 
}

int Finalize ( ObjectHandle aHandle)
{
    SimpleSelectTask *sHandle = (SimpleSelectTask*)aHandle; 
    sHandle->Finalize();

    return 0;

}
