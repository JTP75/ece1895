#pragma once
#include "Arduino.h"

class SlotMachineBopIt {
  public:
    SlotMachineBopIt(int pin);
    bool coinVerifier(int pin);
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
};

#include "slotmachinebopit.c"