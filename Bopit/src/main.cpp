#include <Arduino.h>
#include <bopit.h>
#include <HardwareSerial.h>
#include <Arduino_GFX.h>
#include <SPI.h>

BopIt *bopit;

/* interrupt handlers */
void power_button_isr();


void setup() {

    Serial.begin(9600);
    while (!Serial);

    // construct
    bopit = new BopIt();

    // attach power button interrupt
    attachInterrupt(digitalPinToInterrupt(bopit->power_button.pin), power_button_isr, RISING);

    Serial.write("Setup Complete!\n");

}

void loop() {

    bopit->update_state();

}

/* interrupt handlers */
void power_button_isr() {
    bopit->power_button_pressed();
}