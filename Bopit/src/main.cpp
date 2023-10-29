#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define JS_X_PIN A0
#define JS_Y_PIN A1
#define JS_DOWN_PIN A2

extern unsigned int __heap_start;
extern void *__brkval;

/* fn */
int freeMemory();
void load_await_screen();
void load_pachinko_screen();
void pachinko_drop_pos(u8 pos);

enum State : u8 {
    await,
    slots,
    slots_done,
    roulette,
    roulette_done,
    pachinko,
    pachinko_done,
    win,
    lose
};

Adafruit_SSD1306 display(128,64);
State state;
unsigned long timer_start;
u8 pachinko_pos;
u8 victory;

void setup() {

    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    display.display();

    /* begin setup */

    Serial.begin(9600);
    while (!Serial);
    pinMode(JS_X_PIN, INPUT);
    pinMode(JS_Y_PIN, INPUT);
    pinMode(JS_DOWN_PIN, INPUT);

    pachinko_pos = 60;
    victory = 0;

    /* end setup */

    Serial.write("Setup Complete!\n");
    Serial.print("Free memory: ");
    Serial.println(freeMemory());
    
    delay(2000);

    state = await;
    load_await_screen();

    timer_start = millis();

}

void loop() {

    /* state change logic */
    switch (state) {
        case await:
            if (millis()-timer_start>2000) {
                Serial.println("Pachinko");
                state = pachinko;
                load_pachinko_screen();
            }
        break;
        case slots:
        break;
        case slots_done:
        break;
        case roulette:
        break;
        case roulette_done:
        break;
        case pachinko:
            if (analogRead(JS_DOWN_PIN)>=1020) {
                Serial.println("Pachinko done");
                state = pachinko_done;
            }
        break;
        case pachinko_done:
            if (victory) {
                state = win;
            } else {
                state = lose;
            }
        break;
        case win:
        break;
        case lose:
        break;
    }
    /* state logic */
    switch (state) {
        case await:
        break;
        case slots:
        break;
        case slots_done:
        break;
        case roulette:
        break;
        case roulette_done:
        break;
        case pachinko:
            if (analogRead(JS_X_PIN)>768) {
                pachinko_drop_pos(0);
                delay(250);
            } else if (analogRead(JS_X_PIN)<256) {
                pachinko_drop_pos(1);
                delay(250);
            }
        break;
        case pachinko_done:
            Serial.println("fuckface");
            u8 go_left = rand()%2;
            display.fillRect(pachinko_pos,0,6,8,SSD1306_BLACK);
            if (go_left) {
                pachinko_pos -= 12;
            } else {
                pachinko_pos += 12;
            }
            display.setCursor(pachinko_pos,8);
            display.print("o");
            display.display();
            delay(750);
        break;
        case win:
        break;
        case lose:
        break;
    }
}

/* impl */
int freeMemory() {
    int free_memory;
    if ((int)__brkval == 0)
        free_memory = ((int)&free_memory) - ((int)&__heap_start);
    else
        free_memory = ((int)&free_memory) - ((int)__brkval);
    return free_memory;
}

void load_await_screen() {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.print("Awaiting coin...");

    display.display();
}

void load_pachinko_screen() {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(pachinko_pos,0);
    display.print("o");
    for (u8 y=8;y<48;y+=8) {
        display.setCursor(0,y);
        if (y/8%2==1) {
            display.print("  .   .   .   .   .   ");
        } else {
            display.print("    .   .   .   .     ");
        }
    }
    display.setCursor(0,48);
    display.println("  |   |   |   |   |   ");
    display.setCursor(0,56);
    display.println("  | L | W | W | L |   ");
    display.display();
}

void pachinko_drop_pos(u8 dir) {

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    u8 prev = pachinko_pos;

    if (dir) {
        if (pachinko_pos<108)
            pachinko_pos += 24;
    } else {
        if (pachinko_pos>12)
            pachinko_pos -= 24;
    }

    display.fillRect(prev,0,6,8,SSD1306_BLACK);

    display.setCursor(pachinko_pos,0);
    display.print("o");

    display.display();
}