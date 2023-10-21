#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H

#include <action.h>

class SlotMachine : public Action {
    public:
        SlotMachine();
        void start();
        bool is_completed();
};

#endif