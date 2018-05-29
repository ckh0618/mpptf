#include <MultiPointTimer.hpp>
#include <MultiPointTimer.h>
#include <string.h>


extern "C" 
{

int initMultiPointTimer ( TimerHandle * aTimer, int aUnit)
{
    timer_util::MultiPointTimer * sTimer = new timer_util::MultiPointTimer ( aUnit );
    *aTimer = sTimer; 
    return 0;
}

int freeMultiPointTimer ( TimerHandle aTimer )
{

    timer_util::MultiPointTimer* sTimer = (timer_util::MultiPointTimer*) aTimer; 
 
    delete sTimer; 
    return 0; 
}

int startMultiPointTimer ( TimerHandle aTimer, char * aPointName )
{
    timer_util::MultiPointTimer* sTimer = (timer_util::MultiPointTimer*) aTimer; 

    return sTimer->Start ( aPointName );

}
int endMultiPointTimer ( TimerHandle aTimer, char * aPointName)
{
    timer_util::MultiPointTimer* sTimer = (timer_util::MultiPointTimer*) aTimer; 
    return sTimer->End ( aPointName );
}

int getResultMultiPointTimer ( TimerHandle aTimer,  
                               char *aPointName, 
                               TimerResult* aResult  )
{
    timer_util::MultiPointTimer* sTimer = (timer_util::MultiPointTimer*) aTimer; 
    timer_util::TimerResult sResult ; 
    sTimer->GetResult ( aPointName, sResult);
    memcpy ( aResult, &sResult, sizeof ( TimerResult));
    return 0;
}


 
}
