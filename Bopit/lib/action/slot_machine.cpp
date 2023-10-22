#include <slot_machine.h>
/**
 * @brief   slot machine ctor
 * @returns slot machine instance initialized to idle state
*/
SlotMachine::SlotMachine() {
    in_progress = false;
    pinMode(lever_pin, INPUT);
}

/**
 * @brief   starts slot machine game
*/
void SlotMachine::start() {
    Serial.write("Starting Slots\n");
    in_progress = true;
}

/**
 * @brief   stops slots game
*/
void SlotMachine::stop() {
    Serial.write("Slots game over\n");
    in_progress = false;
}

/**
 * @brief   checks if lever is pulled & updates state
 * @returns true if action is completed
*/
bool SlotMachine::is_completed() {
    bool status = false;
    if (status) stop();
    return status;
}