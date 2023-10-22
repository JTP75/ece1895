#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Display {
    private:
        LiquidCrystal_I2C disp;
        int score;
    public:
        Display();
        void update_score(int);
        void start_screen();
        void win_display();
        void lose_display();
        void load_slots_screen();
        void load_roulette_screen();
        void load_pachinko_screen();
};

#endif