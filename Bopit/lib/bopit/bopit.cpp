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
 * @brief   updates internal clock and performs state machine logic
 * @returns next state enum based on current state and internal logic
*/
BopItState BopIt::get_next_state() {
    update_time();
    
    switch (this->state) {
        case off:
            if (power_button.is_pressed()) {
                Serial.write("state -> ins coin\n");
                delay(200);
                set_timer_start();
                return awaiting_coin;
            } else {
                return off;
            }
        case awaiting_coin:
            coin_scanner.poll_scanner(get_timer_delta());
            if (coin_scanner.balance>=0.25) {
                Serial.write("state -> game\n");
                set_timer_start();
                return select_random_game();
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else {
                return awaiting_coin;
            }
        case slots: 
            if (slot_machine.is_completed()) {
                Serial.write("state -> win\n");
                set_timer_start();
                return game_over_win;
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else if (get_timer_delta()>=time_limit) {
                Serial.write("state -> loser\n");
                set_timer_start();
                return game_over_lose;
            } else {
                return slots;
            }
        case pachinko:
            if (slot_machine.is_completed()) {
                Serial.write("state -> win\n");
                set_timer_start();
                return game_over_win;
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else if (get_timer_delta()>=time_limit) {
                Serial.write("state -> loser\n");
                set_timer_start();
                return game_over_lose;
            } else {
                return pachinko;
            }
        case roulette:
            if (slot_machine.is_completed()) {
                Serial.write("state -> win\n");
                set_timer_start();
                return game_over_win;
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else if (get_timer_delta()>=time_limit) {
                Serial.write("state -> loser\n");
                set_timer_start();
                return game_over_lose;
            } else {
                return roulette;
            }
        case game_over_lose:
            if (get_timer_delta() >= 5000) {
                // no coin return: we keep the money if they lose >:)
                Serial.write("state -> ins coin\n");
                return awaiting_coin;
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else {
                return game_over_lose;
            }
        case game_over_win:
            if (get_timer_delta() >= 5000) {
                coin_scanner.return_coins();
                Serial.write("state -> ins coin\n");
                return awaiting_coin;
            } else if (power_button.is_pressed()) {
                Serial.write("state -> off\n");
                delay(200);
                return off;
            } else {
                return game_over_win;
            }
    }
}

/**
 * @brief   updates the current state by calling get_next_state()
 * @post    game cycles to next state
*/
void BopIt::update_state() {
    state = get_next_state();
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
void BopIt::set_timer_start() {
    start_time = current_time;
}

/**
 * @brief   gets the timer value
 * @returns time delta: the difference between current time and start time
*/
time_t BopIt::get_timer_delta() const {
    return current_time-start_time;
}

/**
 * @brief   selects a random state and starts the corresponding game
 * @returns state enum for selected game: slots, roulette, or pachinko
 * @post    game is started
*/
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