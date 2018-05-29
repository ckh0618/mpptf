#include <MultiPointTimer.hpp>
#include <algorithm>
#include <numeric>



namespace timer_util 
{

MultiPointTimer :: MultiPointTimer (int aUnit) 
{
  mUnit = 1; 
  switch (aUnit ) 
  {
    case nanosecond : 
      mUnit = 1;
      break; 
    case microsecond : 
      mUnit = 1000;
      break; 
    case milisecond : 
      mUnit = 1000000;
      break;
    case second : 
      mUnit = 1000000 * 1000 ; 
      break;
  };

}

MultiPointTimer :: ~MultiPointTimer () {}



int MultiPointTimer :: Start  ( const std::string& aName ) 
{

  timespec  sTimeSpec; 
  clock_gettime ( CLOCK_MONOTONIC_RAW, &sTimeSpec ) ;
  mOldValue [ aName ] = sTimeSpec; 

  return 0 ;
}


int MultiPointTimer :: End ( const std::string& aName ) 
{

  timespec sTimeSpec; 
  clock_gettime ( CLOCK_MONOTONIC_RAW, &sTimeSpec ) ;
  long_vector_t  sVector; 
  double         sDiff; 

  // get time difference 

  if ( mOldValue.find ( aName ) == mOldValue.end ()) 
  {
    return -1; 
  }

  if ( mValue.find ( aName ) == mValue.end()) 
  {
    mValue[aName] = sVector; 
  }


  sDiff = ( sTimeSpec.tv_sec - mOldValue[aName].tv_sec ) * 1000000000 + 
          ( sTimeSpec.tv_nsec - mOldValue[aName].tv_nsec );

  sDiff = sDiff / mUnit; 
  mValue[aName].push_back ( std::move(sDiff) ) ;
  return 0;
}

int MultiPointTimer :: GetResult ( const std::string& aName, 
                                   TimerResult& aResult ) 
{
  auto& sResultVector = mValue[aName] ; 
  double sSum = 0 ; 
  int sP99_idx = 0 , sP999_idx = 0 ;


  std::sort (sResultVector.begin(), sResultVector.end());
  sSum = std::accumulate ( sResultVector.begin(), sResultVector.end(), 0.000);

  sP99_idx = sResultVector.size()-((sResultVector.size() /100) + 1) ;
  sP999_idx = sResultVector.size()-((sResultVector.size() /1000) + 1) ;


  sP99_idx=sP99_idx >= 0?sP99_idx:0;
  sP999_idx=sP99_idx >= 0?sP999_idx:0;
  

  aResult.mAvg = sSum / sResultVector.size()  ; 
  aResult.mMin = sResultVector.front();
  aResult.mMax = sResultVector.back() ;

  aResult.m99 = sP99_idx==0?0.00:sResultVector[sP99_idx];
  aResult.m999 = sP999_idx==0?0.00:sResultVector[sP999_idx];

  aResult.mOps = (sResultVector.size() / sSum) *  (1000000000 / mUnit)  ;
  
  return 0; 

}



}


