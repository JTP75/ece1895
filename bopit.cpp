#include "BopIt.h"

BopIt::BopIt() {
  Serial.println("BopIt constructor called");
  disp = new Display();
  timer1 = 5000;
  state = awaiting_coin;
}

BopIt::~BopIt() {
  delete disp;
  state = awaiting_coin;
}

void BopIt::set_state(BopItState s) {
    state = s;
}

BopItState BopIt::get_curr_state() const {
    return state;
}

BopItState BopIt::action() {
  if (disp->get_score() == 99) {
    disp->win_display();
    state = awaiting_coin;
    disp->reset_score();
    return state;
  }
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
  state = slots;
  timeBegin = millis();
  while(millis() - timeBegin < timer1) {
    if (digitalRead(4) == HIGH) {
      delay(750);
      Serial.println(state);
      disp->update_score(1);
      state = start;
      return;
    }
    else if (digitalRead(7) == HIGH || digitalRead(8) == HIGH) {
      disp->reset_score();
      set_state(game_over);
      disp->lose_display();
      delay(1500);
    }
  }
}

void BopIt::roulette_game() {
  disp->load_roulette_screen();
  state = roulette;
  timeBegin = millis();
  while(millis() - timeBegin < timer1) {
    if (digitalRead(7) == HIGH) {
      delay(750);
      Serial.println(state);
      disp->update_score(1);
      state = start;
      return;
    }
    else if (digitalRead(4) == HIGH || digitalRead(8) == HIGH) {
      disp->reset_score();
      set_state(game_over);
      disp->lose_display();
      delay(1500);
    }
  }
}

void BopIt::pachinko_game() {
  disp->load_pachinko_screen();
  state=pachinko;
  timeBegin = millis();
  while(millis() - timeBegin < timer1) {
    if (digitalRead(8) == HIGH) {
      delay(750);
      Serial.println(state);
      disp->update_score(1);
      state = start;
      return;
    }
    else if (digitalRead(4) == HIGH || digitalRead(7) == HIGH) {
      disp->reset_score();
      set_state(game_over);
      disp->lose_display();
      delay(1500);
    }
  }
}
