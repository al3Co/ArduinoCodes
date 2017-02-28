
#include <LiquidCrystal.h>
#include <IRremote.h>

int RECV_PIN = 9;
int valor;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Press button");
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    valor = results.value, DEC;
    switch (valor) {
    case 12495:
      impr();
      lcd.print("Button 1");
      break;
    case 6375:
      impr();
      lcd.print("Button 2");
      break;
    case 31365:
      impr();
      lcd.print("Button 3");
      break;
    case -1:
      impr();
      lcd.print("Button Hold");
      break;
    default: 
      impr();
      lcd.print(valor);
      lcd.setCursor(8, 1);
      lcd.print("value");
      break;
    }
    irrecv.resume();
  }
  delay(350);
}

void impr(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Control Code");
    lcd.setCursor(1, 1);
    Serial.println(valor);
}


