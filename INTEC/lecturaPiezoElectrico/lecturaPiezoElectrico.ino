
const int pinLed   =  13;     // led conectado al pin digital 13
const int pinPiezo =  A0;    // piezo conectado al pin analogico  0
// declaramos una constante con el valor del umbral
const int umbral   = 100;    // valor umbral para detectar un golpe
// declaramos las variables para los valores de lectura y estdo del led
int lecturaSensor = 0;       // variable para gaurdar el valor del sensor
int estadoLed     = 0;       // variable pra guaradar el estado del led

void setup() {
   pinMode(pinLed, OUTPUT);   // inicializamos el pin del led como salida - OUTPUT
   Serial.begin(9600);        // inicializamos la comunicacion serial
}

void loop() {
   // leemos el valor del sensor en lecturaSensor
   lecturaSensor = analogRead(pinPiezo);
   lecturaSensor = (lecturaSensor - 1023) * (-1);
   Serial.print("Valor: ");    
   Serial.println(lecturaSensor);
   // si el valor del sensor es mayor que el umbral 
   if (lecturaSensor >= umbral) {
       // cambiamos el estado del led
       estadoLed = 1 - estadoLed;
       // y actualizamos la salida del pin del led        
       digitalWrite(pinLed, estadoLed);
       // Y mandamos un "Golpe!!" a la computadora por el serial
       Serial.print("Golpe!! valor: ");
       Serial.println(lecturaSensor);
       delay(1000);
     }
   delay(100);
}
