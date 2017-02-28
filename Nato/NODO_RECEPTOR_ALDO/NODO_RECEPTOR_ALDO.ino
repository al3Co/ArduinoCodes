// decl puertos com
HardwareSerial &pc    = Serial;
HardwareSerial &xbee  = Serial3;

// decl variables
String Recepcion = "";
boolean flagRequest = false;
char c;
#define cantidadSensores  6 // cantidad de sensores a medir [6]

// var tiempo
int intervalo = 100;
int ciclo = 15000;

// array
int miArray[cantidadSensores];

void setup() {
  Serial.begin(9600); 
  Serial3.begin(9600);
  delay(300);// tiempo de espera para acumulamiento de datos recibidos
}


void loop() {
  while (Serial3.available()){
    if(Serial3.available()>0){
      leerSensores();  
      mandarPuertoSerial();
      }
    }
  Serial3.flush();
  }

void leerSensores(){
  // leer todos los sensores
  for (int numeroSensor = 0; numeroSensor < cantidadSensores; numeroSensor++) {
    while(flagRequest == false){
      c = Serial3.read();
      Recepcion += c;
      if(c == 'z'){
        flagRequest = true;
        break;
        }
      }
    if(flagRequest){
      int valor = Recepcion.toInt();
      miArray[numeroSensor] = valor;
      flagRequest = false;
      Recepcion="";
      }
    delay(intervalo); // retraso = cilo + [(intervalo)*(cantidad de sensores)] = 15600
    }
  }

void mandarPuertoSerial(){
  // Envía datos de los sensores
  Serial.print(miArray[0]);Serial.println(',');// Serial.print("humedad")
  Serial.print(miArray[2]);Serial.println(',');//Serial.print("monoxido");
  Serial.print(miArray[3]);Serial.println(',');//Serial.print("hidrogeno");
  Serial.print(miArray[4]);Serial.println(',');// Serial.print("ozono");
  Serial.print(miArray[5]);Serial.println(',');// Serial.print("dioxido de carbono");
  Serial.print(miArray[1]);Serial.println(',');// Serial.print("temperatura");
  Serial.println(",,,,,,");
  delay(ciclo);// debe ser mayor de 15 segundos
  }





