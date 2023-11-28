#include <bopit.h>
#include <math.h>

#define TIME_LIMIT 10000

BopIt::BopIt() {
    state = await;
    disp = Display();
    pachinko_ball_x = 60;
    pachinko_ball_y = 15;

    pinMode(7,INPUT);
    disp.load_init_screen();
}

BopIt::~BopIt() {
}

void BopIt::await_coin() {
    state = await;
    disp.load_start_screen();
    while(digitalRead(7)==LOW);
    delay(250);
}

void BopIt::set_state(const BopItState &s) {
    state = s;
}

const BopItState &BopIt::get_curr_state() const {
    return state;
}

void BopIt::end_game() {
    delay(1000);
    if (state==win) {
        disp.load_win_screen();
    } else if (state==lose) {
        disp.load_lose_screen();
    }
    delay(1500);
}

void BopIt::start_slots() {
    state = slots;
    disp.load_slots_screen();
    t0=millis();
    bool iswin;
    while (millis()-t0<TIME_LIMIT) {
        if (digitalRead(7)==HIGH) {
            iswin = (bool)(random()%2);
            spin_slots(iswin);
            if (iswin) state = win; else state = lose;
            return;
        }
    }
    state = lose;
}

/**
 * @brief spins slot reels, win/lose is predetermined (like a real slot machine)
 * 
 * @param win predetermined win/loss state
 * 
 * @note program will hang here for appr 4 seconds
 */
void BopIt::spin_slots(bool win) {
    if (this->state != slots) 
        return;
    uint64_t start = millis();

    char s1[2],s2[2],s3[2];
    
    while (millis()-start < 2000) {     // spin 1,2,3
        uint8_t i1 = random(9)+1, i2 = random(9)+1, i3 = random(9)+1;

        itoa(i1,s1,10);
        itoa(i2,s2,10);
        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    } 
    if (win) {itoa(7,s1,10);}
    while (millis()-start < 2800) {     // spin 2,3
        uint8_t i2 = random(9)+1, i3 = random(9)+1;

        itoa(i2,s2,10);
        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    } 
    if (win) {itoa(7,s2,10);}
    while (millis()-start < 3600) {     // spin 3
        uint8_t i3 = random(9)+1;

        itoa(i3,s3,10);

        disp.set_slot_reel_values(s3,s2,s1);
        delay(50);
    }
    if (win) {itoa(7,s3,10);}
    else if (s1==s2) {itoa(7,s3,10);}
    disp.set_slot_reel_values(s3,s2,s1);
}

void BopIt::start_roulette() {
    state = roulette;
    disp.load_roulette_screen();
    t0=millis();
    bool iswin;
    while (millis()-t0<TIME_LIMIT) {
        if (digitalRead(7)==HIGH) {
            iswin = (bool)(random()%2);
            spin_roulette(iswin);
            if (iswin) state = win; else state = lose;
            return;
        }
    }
    state = lose;
}

void BopIt::spin_roulette(bool win) {
    if (this->state != roulette) 
        return;
    int angle = 0, incr = 0, incr_max, it;
    if (win) {
        incr_max = 29;
    } else {
        incr_max = 28;
    }
    while (incr<incr_max) {     // accel loop
        incr+=1;
        disp.set_roulette_wheel_angle(angle);
        angle += incr;
        delay(10);
    }
    it=0;
    while (incr>0) {            // decel loop
        if (it%7==0) incr-=1;
        disp.set_roulette_wheel_angle(angle);
        angle += incr;
        it+=1;
        delay(10);
    }
}

void BopIt::start_pachinko() {
    state = pachinko;
    pachinko_ball_x = 60;
    pachinko_ball_y = 15;
    disp.load_pachinko_screen();
    t0=millis();
    bool iswin;
    while (millis()-t0<TIME_LIMIT) {
        if (digitalRead(7)==HIGH) {
            iswin = (bool)(random()%2);
            delay(750);
            drop_pachinko_ball(iswin);
            if (iswin) state = win; else state = lose;
            return;
        }
    }
    state = lose;
}

void BopIt::move_pachinko_ball(bool left) {
    if (this->state != pachinko) 
        return;
    if (left) {
        if (pachinko_ball_x<=24) return;
        set_pball_pos(pachinko_ball_x-8,pachinko_ball_y);
    } else {
        if (pachinko_ball_x>=104) return;
        set_pball_pos(pachinko_ball_x+8,pachinko_ball_y);
    }
}

void BopIt::set_pball_pos(const uint8_t &x, const uint8_t &y) {
    if (this->state != pachinko) 
        return;
    disp.move_pachinko_ball(pachinko_ball_x,pachinko_ball_y,x,y);
    pachinko_ball_x = x;
    pachinko_ball_y = y;
}

void BopIt::drop_pachinko_ball(bool win) {
    if (this->state != pachinko) 
        return;
    uint8_t target;
    if (win) {
        if (pachinko_ball_x<64)
            target = 32;
        else
            target = 96;
    } else {
        if (abs(pachinko_ball_x-64) < abs(pachinko_ball_x-0) && abs(pachinko_ball_x-64) < abs(pachinko_ball_x-128))
            target = 64;
        else if (abs(pachinko_ball_x-0) < abs(pachinko_ball_x-64) && abs(pachinko_ball_x-0) < abs(pachinko_ball_x-128))
            target = 12;
        else
            target = 116;
    }

    for (uint8_t i=0; i<4; i++) {
        if (pachinko_ball_x<target) {
            set_pball_pos(pachinko_ball_x+4,pachinko_ball_y+8);
        } else {
            set_pball_pos(pachinko_ball_x-4,pachinko_ball_y+8);
        }
        delay(400);
    }
    set_pball_pos(pachinko_ball_x,pachinko_ball_y+12);
}