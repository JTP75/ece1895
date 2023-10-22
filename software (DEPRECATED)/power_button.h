#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#endif

class PowerButton {
    private:
        int pin;
    public:
        PowerButton(int pin);
        bool is_pressed();
};