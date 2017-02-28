#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 9;
const int redLed = 8;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocksMade = 0;
int maxNumberOfKnocks = 3;


void setup(){
    myServo.attach(5);
    pinMode(yellowLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(switchPin, INPUT);
    Serial.begin(9600);

    digitalWrite(greenLed, HIGH);
    myServo.write(0);
    Serial.println("La caja esta desbloqueada!");
}

void loop(){
    //Bloquear la puerta
    if(locked == false){
        switchVal = digitalRead(switchPin);
        if(switchVal == HIGH){
            locked = true;
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
            myServo.write(90);
            Serial.println("La caja esta bloqueada!");
            delay(1000);
        }
    }
    //Empieza a leer el piezoelectrico
    if(locked == true){
        knockVal = analogRead(piezo);
        
        if(numberOfKnocksMade < maxNumberOfKnocks && knockVal > 0){
            if(checkForKnock(knockVal) == true){
                numberOfKnocksMade++;
            }
            Serial.print("Golpes restantes: ");
            Serial.println(maxNumberOfKnocks-numberOfKnocksMade);
        }

        if(numberOfKnocksMade >= maxNumberOfKnocks){
            locked = false;
            myServo.write(0);
            delay(20);
            digitalWrite(greenLed, HIGH);
            digitalWrite(redLed, LOW);
            Serial.println("La caja esta desbloqueada");
        }
    }
}

boolean checkForKnock(int value){

  if(value > quietKnock && value < loudKnock){
        digitalWrite(yellowLed, HIGH);
        delay(50);
        digitalWrite(yellowLed, LOW);
        Serial.print("Valor del golpe correcto: ");
        Serial.println(value);
        return true;
  }
  else {
        Serial.print("Valor del golpe incorrecto: ");
        Serial.println(value);
        return false;
    }
}
   
