#ifndef ROULETTE_H
#define ROULETTE_H

#include <action.h>

class Roulette : public Action {
    public:
        Roulette();
        void start();
        bool is_completed();
};

#endif