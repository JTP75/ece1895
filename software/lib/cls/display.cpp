#include <display.h>
#include <math.h>

/* roulette geometry */
#define RADIUS 24
#define CENTER_X 64
#define CENTER_Y 38

//static const char* slots_reel[] PROGMEM = {"diamond","heart","club","spade"};

/* drawing */
void draw_start(DISPLAY_T &);
void draw_win(DISPLAY_T &);
void draw_lose(DISPLAY_T &);

void draw_slots(DISPLAY_T &);

void draw_roulette(DISPLAY_T &);
void draw_roulette_angle(DISPLAY_T &, const uint8_t &);

void draw_pachinko(DISPLAY_T &);
void draw_pachinko_ball(DISPLAY_T &u8g2, const uint8_t &x, const uint8_t &y);
 
/* class methods */

Display::Display() : u8g2(U8G2_R0, /* sck */ 13, /* sda */ 11, /* cs */ 10, /* dc */ 9, /* res */ 8) {
    pinMode(9, OUTPUT);
    digitalWrite(9, 0);

    u8g2.begin();
}

Display::~Display() {
}

void Display::load_init_screen() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_fur35_tr);
    u8g2.drawStr(10,48,"$ $ $");
    u8g2.sendBuffer();
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
        
    u8g2.drawStr(19,39,s1);
    u8g2.drawStr(61,39,s2);
    u8g2.drawStr(103,39,s3);

    u8g2.sendBuffer();
}

void Display::set_roulette_wheel_angle(const uint8_t &angle) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(0,10,128,54);
    u8g2.setDrawColor(1);
    u8g2.drawCircle(CENTER_X,CENTER_Y,RADIUS);
    u8g2.drawTriangle(32,38, 16,34, 16,42);
    draw_roulette_angle(u8g2, angle);
}

void Display::load_roulette_screen() {
    draw_roulette(u8g2);
}

void Display::load_pachinko_screen() {
    draw_pachinko(u8g2);
}

void Display::move_pachinko_ball(const uint8_t &x0, const uint8_t &y0, const uint8_t &x1, const uint8_t &y1) {
    u8g2.setDrawColor(0);
    draw_pachinko_ball(u8g2,x0,y0);
    u8g2.setDrawColor(1);
    draw_pachinko_ball(u8g2,x1,y1);

    u8g2.sendBuffer();
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
    u8g2.drawTriangle(32,38, 16,34, 16,42);
    u8g2.drawCircle(CENTER_X,CENTER_Y,RADIUS);

    draw_roulette_angle(u8g2, 0);

    u8g2.sendBuffer();
}

void draw_roulette_angle(DISPLAY_T &u8g2, const uint8_t &gross_angle) {
    uint8_t angle = gross_angle%45, x1, x2, y1, y2, x1r, x2r, y1r, y2r;
    for (int line_angle = 0; line_angle<180; line_angle+=45) {
        x1 = (uint8_t)round(CENTER_X - RADIUS*cos(-DEG_TO_RAD*(angle+line_angle)));
        x2 = (uint8_t)round(CENTER_X + RADIUS*cos(-DEG_TO_RAD*(angle+line_angle)));
        y1 = (uint8_t)round(CENTER_Y + RADIUS*sin(-DEG_TO_RAD*(angle+line_angle)));
        y2 = (uint8_t)round(CENTER_Y - RADIUS*sin(-DEG_TO_RAD*(angle+line_angle)));

        x1r = (uint8_t)round(CENTER_X - RADIUS*cos(-DEG_TO_RAD*(angle+line_angle+22.5)));
        x2r = (uint8_t)round(CENTER_X + RADIUS*cos(-DEG_TO_RAD*(angle+line_angle+22.5)));
        y1r = (uint8_t)round(CENTER_Y + RADIUS*sin(-DEG_TO_RAD*(angle+line_angle+22.5)));
        y2r = (uint8_t)round(CENTER_Y - RADIUS*sin(-DEG_TO_RAD*(angle+line_angle+22.5)));

        u8g2.drawTriangle(CENTER_X,CENTER_Y, x1,y1, x1r, y1r);
        u8g2.drawTriangle(CENTER_X,CENTER_Y, x2,y2, x2r, y2r);
    }

    u8g2.sendBuffer();
}

void draw_pachinko(DISPLAY_T &u8g2) {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_5x7_tr); 
    u8g2.drawStr(4,8,"Pachinko: drop the ball!");

    uint8_t row,col;
    
    for (row=20; row<50; row+=8) {
        if (row==20 || row==28) {
            for (col=16; col<=112; col+=8) {
                if ((row-4)%16) {
                    u8g2.drawPixel(col,row);
                } else {
                    if (col>=112) continue;
                    u8g2.drawPixel(col+4,row);
                }
            }
        } else {
            for (col=8; col<=120; col+=8) {
                if ((row-4)%16) {
                    u8g2.drawPixel(col,row); 
                } else {
                    if (col>=120) continue;
                    u8g2.drawPixel(col+4,row);
                }
            }
        }
    }

    u8g2.drawStr(2,60,"   |     |     |     |   ");
    u8g2.drawStr(2,61," L |  W  |  L  |  W  | L ");
    u8g2.drawStr(2,63,"   |     |     |     |   ");
    u8g2.drawHLine(1,63,128);

    u8g2.drawVLine(1,16,64);
    u8g2.drawVLine(127,16,64);

    draw_pachinko_ball(u8g2,60,15);

    u8g2.sendBuffer();
}

void draw_pachinko_ball(DISPLAY_T &u8g2, const uint8_t &x, const uint8_t &y) {
    u8g2.drawDisc(x,y,2);
}