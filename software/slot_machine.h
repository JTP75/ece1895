#pragma once
#include "action.h"

class SlotMachine : public Action {
    public:
        void start();
        bool is_completed();
};