#pragma once 

class ITask {
    public :
        virtual void Initialize ( int aThreadIndex, int aLoopCount )  = 0; 
        virtual void Run (int aIndex) = 0; 
        virtual void Finalize () = 0 ;
};
