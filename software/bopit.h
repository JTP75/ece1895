#pragma once

#include "power_button.h"
#include "display.h"
#include "slot_machine.h"
#include "roulette.h"
#include "pachinko.h"
#include "coin_scanner.h"

enum BopItState {
    off,
    awaiting_coin,
    slots,
    pachinko,
    roulette,
    game_over_win,
    game_over_lose
};

class BopIt {
    public:
        BopIt();
        

    private:
        SlotMachine slot_machine;
        Roulette roulette;
        Pachinko pachinko;
        CoinScanner coin_scanner;
        Display display;
        PowerButton power_button;
        BopItState state;
};

#include "bopit.cpp";