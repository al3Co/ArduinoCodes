
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("Voltage: ");
  Serial.println(voltage);
  if(voltage > 4){
    digitalWrite(13, HIGH);
    Serial.print("PRENDO LED");
    }
   else{
    digitalWrite(13, LOW);
    Serial.print("APAGO LED");
    }
  delay(100);
}
