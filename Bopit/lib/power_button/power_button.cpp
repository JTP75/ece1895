#include <power_button.h>

/**
 * @brief   power button ctor
*/
PowerButton::PowerButton() {
    pinMode(pin, INPUT);
}

/**
 * @brief   gets button press
 * @returns true if button is pressed
*/
bool PowerButton::is_pressed() const {
    return digitalRead(pin)==HIGH;
}