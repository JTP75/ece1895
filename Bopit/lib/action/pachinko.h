#ifndef PACHINKO_H
#define PACHINKO_H

#include <action.h>

class Pachinko : public Action {
    public:
        Pachinko();
        void start();
        bool is_completed();
};

#endif