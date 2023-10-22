#include <display.h>

/**
 * @brief LCD display class ctor
*/
Display::Display() : disp(0x27,16,2) {
    score = 0;  // score starts at 0
    disp.init();  // initializes display parameters
    disp.clear();         
    disp.backlight();  // Make sure backlight is on
    
    // Print a message on both lines of the LCD.
    disp.setCursor(0,0);   //Set cursor to character 1 on line 1
    disp.print("Score=0");
    disp.setCursor(0,1);   //Move cursor to character 1 on line 2
    disp.print("Game Start");
}

/**
 * @brief   sets display to show awaiting coin screen
*/
void Display::start_screen() {
    disp.clear();         
    disp.backlight();  // Make sure backlight is on
    disp.setCursor(0,0);
    disp.print("Insert a coin,");
    disp.setCursor(0,1);
    disp.print("to play.");  
}

/**
 * @brief   increments internal score value
 * @param   p increment value
*/
void Display::update_score(int p) {
    score += p;
    disp.setCursor(0,0);   //Move cursor to character 1 on line 2
    disp.print("Score=");
    disp.print(score);
}

/**
 * @brief   sets display to show win screen
*/
void Display::win_display() {
    disp.clear();
    disp.backlight();  // Make sure backlight is on         
    disp.setCursor(0,0);   //Set cursor to character 2 on line 0
    disp.print("Score=");
    disp.print(score);
    disp.print(", Game");
    disp.setCursor(0,1);
    disp.print("over. You win :)");
}

/**
 * @brief   sets display to show lose screen
*/
void Display::lose_display() {
    disp.clear();
    disp.backlight();  // Make sure backlight is on         
    disp.setCursor(0,0);   //Set cursor to character 2 on line 0
    disp.print("Score=");
    disp.print(score);
    disp.print(", Game");
    disp.setCursor(0,1);
    disp.print("over. You lose :(");
}

/**
 * @brief   sets display to pachinko game screen
*/
void Display::load_pachinko_screen() {
  
}

/**
 * @brief   sets display to slots game screen
*/
void Display::load_slots_screen() {
  
}

/**
 * @brief   sets display to roulette game screen
*/
void Display::load_roulette_screen() {
  
}