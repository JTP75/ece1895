#include <pachinko.h>

/**
 * @brief   ctor for pachinko game
 * @returns instance of pachinko
*/
Pachinko::Pachinko() {
    in_progress = false;
    drop_pos = drop_positions/2 + 1;

    pinMode(joystick_x_pin, INPUT);
    pinMode(joystick_y_pin, INPUT);
    pinMode(joystick_down_pin, INPUT);
    this->update_joystick();
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

bool Pachinko::over() const {
    return !in_progress;
}

/**
 * @brief   updates internal joystick x&y positions
 * 
 */
void Pachinko::update_joystick() {
    joystick_x_pos = analogRead(joystick_x_pin);
    joystick_y_pos = analogRead(joystick_y_pin);
    
}

void Pachinko::update_drop_pos() {
    update_joystick();
    if (joystick_x_pos<768 && drop_pos>1) {
        drop_pos -= 1;
        Serial.println(drop_pos);
        delay(500);
    } else if (joystick_x_pos>256 && drop_pos<drop_positions) {
        drop_pos += 1;
        Serial.println(drop_pos);
        delay(500);
    }
}