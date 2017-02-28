
#include <Servo.h> 
Servo myservo;

int posNoMetal = 180;
int posHome = 90;
int posMetal = 0;
int pos = 0;
int E_LimitSwitch = A4;
int E_SMetal = A5;

float SensorMetalState = 0.0;
float LimitSwitchState = 0.0;
int hayLata = 0;

void setup() {
  myservo.attach(9);
  pinMode(E_LimitSwitch, INPUT);
  pinMode(E_SMetal, INPUT);
  Serial.begin(9600);
}

void loop() {
  LimitSwitchState = analogRead(E_LimitSwitch);
  Serial.print(" Switch: ");
  Serial.print(LimitSwitchState);
  if (LimitSwitchState >= 1020){
      hayLata = 1; //Calló la lata
      Serial.print(" hayLata: ");
      Serial.print(hayLata);
      delay(500);
      SensorMetalState = analogRead(E_SMetal);
      Serial.print(" Sensor Metal: ");
      Serial.print(SensorMetalState);
    }
  if (hayLata == 1 && SensorMetalState > 200.0){
      gira_Metal();
      
    }
  else if(hayLata == 1 && SensorMetalState < 200.0){
      gira_NoMetal();
    }
  else if(hayLata == 0 ){
      myservo.write(posHome);
      Serial.print(" gira a pos Inicial ");
      pos = posHome;
    }
  hayLata = 0;
  Serial.print(" angulo: ");
  Serial.print(pos);
  Serial.println(". ");
  delay(100);
}

void gira_Metal(){
    Serial.print(" gira a Metal ");
//    for(pos = pos; pos <= posMetal; pos -= 1){
//        myservo.write(pos);
//        delay(15);
//      }
//    pos = posMetal; 
    //delay(1000);
    myservo.write(posMetal);
  }

void gira_NoMetal(){
  Serial.print(" gira a No Metal ");
//  for(pos = pos; pos <= posNoMetal; pos += 1){
//      myservo.write(pos);
//      delay(15);
//    }
//    pos = posNoMetal;
    //delay(1000);
    myservo.write(posNoMetal);
  }
