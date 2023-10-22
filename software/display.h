#ifndef Display_h
#define Display_h

#include <LiquidCrystal_I2C.h>
 
class Display {
    private:
        LiquidCrystal_I2C disp;
        int score;
    public:
        Display();
        void update_score(int);
        void start_screen();
        void win_display();
        void load_slots_screen();
        void load_roulette_screen();
        void load_pachinko_screen();
};
#endif
