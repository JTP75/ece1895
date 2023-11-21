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
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Serial started in 9600. Beginning setup...");

    BopIt bopit;

    Serial.println("Setup complete!");
    Serial.print("Remaining memory: "); Serial.print(free_memory()); Serial.println(" / 2048 Bytes");
    
    srand(micros());
    
    bopit.disp.load_start_screen();

    bopit.spin_slots(true);

    /* main loop */
    while (1) {
        delay(1000);
    }
}

void loop() {
} 