#include <display.h>

//static const char* slots_reel[] PROGMEM = {"diamond","heart","club","spade"};

/* drawing */
void draw_start(DISPLAY_T &);
void draw_win(DISPLAY_T &);
void draw_lose(DISPLAY_T &);

void draw_slots(DISPLAY_T &);

void draw_roulette(DISPLAY_T &);
 
/* class methods */

Display::Display() : u8g2(U8G2_R0, /* sck */ 13, /* sda */ 11, /* cs */ 10, /* dc */ 9, /* res */ 8) {
    pinMode(9, OUTPUT);
    digitalWrite(9, 0);

    u8g2.begin();
}

Display::~Display() {
}

void Display::load_start_screen() { 
    draw_start(u8g2);
}

void Display::load_win_screen() {
    draw_win(u8g2);
}

void Display::load_lose_screen() {
    draw_lose(u8g2);
}

void Display::load_slots_screen() {
    draw_slots(u8g2);
}

void Display::set_slot_reel_values(const char *s3, const char *s2, const char *s1) {
    u8g2.setFont(u8g2_font_5x7_tr); 
    
    Serial.println("+");
    
    u8g2.drawStr(19,39,s1);
    u8g2.drawStr(61,39,s2);
    u8g2.drawStr(103,39,s3);

    u8g2.sendBuffer();
}

void Display::load_roulette_screen() {
    draw_roulette(u8g2);
}

void Display::load_pachinko_screen() {
}


/* drawing */

void draw_start(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_5x7_tr); u8g2.drawStr(4,10,"Welcome to");
    u8g2.setFont(u8g2_font_9x15_tr); u8g2.drawStr(1,30,"Casino Bop-It!");
    u8g2.setFont(u8g2_font_5x7_tr); u8g2.drawStr(30,60,"Insert coin to play");

    u8g2.sendBuffer();
}

void draw_win(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_9x15_tr); u8g2.drawStr(28,36,"You win!");

    u8g2.setFont(u8g2_font_5x7_tr); 
    u8g2.drawStr(12,5,"$");
    u8g2.drawStr(114,11,"$");
    u8g2.drawStr(100,50,"$");
    u8g2.drawStr(6,43,"$");

    u8g2.setFont(u8g2_font_7x13_mr); 
    u8g2.drawStr(30,18,"$");
    u8g2.drawStr(109,25,"$");
    u8g2.drawStr(120,60,"$");
    u8g2.drawStr(20,53,"$");

    u8g2.sendBuffer();
}

void draw_lose(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_9x15_tr); u8g2.drawStr(22,36,"You lose!");
    u8g2.setFont(u8g2_font_5x7_tr); u8g2.drawStr(10,60,"Better luck next time!");

    u8g2.sendBuffer();
}

void draw_slots(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_5x7_tr); u8g2.drawStr(4,8,"Slots: pull the lever!");

    u8g2.drawRFrame(2,12,40,50,0);
    u8g2.drawRFrame(44,12,40,50,0);
    u8g2.drawRFrame(86,12,40,50,0);

    u8g2.drawStr(19, 39, "?");
    u8g2.drawStr(61, 39, "?");
    u8g2.drawStr(103, 39, "?");

    u8g2.sendBuffer();
}

void draw_roulette(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_5x7_tr); u8g2.drawStr(4,8,"Roulette: spin the wheel!");
    u8g2.drawCircle(64,38,24);

    u8g2.sendBuffer();
}