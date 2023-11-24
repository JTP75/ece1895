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

    char s1[2],s2[2],s3[2];
    
    while (millis()-start < 2000) {
        uint8_t i1 = random(9)+1, i2 = random(9)+1, i3 = random(9)+1;

        itoa(i1,s1,10);
        itoa(i2,s2,10);
        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    } 
    if (win) {itoa(7,s1,10);}
    while (millis()-start < 2400) {
        uint8_t i2 = random(9)+1, i3 = random(9)+1;

        itoa(i2,s2,10);
        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    } 
    if (win) {itoa(7,s2,10);}
    while (millis()-start < 2800) {
        uint8_t i3 = random(9)+1;

        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    }
    if (win) {itoa(7,s3,10);}
    disp.set_slot_reel_values(s3,s2,s1);
}

void BopIt::start_roulette() {
    disp.load_roulette_screen();
}

void BopIt::spin_roulette(bool win) {
    int angle = 0, incr;
    if (win) {
        incr = 40;
    } else {
        incr = 32;
    }
    int it=0;
    while (incr>0) {
        if (it%7==0) incr-=1;
        disp.set_roulette_wheel_angle(angle);
        angle += incr;
        it+=1;
        delay(10);
    }
}

void BopIt::start_pachinko() {
}
