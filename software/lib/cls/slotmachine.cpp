#include <slotmachine.h>

Slotmachine::Slotmachine() : reels{"cherry", "strawberry", "lemon", "orange", "grape", "watermelon", "7"} {
  
}

Slotmachine::~Slotmachine() {

}

String Slotmachine::get_reels(int p) {
  return reels[p];
}

String Slotmachine::spin() {
  randomSeed(millis());
  int val = random(1,8);
  return reels[val];
}
