#include "Stepmotor.h"
Stepmotor motor(10, 11, 12, 13);

void setup() {
  
}

void loop() {
  motor.setStep(1);
  motor.setDirection(1);
  motor.setSpeed(10);
  motor.start();
}
