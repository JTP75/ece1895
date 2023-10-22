#ifndef ACTION_H
#define ACTION_H

#include <Arduino.h>

class Action {
    private:
    public:
        bool in_progress;
        
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual bool is_completed() = 0;
};

#endif