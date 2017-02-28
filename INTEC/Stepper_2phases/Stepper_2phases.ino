/* LucidTronix Control a stepper motor.
 * For instructions details and schematic, See:
 * http://www.lucidtronix.com/tutorials/24
 */
#include <Stepper.h>
// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to:
Stepper stepper(STEPS, 2,3);

int btn1 = 4;
int pot_pin = 0;
int mode = 0;
int num_modes = 2;
int cur_pos = 100;
unsigned long last_press = 0;

void setup()
{
    // set the speed of the motor to 30 RPMs
    stepper.setSpeed(30);
    pinMode(btn1, INPUT);
}

void loop()
{
  if (mode == 0 ) speed_control();
  else if (mode == 1) phase_control();
  //check_buttons();
}

void check_buttons(){
  if (digitalRead(btn1) == HIGH  && millis() - last_press  > 500){
    mode = ++mode % num_modes; 
    last_press = millis();
    stepper.setSpeed(30);
  }
}

void speed_control(){
  int val = analogRead(pot_pin);
  val -= 512;
  val /= 5;
  stepper.setSpeed(abs(val));
  int step_amount = 0;
  if ( val > 0) step_amount = 1;
  else if ( val < 0) step_amount = -1;
  stepper.step(step_amount); 
}

void phase_control(){
  int val = analogRead(pot_pin);
  int degree = map(val,0,1023,0,200);
  int step_amount = 0;
  if (cur_pos < degree  && cur_pos < 200) step_amount = 1;
  else if(cur_pos > degree && cur_pos > 0) step_amount = -1;
  stepper.step(step_amount); 
  cur_pos += step_amount; 
}

