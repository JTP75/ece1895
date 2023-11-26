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
    //Serial.begin(9600);
    //while(!Serial);
    //Serial.println("Serial started in 9600. Beginning setup...");

    BopIt bopit;

    //Serial.println("Setup complete!");
    //Serial.println(free_memory());
    
    randomSeed(analogRead(A0));

    bopit.disp.load_init_screen();
    delay(2000);

    /* main loop */
    while (1) {
        bool iswin = (bool)(random()%2);
        int game = 3;//random()%3 + 1;
        
        bopit.disp.load_start_screen();
        delay(1000);
        if (game==1) {
            bopit.start_slots();
            delay(1000);
            bopit.spin_slots(iswin);
            delay(1000);
        } else if (game==2) {
            bopit.start_roulette();
            delay(1000);
            bopit.spin_roulette(iswin);
            delay(1000);
        } else {
            bopit.start_pachinko();
            delay(1000);
            bopit.drop_pachinko_ball(iswin);
            delay(1000);
        }
        if (iswin) 
            bopit.disp.load_win_screen();
        else
            bopit.disp.load_lose_screen();
        delay(1000);
    }
}

void loop() {
} 