#include "Arduino.h"
#include "SlotMachineBopIt.h"
#include <LiquidCrystal_I2C.h>

SlotMachineBopIt::SlotMachineBopIt() {
  game_start = false;
  lever_pin = analogRead(A0);
  roulette_pin = analogRead(A1);
  coin_verifier_pin = analogRead(A2);
  joystick_pinX = analogRead(A3);
  joystick_pinY = analogRead(A4);
  //screen.start_screen();
}

bool SlotMachineBopIt::coinVerifier(int pin) {
    
}

bool SlotMachineBopIt::getGameState() {
  return game_start;
}

void SlotMachineBopIt::action() {
  Serial.begin(9600);
  randomSeed(millis());
  int val = random(1,4);
  if (val == 1) {
    Serial.println("Pull the lever!");
    //slots();
  }
  else if (val == 2) {
    Serial.println("Spin the roullete!");
    //roulette();
  }
  else {
    Serial.println("Move down on the joystick!");
    //pachinko();
  }
}

void SlotMachineBopIt::slots() {
  
}

void SlotMachineBopIt::roulette() {
  
}

void SlotMachineBopIt::pachinko() {
  
}

void SlotMachineBopIt::setGameState() {
  game_start = true;
}
