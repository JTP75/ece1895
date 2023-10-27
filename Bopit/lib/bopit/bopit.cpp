#include <bopit.h>

/**
 * @brief   toplevel bopit class ctor
 * @returns bopit instance
*/
BopIt::BopIt() {
    slot_machine = SlotMachine();
    roulette_machine = Roulette();
    pachinko_machine = Pachinko();
    coin_scanner = CoinScanner();
    display = Display();
    power_button = PowerButton();

    state = off;

    srand(micros());
}

/**
 * @brief   gets current device state
 * @returns bopit state enum for current state
*/
BopItState BopIt::get_curr_state() const {
    return state;
}

/**
 * @brief handler for power button interrupt (called by wrapper in main)
 * 
 */
void BopIt::power_button_pressed() {
    if (state==off) {
        state = awaiting_coin;
    } else {
        state = off;
    }
    do_state_change_action();
}

/**
 * @brief   updates internal clock and performs state machine logic
 * @returns next state enum based on current state and internal logic
 * 
 * @note    called every main loop iteration
*/
void BopIt::next_state_logic() { 
    switch (this->state) {
        case off:
        break; case awaiting_coin:
            if (coin_scanner.balance>=0.25 || get_timer()>1000) {
                state = select_random_game();
            }
        break; case slots: 
            if (slot_machine.over()) {
                state = game_over_win;
            } else if (get_timer()>=time_limit) {
                state = game_over_lose;
            }
        break; case pachinko:
            if (pachinko_machine.over()) {
                state = game_over_win;
            } else if (get_timer()>=time_limit) {
                state = game_over_lose;
            }
        break; case roulette:
            if (roulette_machine.over()) {
                state = game_over_win;
            } else if (get_timer()>=time_limit) {
                state = game_over_lose;
            }
        break; case game_over_lose:
            if (get_timer() >= 2000) {
                state = awaiting_coin;
            }
        break; case game_over_win:
            if (get_timer() >= 2000) {
                state = awaiting_coin;
            }
        break;
    }
}

/**
 * @brief   performs functions for each state
 * 
 * @note    called every main loop iteration
 */
void BopIt::do_state_action() {
    switch (this->state) {
        case off:
        break; case awaiting_coin:
        break; case slots: 
        break; case pachinko:
        break; case roulette:
        break; case game_over_lose:
        break; case game_over_win:
        break;
    }
}

/**
 * @brief   performs functions for each state
 * 
 * @note    called ONCE per state change
 * @todo    double-check that ^^
 */
void BopIt::do_state_change_action() {
    switch (this->state) {
        case off:
            Serial.write("off\n");
        break; case awaiting_coin:
            Serial.write("await coin\n");
            start_timer();
        break; case slots: 
            Serial.write("slots\n");
            start_timer();
        break; case pachinko:
            Serial.write("pachinko\n");
            start_timer();
        break; case roulette:
            Serial.write("roulette\n");
            start_timer();
        break; case game_over_lose:
            Serial.write("loser\n");
            start_timer();
        break; case game_over_win:
            Serial.write("winner\n");
            start_timer();
        break;
    }
}

/**
 * @brief   updates the current state by calling get_next_state()
 * @post    game cycles to next state
*/
void BopIt::update_state() {
    update_time();
    BopItState prev_state = state;
    next_state_logic();
    if (prev_state != state) {
        do_state_change_action();
    }
    do_state_action();
}

/**
 * @brief   updates internal time value (in ms) use arduino millis() function
*/
void BopIt::update_time() {
    current_time = millis();
}

/**
 * @brief   sets internal timer start time to current time
*/
void BopIt::start_timer() {
    start_time = current_time;
}

/**
 * @brief   gets the timer value
 * @returns time delta: the difference between current time and start time
*/
time_t BopIt::get_timer() const {
    return current_time-start_time;
}

/**
 * @brief   selects a random state and starts the corresponding game
 * @returns state enum for selected game: slots, roulette, or pachinko
 * @post    game is started
*/
BopItState BopIt::select_random_game() const {
    switch (rand()%3) {
        case 0: 
            return slots;
        case 1: 
            return pachinko;
        case 2: 
            return roulette;
    }
    return off;
}