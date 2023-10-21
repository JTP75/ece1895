#include <roulette.h>

Roulette::Roulette() {
    in_progress = false;
}
void Roulette::start() {
    in_progress = true;
}
bool Roulette::is_completed() {
    bool status = true;
    if (status)
        in_progress = false;
    return status;
}