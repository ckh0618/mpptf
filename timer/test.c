#include <MultiPointTimer.h>
#include <stdio.h>
#include <unistd.h>


int main ()
{
    int sRC = 0 ; 
    int i = 0;

    TimerHandle sHandle; 
    TimerResult sResult ; 


    sRC = initMultiPointTimer ( &sHandle, microsecond);

    for ( i=0; i< 100000 ; ++i ) 
    { 
        sRC = startMultiPointTimer ( sHandle , "BC");
        i++;
        sRC = endMultiPointTimer ( sHandle, "BC");
    
    } 

    sRC = getResultMultiPointTimer ( sHandle, "BC", &sResult);

    sRC = freeMultiPointTimer ( sHandle );

    printf ( "[%20s]  : [%10lf] \n", "MIN", sResult.mMin ) ;
    printf ( "[%20s]  : [%10lf] \n", "AVG", sResult.mAvg ) ;
    printf ( "[%20s]  : [%10lf] \n", "MAX", sResult.mMax ) ;
    printf ( "[%20s]  : [%10lf] \n", "99%", sResult.m99 ) ;
    printf ( "[%20s]  : [%10lf] \n", "99.9%", sResult.m999 ) ;
    printf ( "[%20s]  : [%10lf] \n", "Ops", sResult.mOps ) ;


    return 0 ;

}
