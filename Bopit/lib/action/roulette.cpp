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
    Serial.write("Starting Roulette");
    in_progress = true;
}

/**
 * @brief   stops roulette game
*/
void Roulette::stop() {
    Serial.write("Roulette game over");
    in_progress = false;
}

/**
 * @brief   checks if game is complete and stops the game
 * @returns true if action is complete
*/
bool Roulette::is_completed() {
    bool status = true;
    if (status) stop();
    return status;
}