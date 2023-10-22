#ifndef COIN_SCANNER_H
#define COIN_SCANNER_H

class CoinScanner {
    private:
        int device;
    public:
        float balance;

        CoinScanner();
        void poll_scanner() const;
        void increment_balance();
};

#endif