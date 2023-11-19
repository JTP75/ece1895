#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <string>

enum Reels {
  orange = 0,
  lemon = 1,
  grape = 2,
  watermelon = 3,
  strawberry = 4,
  cherry = 5,
  coin = 6,
  seven = 7
};

class Slotmachine {
  private:
    //added a Reels array and a string pointer for dynamically allocating the number of reels we want shown
    //on the screen. If we can find a way to print strings without having a string array or making the code
    //absurdly inefficient, we can save more memory, hopefully.
    Reels num_reels[8] = {orange, lemon, grape, watermelon, strawberry, cherry, coin, seven};
    std::string* str_reels;

  public:
    Slotmachine();
    ~Slotmachine();
    void odds();
    int test_spins();
    std::string* spin();
    void reels_screen(std::string*);
    Reels get_reel(int);
};
#endif
