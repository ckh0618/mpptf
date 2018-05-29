#pragma once

#include <ITask.hpp>
#define MAX_STRING_LEN 1024 

class SimpleSelectTask : public ITask { 

    public :
        SimpleSelectTask () ; 
        void Initialize ( int aThreadIndex ); 
        void Run (); 
        void Finalize ();
        ~SimpleSelectTask () ;

    private : 
        int mThreadIndex; 
        void setConnName ( char * aConnName);
};
