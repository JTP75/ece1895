#ifndef POWER_BUTTON_H
#define POWER_BUTTON_H

#include <Arduino.h>

class PowerButton {
    private:
    public:
        static const int pin = 2;

        PowerButton();
        bool is_pressed() const;
};

#endif