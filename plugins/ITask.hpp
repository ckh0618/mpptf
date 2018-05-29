#pragma once 

class ITask {
    public :
        virtual void Initialize ( int aThreadIndex )  = 0; 
        virtual void Run () = 0; 
        virtual void Finalize () = 0 ;
};
