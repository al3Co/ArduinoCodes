int sensorInfra = 8;
int valor = 0;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(sensorInfra, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  valor = digitalRead(sensorInfra);
  if (valor == LOW){
      digitalWrite(led, HIGH);
    }
  else{
      digitalWrite(led, LOW);
    }
  Serial.println(valor);
}
