#pragma once

class SlotMachineBopIt {
    public:
        SlotMachineBopIt(int pin);
        bool verify_coin_input(int pin);
        void actions(int);
        void slots();
        void roulette();
        void pachinko();
        int getScore();
        void setScore();
        bool getGameState();

    private:
        bool game_start;
        int lever_pin;
        int wheel_pin;
        int joystick_pin;
        int score;
};

#include "slot_machine.cpp";