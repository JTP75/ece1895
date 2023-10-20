#pragma once
#include "action.h"

class Roulette : public Action {
    public:
        void start();
        bool is_completed();
};