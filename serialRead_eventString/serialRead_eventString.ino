/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.

 http://www.arduino.cc/en/Tutorial/SerialEvent

 code EDITED

 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    // print on Serial Monitor what you have recived
    Serial.println(inputString);
    // call function recived
    recived();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void recived(){
        if (inputString == "turnOnLed"){
            //do something when inputString equals turnOnLed
             turnOnLed();    // call function to turn on the led 13
          }
        else if(inputString == "turnOffLed"){
            //do something when inputString equals turnOffLed
            turnOffLed();   // call function to turn off the led 13
          }
        else{
            // if nothing else matches, do the default
          }
  }

void turnOnLed(){
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }

void turnOffLed(){
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  }
