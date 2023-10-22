#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H

#include <action.h>

class SlotMachine : public Action {
    public:
        static const int lever_pin = 9;

        SlotMachine();
        void start();
        void stop();
        bool is_completed();
};

#endif