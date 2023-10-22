#include <display.h>

Display::Display() : disp(0x27,16,2) {
  disp.init();
  disp.clear();         
  disp.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  disp.setCursor(0,0);   //Set cursor to character 1 on line 1
  disp.print("Score=0");
  disp.setCursor(0,1);   //Move cursor to character 1 on line 2
  disp.print("Game Start");
}

void Display::update_score() {
  score++;
  disp.setCursor(0,0);   //Move cursor to character 1 on line 2
  disp.print("Score=");
  disp.print(score);
}

void Display::load_pachinko_screen() {
  
}

void Display::load_slots_screen() {
  
}

void Display::load_roulette_screen() {
  
}
