#include <roulette.h>

/**
 * @brief   ctor for roulette game
 * @returns instance of roulette
*/
Roulette::Roulette() {
    in_progress = false;
    pinMode(spin_pin, INPUT);
}

/**
 * @brief   starts roulette game
*/
void Roulette::start() {
    Serial.write("Starting Roulette\n");
    in_progress = true;
}

/**
 * @brief   stops roulette game
*/
void Roulette::stop() {
    Serial.write("Roulette game over\n");
    in_progress = false;
}

/**
 * @brief   checks if game is complete and stops the game
 * @returns true if action is complete
*/
bool Roulette::is_completed() {
    bool status = false;
    if (status) stop();
    return status;
}