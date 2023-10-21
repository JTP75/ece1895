#include <bopit.h>

BopIt::BopIt() {
    slot_machine = SlotMachine();
    roulette_machine = Roulette();
    pachinko_machine = Pachinko();
    coin_scanner = CoinScanner();
    display = Display();
    power_button = PowerButton(POWER_BUTTON_PIN);

    state = off;
}

BopItState BopIt::get_curr_state() const {
    return state;
}

BopItState BopIt::get_next_state() {

    update_time();
    
    BopItState next_state;
    switch (this->state) {
        case off:
            if (power_button.is_pressed()) {
                next_state = awaiting_coin;
                set_timer_start();
            } else {
                next_state = off;
            }
            break;
        case awaiting_coin:
            if (get_timer_delta() < 2000)
                next_state = awaiting_coin;
            else
                next_state = off;
            break;
        case slots:
            next_state = off;
        case pachinko:
            next_state = off;
        case roulette:
            next_state = off;
        case game_over_lose:
            next_state = off;
        case game_over_win:
            next_state = off;
    }
    return next_state;
}

void BopIt::update_state() {
    state = get_next_state();
}

void BopIt::update_time() {
    current_time = millis();
}

void BopIt::set_timer_start() {
    start_time = current_time;
}

time_t BopIt::get_timer_delta() const {
    return current_time-start_time;
}