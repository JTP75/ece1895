#ifndef SlotMachineBopIt_h
#define SlotMachineBopIt_h

#include "Arduino.h"
#include "Display.h"

class SlotMachineBopIt {
  public:
    SlotMachineBopIt();
    bool coinVerifier(int pin);
    void action();
    void slots();
    void roulette();
    void pachinko();
    bool getGameState();
    void setGameState();

  private:
    bool game_start;
    int lever_pin;
    int roulette_pin;
    int coin_verifier_pin;
    int joystick_pinX;
    int joystick_pinY;
    Display screen;
};
#endif
