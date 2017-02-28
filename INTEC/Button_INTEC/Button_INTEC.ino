#include <Servo.h>
Servo servo; 
const int pinPiezo = A0;
const int ledRojo = 8;
const int ledVerde = 9;
const int umbral   = 100;
int lecturaSensor = 0;
int estado_Puerta = 0;

void setup() {
  pinMode(pinPiezo, INPUT);
  servo.attach(5);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (estado_Puerta == 1){
    abrirPuerta();
    }
  else{
    funLecturaSensor();
    cerrarPuerta();
    }
  delay(100);
}

void funLecturaSensor(){
    lecturaSensor = analogRead(pinPiezo);
    lecturaSensor = (lecturaSensor - 1023) * (-1);
    //lecturaSensor = (((lecturaSensor * (1/1023)) -1) * 1023) * (-1);
//    Serial.print("Valor: ");
//    Serial.println(lecturaSensor);
    if (lecturaSensor >= umbral) {
          estado_Puerta = 1;
          Serial.print("Golpe!! valor: ");
          Serial.println(lecturaSensor);
      }
  }

void abrirPuerta(){
    digitalWrite(ledRojo, LOW);
    servo.write(0);
    digitalWrite(ledVerde, HIGH);
    delay(6000);
    for(int i = 0; i<=4; i++){
        digitalWrite(ledVerde, HIGH);
        delay(1000);
        digitalWrite(ledVerde, LOW);
        delay(1000);
      }
    estado_Puerta = 0;
    lecturaSensor = 0;
  }

void cerrarPuerta(){
    servo.write(90);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
  }
  
