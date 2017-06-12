
#ifndef Rotator_h
#define Rotator_h

#include <Arduino.h>
#include <Servo.h>


// CAREFUL: STAY IN RANGE
// Range of Micro servo Tower Pro SG90: 200-1000
// Range of FITEC FS5106B: (180)200-550(570) = 180

// Define Arm as Class to instantiate a left and a right arm


#define SERVOMIN   0
#define SERVOMAX  100


class Rotator
{
  public:
    Rotator(uint8_t pServo, uint8_t pFeedback);
    void start();
    void stop();
    int getPosition();
    bool loop ();
  private:
    uint8_t pServo;
    uint8_t pFeedback;
    Servo servo;
    int pos;
    int direction;
    int step;
    int stepSize;
    int calibmin;
    int calibmax;
};

#endif
