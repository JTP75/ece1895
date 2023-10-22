#ifndef ROULETTE_H
#define ROULETTE_H

#include <action.h>

class Roulette : public Action {
    public:
        static const int spin_pin = 10;

        Roulette();
        void start();
        void stop();
        bool is_completed();
};

#endif