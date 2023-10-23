#include <coin_scanner.h>

/**
 * @brief Construct a new Coin Scanner object
 */
CoinScanner::CoinScanner() {
    balance = 0.0;
    device = 0;
}

/**
 * @brief polls the coin scanner for input
 */
void CoinScanner::poll_scanner(int t) {
    if (t>3000) {
        increment_balance();
    }
}

/**
 * @brief increments balance by 25 cents
 * 
 */
void CoinScanner::increment_balance() {
    balance += 0.25;
}

/**
 * @brief resets balance and returns all coins
 * @returns false if balance is already zero
 */
bool CoinScanner::return_coins() {
    balance = 0.0;
}