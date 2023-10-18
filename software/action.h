#pragma once

class Action {
    private: 
        int device;
    public:
        virtual void start() = 0;
        virtual bool is_completed() = 0;
};