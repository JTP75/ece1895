#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

#define DISPLAY_T U8G2_SSD1309_128X64_NONAME0_F_4W_SW_SPI
 
class Display {
    private:
        DISPLAY_T u8g2;
    public:
        Display();
        ~Display();

        void load_init_screen();

        void load_start_screen();

        void load_win_screen();
        void load_lose_screen();

        void load_slots_screen();
        void set_slot_reel_values(const char *s3, const char *s2, const char *s1);
        
        void load_roulette_screen();
        void set_roulette_wheel_angle(const uint8_t &angle);

        void load_pachinko_screen();
        void move_pachinko_ball(const uint8_t &x0, const uint8_t &y0, const uint8_t &x1, const uint8_t &y1);
};

#endif
