#include "BopIt.h"
#include "Display.h"
#include <Wire.h>

// analog pins
int coin_scanner_pin = A0;
int lever_pin = A1;
int joystick_y_pin = A2;
int roulette_pin = A3;

Display screen;

int main() {
  init();
  delay(500); // delay for seed
  // setting up pins
  pinMode(coin_scanner_pin, INPUT);
  pinMode(lever_pin, INPUT);
  pinMode(joystick_y_pin, INPUT);
  pinMode(roulette_pin, INPUT);

  Wire.begin(); // starts I2C transmission
  Wire.beginTransmission(0x27); // starts sending to address of LCD
  BopIt game; // creates bopit object
  screen.start_screen();
  game.set_state(awaiting_coin);

  //scanning for coin
  while (game.get_curr_state() == awaiting_coin) {
    if (analogRead(coin_scanner_pin) < 500) {
      game.set_state(start);
    }
  }

  do {
    BopItState choice = game.action();
    switch(choice) {
       case slots:
          game.slots_game();
          break;
       case pachinko:
          game.pachinko_game();
          break;
       case roulette:
          game.roulette_game();
          break;
    }
  } while (game.get_curr_state() != game_over);

  //Wire.endTransmission();
}