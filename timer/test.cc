
#include <MultiPointTimer.hpp>
#include <stdio.h>
#include <unistd.h>


int main ()
{

  timer_util::MultiPointTimer sTimer( timer_util::microsecond ) ; 
  timer_util::TimerResult sResult ;

  for ( int i=0; i< 100000 ; ++i ) 
  { 
    sTimer.Start ("BC");
    i++;
    sTimer.End ("BC");
  } 

  sTimer.GetResult ( "BC" , sResult ) ;

  printf ( "[%20s]  : [%10lf] \n", "MIN", sResult.mMin ) ;
  printf ( "[%20s]  : [%10lf] \n", "AVG", sResult.mAvg ) ;
  printf ( "[%20s]  : [%10lf] \n", "MAX", sResult.mMax ) ;
  printf ( "[%20s]  : [%10lf] \n", "99%", sResult.m99 ) ;
  printf ( "[%20s]  : [%10lf] \n", "99.9%", sResult.m999 ) ;
  printf ( "[%20s]  : [%10lf] \n", "Ops", sResult.mOps ) ;

 return 0 ;
}
