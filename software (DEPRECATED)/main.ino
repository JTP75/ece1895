#include "BopIt.h"
#include "Display.h"
#include <Wire.h>

// analog pins
const int coin_scanner_pin = A0;
const int lever_pin = A1;
const int roulette_pin = A2;
const int joystick_y_pin = A3;

int main() {
  init();
  delay(500); // delay for seed
  Serial.begin(9600);
  // setting up pins
  pinMode(coin_scanner_pin, INPUT);
  pinMode(lever_pin, INPUT);
  pinMode(joystick_y_pin, INPUT);
  pinMode(roulette_pin, INPUT);

  Wire.begin(); // starts I2C transmission
  Wire.beginTransmission(0x27); // starts sending to address of LCD
  BopIt game; // creates bopit object
  game.disp->start_screen();

  //scanning for coin
  while(1) {
    while (game.get_curr_state() == awaiting_coin) {
      Serial.println(analogRead(coin_scanner_pin));
      if (analogRead(coin_scanner_pin) > 725) {
        delay(175);
        game.set_state(start);
      }
      delay(250);
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
    } while (game.get_curr_state() == start);
    delay(1000);
    game.set_state(awaiting_coin);
    game.disp->start_screen();
    //Wire.endTransmission();
  }
}
