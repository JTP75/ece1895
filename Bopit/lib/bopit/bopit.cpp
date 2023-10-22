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
                delay(100);
                set_timer_start();
            } else {
                next_state = off;
            }
            break;
        case awaiting_coin:
            if (coin_scanner.balance>=0.25) {
                next_state = select_random_game();
                set_timer_start();
            } else if (power_button.is_pressed()) {
                next_state = off;
                delay(100);
            } else {
                next_state = awaiting_coin;
            }
            break;
        case slots: 
            if (slot_machine.is_completed()) {
                next_state = game_over_win;
            } else if (get_timer_delta()>=time_limit) {
                next_state = game_over_lose;
            } else {
                next_state = slots;
            }
            break;
        case pachinko:
            if (slot_machine.is_completed()) {
                next_state = game_over_win;
            } else if (get_timer_delta()>=time_limit) {
                next_state = game_over_lose;
            } else {
                next_state = pachinko;
            }
            break;
        case roulette:
            if (slot_machine.is_completed()) {
                next_state = game_over_win;
            } else if (get_timer_delta()>=time_limit) {
                next_state = game_over_lose;
            } else {
                next_state = roulette;
            }
            break;
        case game_over_lose:
            delay(2000);
            next_state = awaiting_coin;
            break;
        case game_over_win:
            delay(2000);
            next_state = awaiting_coin;
            break;
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

BopItState BopIt::select_random_game() {
    switch (rand()%3) {
        case 0: 
            slot_machine.start();
            return slots;
        case 1: 
            pachinko_machine.start();
            return pachinko;
        case 2: 
            roulette_machine.start();
            return roulette;
    }
}