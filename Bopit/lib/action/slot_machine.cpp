#include <slot_machine.h>

SlotMachine::SlotMachine() {
    in_progress = false;
}
void SlotMachine::start() {
    Serial.write("Starting Slots");
    in_progress = true;
}
bool SlotMachine::is_completed() {
    bool status = true;
    if (status)
        in_progress = false;
    return status;
}