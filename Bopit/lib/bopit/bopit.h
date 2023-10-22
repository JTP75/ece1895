#ifndef BOPIT_H
#define BOPIT_H

#include <time.h>

#include <power_button.h>
#include <display.h>
#include <slot_machine.h>
#include <roulette.h>
#include <pachinko.h>
#include <coin_scanner.h>

const int POWER_BUTTON_PIN = 7;

enum BopItState {
    off,
    awaiting_coin,
    slots,
    pachinko,
    roulette,
    game_over_win,
    game_over_lose
};

class BopIt {
    public:

        static const int time_limit = 10000;

        BopIt();
        BopItState get_curr_state() const;

        BopItState get_next_state();
        void update_state();
        void update_time();

        /* interfaces */
        SlotMachine slot_machine;
        Roulette roulette_machine;
        Pachinko pachinko_machine;
        CoinScanner coin_scanner;
        Display display;
        PowerButton power_button;

    private:
    
        BopItState state;
        time_t current_time;
        time_t start_time;

        void set_timer_start();
        time_t get_timer_delta() const;
        BopItState select_random_game();
};

#endif