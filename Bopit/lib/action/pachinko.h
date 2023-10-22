#ifndef PACHINKO_H
#define PACHINKO_H

#include <action.h>

class Pachinko : public Action {
    public:
        static const int joystick_x_pin = 11;
        static const int joystick_y_pin = 12;

        Pachinko();
        void start();
        void stop();
        bool is_completed();
};

#endif