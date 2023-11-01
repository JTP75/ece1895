#ifndef BopIt_h
#define BopIt_h

#include "Display.h"

enum BopItState {
    off,
    awaiting_coin,
    wait,
    start,
    success,
    fail,
    slots,
    pachinko,
    roulette,
    game_over
};

class BopIt {
  public:
    BopIt();
    ~BopIt();
    void slots_game();
    void roulette_game();
    void pachinko_game();
    void set_state(BopItState);
    BopItState action();
    BopItState get_curr_state() const;

  private:
    BopItState state;
    Display *disp;
    unsigned long timer1;
    unsigned long timeBegin;
};
#endif