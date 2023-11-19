#include "Slotmachine.h"
#include <cstdlib>
#include <time.h> 

Slotmachine::Slotmachine() {
  srand(static_cast<unsigned int>(time(nullptr))); // sets seed
  rand();
  str_reels = new std::string[9];
}

Slotmachine::~Slotmachine() {
  delete[] str_reels;
}

Reels Slotmachine::get_reel(int p) {
  return num_reels[p];
}

void Slotmachine::odds() {
  int count[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int temp;
  for (int i=0; i<100000; i++) {
    temp = test_spins();
    count[temp] += 1;
  }
  for (int i = 0; i<8; i++) {
    std::cout << get_reel(i) << " = " << count[i] << std::endl;
  }
}

//this function is used to adjust and test the probabilities. once we're satisfied with a distribution,
//we can delete this function and the odds() function to save memory.
int Slotmachine::test_spins() {
  double val1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX); // normalizing probabilities
  if (val1 < 0.600) {
    int val2 = rand()%5;
    return num_reels[val2];
  }
  else if (val1 > 0.600 && val1 < 0.825) {
    return cherry;
  }
  else if (val1 > 0.825 && val1 < 0.950) {
    return coin;
  }
  else if (val1 > 0.950) {
    return seven;
  }
  else {
    return EXIT_FAILURE;
  }
}

std::string* Slotmachine::spin() {
  for (int i=0; i<9; i++) {
    // normalizing probabilities to be in the range 0<p<1
    double val1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    if (val1 > 0 && val1 <= 0.120) {
       *(str_reels + i) = "  orange  ";
    }
    else if (val1 > 0.120 && val1 <= 0.240) {
       *(str_reels + i) = "  lemon   ";
    }
    else if (val1 > 0.240 && val1 <= 0.360) {
       *(str_reels + i) = "  grape   ";
    }
    else if (val1 > 0.360 && val1 <= 0.480) {
       *(str_reels + i) = "watermelon";
    }
    else if (val1 > 0.480 && val1 <= 0.600) {
       *(str_reels + i) = "strawberry";
    }
    else if (val1 > 0.600 && val1 <= 0.825) {
      *(str_reels + i) = "  cherry  ";
    }
    else if (val1 > 0.825 && val1 <= 0.950) {
      *(str_reels + i) = "   coin   ";
    }
    else if (val1 > 0.950) {
      *(str_reels + i) = "  seven   ";
    }
  }
  return str_reels;
}

void Slotmachine::reels_screen(std::string* r) {
  std::cout << "|" << *(r) << "|" << *(r+1) << "|" << *(r+2) << "|" << std::endl;
  std::cout << "|" << *(r+3) << "|" << *(r+4) << "|" << *(r+5) << "|" << std::endl;
  std::cout << "|" << *(r+6) << "|" << *(r+7) << "|" << *(r+8) << "|" << std::endl;
}
