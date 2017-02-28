
int temporizador1 = 2000;
int temporizador2 = 500;
int temporizador3 = 1000;
int ledRojo = 12;
int ledAmarillo = 11;
int ledVerde = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(ledVerde, HIGH);
  delay(temporizador1);
  PrenderVerde();
  digitalWrite(ledAmarillo, HIGH);
  delay(temporizador3);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, HIGH);             
  delay(temporizador3);
  digitalWrite(ledRojo, LOW);
}

void PrenderVerde(){
    for(int i=0; i<4; i++){
      Serial.println(temporizador3, HEX);
      digitalWrite(ledVerde, HIGH);
      delay(temporizador2);
      digitalWrite(ledVerde, LOW);
      delay(temporizador2);
    }
}


  
