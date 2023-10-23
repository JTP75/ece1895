#include <Arduino.h>
#include <bopit.h>
#include <HardwareSerial.h>

const int COMPLETE_PIN = 6;

BopIt *bopit;

void setup() {
  pinMode(COMPLETE_PIN, OUTPUT);
  digitalWrite(COMPLETE_PIN,LOW);

  Serial.begin(9600);
  while (!Serial);


  bopit = new BopIt();
  Serial.write("Setup Complete!\n");
}

void loop() {
  bopit->update_state();  
}