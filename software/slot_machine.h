#pragma once
#include "action.h"

class SlotMachine : public Action {
    private:
        bool in_progress;
    public:
        SlotMachine();
        void start();
        bool is_completed();
};

#include "slot_machine.cpp"