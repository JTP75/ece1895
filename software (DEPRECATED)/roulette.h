#pragma once
#include "action.h"

class Roulette : public Action {
    private:
        bool in_progress;
    public:
        Roulette();
        void start();
        bool is_completed();
};

#include "roulette.cpp"