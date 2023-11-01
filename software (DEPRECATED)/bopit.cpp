#include "BopIt.h"

BopIt::BopIt() {
  Serial.println("BopIt constructor called");
  disp = new Display();
  timer1 = 1000;
  state = awaiting_coin;
}

BopIt::~BopIt() {
  delete disp;
}

void BopIt::set_state(BopItState s) {
    state = s;
}

BopItState BopIt::get_curr_state() const {
    return state;
}

BopItState BopIt::action() {
  randomSeed(millis());
  int val = random(1,4);
  if (val == 1) {
    return slots;
    //Serial.println("Pull the lever!");
    //slots();
  }
  else if (val == 2) {
    return pachinko;
    //Serial.println("Spin the roullete!");
    //roulette();
  }
  else {
    return roulette;
    //Serial.println("Move down on the joystick!");
    //pachinko();
  }
}

void BopIt::slots_game() {
  disp->load_slots_screen();
  timeBegin = millis();
  while(timeBegin - 0 != timer1) {
    Serial.println(timeBegin);
    if (analogRead(A1) > 1000) {
      disp->update_score(1);
      return;
      }
  }
  set_state(game_over);
  disp->lose_display();
}

void BopIt::roulette_game() {
  disp->load_roulette_screen();
  timeBegin = millis();
  while(timeBegin - 0 != timer1) {
    Serial.println(analogRead(A3));
    if (analogRead(A3) > 1000) {
      disp->update_score(1);
      return;
    }
  }
  set_state(game_over);
  disp->lose_display();
}

void BopIt::pachinko_game() {
  disp->load_pachinko_screen();
  timeBegin = millis();
  while(timeBegin - 0 != timer1) {
    Serial.println(analogRead(A2));
    if (analogRead(A2) > 1000) {
      disp->update_score(1);
      return;
    }
  }
  set_state(game_over);
  disp->lose_display();
}
