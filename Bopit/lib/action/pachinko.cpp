#include <pachinko.h>

/**
 * @brief   ctor for pachinko game
 * @returns instance of pachinko
*/
Pachinko::Pachinko() {
    in_progress = false;
    pinMode(joystick_x_pin, INPUT);
    pinMode(joystick_y_pin, INPUT);
}

/**
 * @brief   starts pachinko game
*/
void Pachinko::start() {
    Serial.write("Starting Pachinko\n");
    in_progress = true;
}

/**
 * @brief   stops pachinko game
*/
void Pachinko::stop() {
    Serial.write("Pachinko game over\n");
    in_progress = false;
}

/**
 * @brief   checks if game is complete and stops the game
 * @returns true if action is complete
*/
bool Pachinko::is_completed() {
    bool status = false;
    if (status) stop();
    return status;
}