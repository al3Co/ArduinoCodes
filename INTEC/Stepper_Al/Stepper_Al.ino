#include <Stepper.h>
// change this to the number of steps on your motor
#define STEPS 200
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to:
Stepper stepper(STEPS, 2,3);

int posNoMetal = 90;
int posMetal = -90;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("clockwise");
  stepper.step(200);
  delay(500);
  Serial.println("counterclockwise");
  stepper.step(200);
  delay(500);
}
