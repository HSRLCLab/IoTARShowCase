#include <Rotator.h>

Rotator::Rotator(uint8_t pServo, uint8_t pFeedback) {
  //servo.attach(pServo);
  this->pServo = pServo;
  this->pFeedback = pFeedback;
  pos = 0;
  direction = 1;
  stepSize = 10;
  step = 0;
  calibmin = 0;
  calibmax = 0;
};

void Rotator::start() {
  servo.attach(pServo);
};

void Rotator::stop() {
  servo.detach();
};

// Read the real postion from Servo
int Rotator::getPosition() {
  int a = analogRead(pFeedback);
  int deg = map(a, calibmin, calibmax, 0, 180);
  return deg;
};

// Move one step
bool Rotator::loop() {
  if (servo.attached()) {
    if (step == stepSize) {
      pos += direction;
      servo.write(pos);
      step = 0;
      if (pos == 0 || pos == 180) {
        if (pos == 0) {
          calibmin = analogRead(pFeedback);
        } else {
          calibmax = analogRead(pFeedback);
        }
        direction = direction * -1;
      }
    }
    step++;
  }
  return true;
};
