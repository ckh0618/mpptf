#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <time.h>

namespace timer_util 
{ 

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

class MultiPointTimer   
{
  typedef std::vector<double> long_vector_t; 
  typedef struct timespec timespec;

 public :  
  MultiPointTimer (int aUnit) ;
  virtual ~MultiPointTimer ();

  int Start ( const std::string& aName ) ;
  int End   ( const std::string& aName ) ;


  int GetResult ( const std::string& aName, 
                  TimerResult& aResult ) ; 

 private :
  std::unordered_map <std::string,timespec>      mOldValue;
  std::unordered_map <std::string,long_vector_t> mValue; 

  long mUnit;
}; 

}
