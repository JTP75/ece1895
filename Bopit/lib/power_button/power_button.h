#ifndef POWER_BUTTON_H
#define POWER_BUTTON_H

#include <Arduino.h>

class PowerButton {
    private:
        int pin;
    public:
        PowerButton();
        PowerButton(int pin);
        bool is_pressed() const;
};

#endif