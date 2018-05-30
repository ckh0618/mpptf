#pragma once
#include <ITask.hpp>
#define MAX_STRING_LEN 1024 

class SimpleSelectTask : public ITask { 

    public :
        SimpleSelectTask () ; 
        void Initialize ( int aThreadIndex, int aLoopCounter ); 
        void Run (int aIndex); 
        void Finalize ();
        ~SimpleSelectTask () ;

    private : 
        int mThreadIndex; 
        int mLoopCount ;
        void setConnName ( char * aConnName);
};
