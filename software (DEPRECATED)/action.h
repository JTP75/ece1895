#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#endif

class Action {
    private: 
        int device;
    public:
        virtual void start() = 0;
        virtual bool is_completed() = 0;
};