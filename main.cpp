#include "Slotmachine.h"

int main() {
  Slotmachine game;
  //game.odds();
  std::string* test;
  test = game.spin();
  game.reels_screen(test);
}