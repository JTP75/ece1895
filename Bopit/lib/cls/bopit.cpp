#include <bopit.h>

BopIt::BopIt() {
    state = await;
    disp = Display();
}

BopIt::~BopIt() {
}

void BopIt::set_state(const BopItState &s) {
    state = s;
}

const BopItState &BopIt::get_curr_state() const {
    return state;
}

void BopIt::start_slots() {
}

/**
 * @brief spins slot reels, win/lose is predetermined (like a real slot machine)
 * 
 * @param win predetermined win/loss state
 * 
 * @note program will hang here for appr 4 seconds
 */
void BopIt::spin_slots(bool win) {
    //if (this->state != slots) 
    //    return;
    uint64_t start = millis();
    
    while (millis()-start < 5000) {
        uint8_t i1 = rand() % 10, i2 = rand() % 10, i3 = rand() % 10;
        char *s1, *s2, *s3;
        itoa(i1,s1,10);
        itoa(i2,s2,10);
        itoa(i3,s3,10);
        disp.set_slot_reel_values(s3,s2,s1);
        delay(500);
    }
}

void BopIt::start_roulette() {
}

void BopIt::start_pachinko() {
}
