#pragma once 

#ifdef __cplusplus
extern "C"  { 
#endif 

typedef struct { 
  double      mAvg; 
  double      mMin ;
  double      mMax;
  double      m99;
  double      m999;
  double      mOps; 
} TimerResult;  


enum { 
  nanosecond, 
  microsecond,
  milisecond, 
  second, 
}; 


typedef void* TimerHandle;

int initMultiPointTimer ( TimerHandle * aTimer, int aUnit);
int freeMultiPointTimer ( TimerHandle aTimer );
int startMultiPointTimer ( TimerHandle aTimer, char * aPointName );
int endMultiPointTimer ( TimerHandle aTimer, char * aPointName);

int getResultMultiPointTimer ( TimerHandle aTimer,  
                               char *aPointName, 
                               TimerResult *aResult 
                              );


#ifdef __cplusplus
} 
#endif 
