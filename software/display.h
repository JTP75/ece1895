#pragma once

class Display {
    private:
        int device;
    public:
        void update();
        void load_slots_screen();
        void load_roulette_screen();
        void load_pachinko_screen();
};