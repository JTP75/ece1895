#include <power_button.h>


PowerButton::PowerButton() {
    pin=0;
    pinMode(pin, INPUT);
}
PowerButton::PowerButton(int pin) {
    this->pin=pin;
    pinMode(pin, INPUT);
}
bool PowerButton::is_pressed() const {
    return digitalRead(pin)==HIGH;
}