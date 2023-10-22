#ifndef POWER_BUTTON_H
#define POWER_BUTTON_H

#include <Arduino.h>

class PowerButton {
    private:
    public:
        static const int pb_pin = 7;

        PowerButton();
        bool is_pressed() const;
};

#endif