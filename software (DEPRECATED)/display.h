#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#endif
#include <LiquidCrystal_I2C.h>

class Display {
    private:
        LiquidCrystal_I2C disp;
        int score;
    public:
        Display();
        void update_score();
        void load_slots_screen();
        void load_roulette_screen();
        void load_pachinko_screen();
};
#include "display.cpp"
