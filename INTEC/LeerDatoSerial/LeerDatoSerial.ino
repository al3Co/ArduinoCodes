int retardo=5;          // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 0;   // Valor en grados donde se encuentra el motor
String leeCadena; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available()) {    // Leer el valor enviado por el Puerto serial
    delay(retardo);
    char c  = Serial.read();     // Lee los caracteres
    leeCadena += c;              // Convierte Caracteres a cadena de caracteres
  }  
  if (leeCadena.length()>0){       
        dato_rx = leeCadena.toInt();   // Convierte Cadena de caracteres a Enteros
         Serial.print(dato_rx);         // Envia valor en Grados 
         Serial.println(" Grados");
        delay(retardo);
        //dato_rx = (dato_rx * 1.4222222222); // Ajuste de 512 vueltas a los 360 grados
  }
  Serial.println(dato_rx);
}
