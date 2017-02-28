
int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);
}

void loop() {
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                //incomingByte = (incomingByte, DEC);
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
                digitalWrite(13, HIGH);
                delay(3000);
                digitalWrite(13, LOW);
        }
        if (incomingByte == 49){
            for (int i=0; i <= 5; i++){
                digitalWrite(13, HIGH);
                delay(1000);   
                digitalWrite(13, LOW);
                delay(1000);
            }
            Serial.print("I received: ");
            Serial.println(incomingByte);
            incomingByte = 0;
          }
         if (incomingByte == 50){
            for (int i=0; i <= 10; i++){
                digitalWrite(13, HIGH);
                delay(500);   
                digitalWrite(13, LOW);
                delay(500);
            }
            Serial.print("I received: ");
            Serial.println(incomingByte);
            incomingByte = 0;
          }
     delay(3000);
     Serial.print("I received: ");
     Serial.println(incomingByte); 
}
