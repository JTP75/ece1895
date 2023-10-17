#ifndef SlotMachineBopIt_h
#define SlotMachineBopIt_h
#include "Arduino.h"
class SlotMachineBopIt {
  public:
    SlotMachineBopIt();
    bool coinVerifier(int pin);
    void action();
    void slots();
    void roulette();
    void pachinko();
    int getScore();
    void setScore();
    bool getGameState();
    void setGameState();
    

  private:
    bool game_start;
    int score;
    int lever_pin;
    int wheel_pin;
    int joystick_pin;
};
#endif
