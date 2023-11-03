#include "BopIt.h"
#include "Display.h"
#include <Wire.h>

// digital pins
const int coin_scanner_pin = 2;
const int lever_pin = 4;
const int roulette_pin = 7;
const int joystick_y_pin = 8;

int main() {
  init();
  Serial.begin(9600);
  // setting up pins
  pinMode(coin_scanner_pin, INPUT);
  pinMode(lever_pin, INPUT);
  pinMode(roulette_pin, INPUT);
  pinMode(joystick_y_pin, INPUT);

  Wire.begin(); // starts I2C transmission
  Wire.beginTransmission(0x27); // starts sending to address of LCD
  BopIt game; // creates bopit object
  game.disp->start_screen();

  while(1) {
    //scanning for coin
    do {
      /*Serial.println(digitalRead(coin_scanner_pin));
      Serial.println(digitalRead(lever_pin));
      Serial.println(digitalRead(roulette_pin));
      Serial.println(digitalRead(joystick_y_pin));
      Serial.println();*/
        if (digitalRead(coin_scanner_pin) == HIGH) {
          /*Serial.println(digitalRead(coin_scanner_pin));
          Serial.println(digitalRead(lever_pin));
          Serial.println(digitalRead(roulette_pin));
          Serial.println(digitalRead(joystick_y_pin));
          Serial.println();*/
          delay(600);
          game.set_state(start);
        }
      } while (game.get_curr_state() == awaiting_coin);
    
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
      game.disp->start_screen();
      delay(1000);
      //Wire.endTransmission();
    }
}
