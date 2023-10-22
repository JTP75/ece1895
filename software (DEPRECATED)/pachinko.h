#pragma once
#include "action.h"

class Pachinko : public Action {
    private:
        bool in_progress;
    public:
        Pachinko();
        void start();
        bool is_completed();
};