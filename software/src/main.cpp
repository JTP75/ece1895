#include <bopit.h>
//#include <SPI.h>

extern unsigned int __heap_start;
extern void *__brkval;
int free_memory() {
    int free_memory;
    if ((int)__brkval == 0)
        free_memory = ((int)&free_memory) - ((int)&__heap_start);
    else
        free_memory = ((int)&free_memory) - ((int)__brkval);
    return free_memory;
}

// digital pins
const int coin_scanner_pin = 2;
const int lever_pin = 4;
const int roulette_pin = 7;
const int joystick_y_pin = 8;

void setup() {

    BopIt bopit;
    
    randomSeed(analogRead(A0));
    
    delay(2000);
    uint8_t game;

MAIN_LOOP:

    bopit.await_coin();
    delay(500);

    game = 1+random()%3;
    if (game==1)
        bopit.start_slots();
    else if (game==2)
        bopit.start_roulette();
    else if (game==3)
        bopit.start_pachinko();

    bopit.end_game();

    goto MAIN_LOOP;
}

void loop() {
} 