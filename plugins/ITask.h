#pragma once

typedef void * ObjectHandle ; 

#ifdef __cplusplus
extern "C"  {
#endif

int New  (ObjectHandle *aHandle ) ;
int Init (ObjectHandle aHandle , int aThreadNo , int aLoopCount);
int Run  (ObjectHandle aHandle, int aIndex ) ;
int Finalize ( ObjectHandle aHandle);

#ifdef __cplusplus
}
#endif

