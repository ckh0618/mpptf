#pragma once

#include <ITask.hpp>
#define MAX_STRING_LEN 1024 

class SimpleInserter : public ITask { 

    public :
        SimpleInserter () ; 
        void Initialize ( int aThreadIndex , int aLoopCount); 
        void Run (int aIndex); 
        void Finalize ();
        ~SimpleInserter () ;

    private : 
        int mThreadIndex; 
        int mLoopCount ;
        void setConnName ( char * aConnName);
};
