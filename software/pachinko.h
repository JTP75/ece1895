#pragma once
#include "action.h"

class Pachinko : public Action {
    public:
        void start();
        bool is_completed();
};