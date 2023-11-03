#ifndef Slotmachine_H
#define Slotmachine_H

#include "Arduino.h"

class Slotmachine {
  private:
    String reels[7];
     

  public:
    Slotmachine();
    ~Slotmachine();
    String spin();
    String get_reels(int);
};
#endif
