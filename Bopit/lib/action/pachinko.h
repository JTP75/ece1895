#ifndef PACHINKO_H
#define PACHINKO_H

#include <action.h>

class Pachinko : public Action {
    public:
        static const int joystick_x_pin = A0;
        static const int joystick_y_pin = A1;
        static const int joystick_down_pin = 1;

        static const int drop_positions = 5;

        Pachinko();
        void start();
        void stop();
        bool is_completed();
        bool over() const;
        void update_joystick();
        void update_drop_pos();

    private:

        int joystick_x_pos;
        int joystick_y_pos;

        int drop_pos;
};

#endif