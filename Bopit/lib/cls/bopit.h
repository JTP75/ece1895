#ifndef BOPIT_H
#define BOPIT_H

#include <display.h>
#include <slotmachine.h>

enum BopItState {
    await,
    slots,
    pachinko,
    roulette,
    win,
    lose    
};

class BopIt {
  public:
    BopIt();
    ~BopIt();

    void start_slots();
    void spin_slots(bool win);

    void start_roulette();
    void spin_roulette(bool win);

    void start_pachinko();

    void set_state(const BopItState &s);
    const BopItState &get_curr_state() const;

    Display disp;

  private:
    BopItState state;
    unsigned long current_time;
    unsigned long start_time;
};

#endif
