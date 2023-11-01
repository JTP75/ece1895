#include "Display.h"

Display::Display() : disp(0x27,16,2) {
  //Serial.begin(9600);
  Serial.println("Display constructor successfully called.");
}

void Display::start_screen() {
  disp.clear();         
  disp.backlight();  // Make sure backlight is on
  disp.setCursor(0,0);
  disp.print("Insert a coin,");
  disp.setCursor(0,1);
  disp.print("to play.");  
}

void Display::update_score(int p) {
  score += p;
  disp.setCursor(0,0);   //Move cursor to character 1 on line 2
  disp.print("Score=");
  disp.print(score);
}

void Display::win_display() {
  disp.clear();
  disp.backlight();  // Make sure backlight is on         
  disp.setCursor(0,0);   //Set cursor to character 2 on line 0
  disp.print("Score=99");
  disp.print(", Game");
  disp.setCursor(0,1);
  disp.print("over. You win!");
}

void Display::lose_display() {
  disp.clear();
  disp.backlight();  // Make sure backlight is on         
  disp.setCursor(0,0);   //Set cursor to character 2 on line 0
  disp.print("Game Over.");
  disp.setCursor(0,1);
  disp.print("You Lose!");
}

void Display::load_pachinko_screen() {
  disp.clear();
  disp.backlight();  // Make sure backlight is on         
  disp.setCursor(0,0);   //Set cursor to character 2 on line 0
  disp.print("Flick the");
  disp.setCursor(0,1);
  disp.print("joystick!");
}

void Display::load_slots_screen() {
  disp.clear();
  disp.backlight();  // Make sure backlight is on         
  disp.setCursor(0,0);   //Set cursor to character 2 on line 0
  disp.print("Pull the");
  disp.setCursor(0,1);
  disp.print("lever!");
}

void Display::load_roulette_screen() {
  disp.clear();
  disp.backlight();  // Make sure backlight is on         
  disp.setCursor(0,0);   //Set cursor to character 2 on line 0
  disp.print("Spin the");
  disp.setCursor(0,1);
  disp.print("roulette!");
}