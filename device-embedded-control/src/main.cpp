#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <API.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Get Motors

// Define serial communication, Serial1 for arduino yun, Serial for others
HardwareSerial *serialCom = &Serial1;
Rotator *rotator;
API *api;
int i;

void setup() {
  // Create a Rotator and attach to pin 9
  i=0;
  uint8_t pFeedback = A0;
  rotator = new Rotator(9, pFeedback);
  api = new API(serialCom, rotator);
  yield();
}

void loop() {
  // Get clients coming from server
  api->loop();
  rotator->loop();
  if (i == 10) {
    int pos = rotator->getPosition();
    api->sendJSON("position", (String)pos);
    i = 0;
  }
  delay(1); // Poll every 10ms
  i++;
}
