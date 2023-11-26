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
    void move_pachinko_ball(bool left);
    void set_pball_pos(const uint8_t &x, const uint8_t &y);
    void drop_pachinko_ball(bool win);

    void set_state(const BopItState &s);
    const BopItState &get_curr_state() const;

    Display disp;

  private:
    BopItState state;
    unsigned long current_time;
    unsigned long start_time;
    uint8_t pachinko_ball_x;
    uint8_t pachinko_ball_y;
};

#endif
