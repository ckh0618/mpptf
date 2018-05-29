#pragma once

#ifdef __cplusplus
extern "C"  {
#endif

typedef void * ObjectHandle ; 

int New  (ObjectHandle *aHandle ) ;
int Init (ObjectHandle aHandle , int aThreadNo);
int Run  (ObjectHandle aHandle ) ;
int Finalize ( ObjectHandle aHandle);

#ifdef __cplusplus
}
#endif

