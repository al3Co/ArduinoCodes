#define VELOCIDAD 25000

int steps = 12;
int direccion = 9;
int reset = 10;
int pasos = 50;

void setup() {
  pinMode(steps, OUTPUT); 
  pinMode(direccion, OUTPUT); 
  pinMode(reset, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  gira_Metal();
  delay(3000);
  gira_NoMetal();
  delay(3000);
}

void gira_Metal(){
    Serial.print(" gira a Metal ");
    digitalWrite(reset, LOW);    //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, LOW);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {
      digitalWrite(steps, HIGH);  // This LOW to HIGH change is what creates the
      digitalWrite(steps, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
      delayMicroseconds(VELOCIDAD);     // Regula la velocidad, cuanto mas bajo mas velocidad.
    } 
    digitalWrite(reset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    delay(2000);
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, HIGH);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {  
      digitalWrite(steps, LOW);   // LOW to HIGH hace que el motor avance ya que da la orden
      digitalWrite(steps, HIGH);    // al A4988 de avanzar una vez por cada pulso de energia.
      delayMicroseconds(VELOCIDAD);         // Regula la velocidad, cuanto mas bajo mas velocidad.
    }
    digitalWrite(reset, LOW);
  }

void gira_NoMetal(){
    Serial.print(" gira a No Metal ");
    digitalWrite(reset, LOW);    //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, HIGH);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {
      digitalWrite(steps, HIGH);  // This LOW to HIGH change is what creates the
      digitalWrite(steps, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
      delayMicroseconds(VELOCIDAD);     // Regula la velocidad, cuanto mas bajo mas velocidad.
    } 
    digitalWrite(reset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    delay(2000);
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, LOW);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {  
      digitalWrite(steps, LOW);   // LOW to HIGH hace que el motor avance ya que da la orden
      digitalWrite(steps, HIGH);    // al A4988 de avanzar una vez por cada pulso de energia.
      delayMicroseconds(VELOCIDAD);         // Regula la velocidad, cuanto mas bajo mas velocidad.
    }
    digitalWrite(reset, LOW);
  }
