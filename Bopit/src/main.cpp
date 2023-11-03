#include <bopit.h>
#include <display.h>
#include <Wire.h>

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
    init();
    Serial.begin(9600);
    // setting up pins
    pinMode(coin_scanner_pin, INPUT);
    pinMode(lever_pin, INPUT);
    pinMode(roulette_pin, INPUT);
    pinMode(joystick_y_pin, INPUT);

    Wire.begin(); // starts I2C transmission
    Wire.beginTransmission(0x27); // starts sending to address of LCD
    BopIt game; // creates bopit object
    game.disp->start_screen();

    Serial.print("Free Memory: ");
    Serial.print(free_memory());
    Serial.println(" bytes");

    while(1) {
        //scanning for coin
        do {
        /*Serial.println(digitalRead(coin_scanner_pin));
        Serial.println(digitalRead(lever_pin));
        Serial.println(digitalRead(roulette_pin));
        Serial.println(digitalRead(joystick_y_pin));
        Serial.println();*/
            if (digitalRead(coin_scanner_pin) == HIGH) {
                /*Serial.println(digitalRead(coin_scanner_pin));
                Serial.println(digitalRead(lever_pin));
                Serial.println(digitalRead(roulette_pin));
                Serial.println(digitalRead(joystick_y_pin));
                Serial.println();*/
                delay(600);
                game.set_state(start);
            }
        } while (game.get_curr_state() == awaiting_coin);
        
        do {
            BopItState choice = game.action();
            switch(choice) {
            case slots:
                game.slots_game();
                break;
            case pachinko:
                game.pachinko_game();
                break;
            case roulette:
                game.roulette_game();
                break;
            }
        } while (game.get_curr_state() == start);
        game.disp->start_screen();
        delay(1000);
        //Wire.endTransmission();
    }
}

void loop() {}