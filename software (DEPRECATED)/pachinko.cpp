#include "pachinko.h"

Pachinko::Pachinko() {
    in_progress = false;
}
void Pachinko::start() {
    in_progress = true;
}
bool Pachinko::is_completed() {
    bool status = true;
    if (status)
        in_progress = false;
    return status;
}