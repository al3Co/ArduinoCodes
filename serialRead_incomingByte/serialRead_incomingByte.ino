// code to recive incoming data on byte and do something
// definitions and global variables
int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);    // initialize digital pin 13 as an output.
}

void loop() {
        // send data only when you receive data:
        if (Serial.available() > 0) {
            // read the incoming byte:
            incomingByte = Serial.read();
                 
            // call function recived
            recived();

            // print on Serial Monitor what you have recived
            Serial.print("I received: ");
            Serial.println(incomingByte, DEC);
        }
  }

void recived(){
        switch (incomingByte) {
          case 1:
              //do something when var equals 1
              turnOnLed();    // call function to turn on the led 13
              break;
          case 2:
              //do something when var equals 2
              turnOffLed();   // call function to turn off the led 13
              break;
          default: 
              // if nothing else matches, do the default
              // default is optional
          break;
        }
  }

void turnOnLed(){
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }

void turnOffLed(){
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  }
