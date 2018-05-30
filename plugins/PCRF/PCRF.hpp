#pragma once

#include <ITask.hpp>
#include <map> 

const static int MAX_STRING_LEN=1024;
const static int TOTAL_GROUP_COUNT = 2 ;



class PCRF : public ITask { 

    public :
        PCRF () ; 
        void Initialize ( int aThreadIndex , int aLoopCount); 
        void Run (int aIndex); 
        void Finalize ();
        ~PCRF () ;

    private : 
        int mThreadIndex; 
        int mLoopCount ;
        void setConnName ( char * aConnName, int aGroupNo);


        int mGroupCount ; 

        

        
};
