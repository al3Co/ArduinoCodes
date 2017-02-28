#define VELOCIDAD 25000
int steps = 12; //conexión al arduino con el driver
int direccion = 9; //conexión al arduino con el driver
int reset = 10; //conexión al arduino con el driver
int pasos = 50; // 90ª = 50X1.8

int E_LimitSwitch = A4; //Entrada de limit al arduino
int E_SMetal = A5;  //Sensor inductivo

float SensorInductivState = 0.0;
float LimitSwitchState = 0.0;

int hayLata = 0;

void setup() {
  pinMode(steps, OUTPUT); 
  pinMode(direccion, OUTPUT); 
  pinMode(reset, OUTPUT);
  
  pinMode(E_LimitSwitch, INPUT);
  pinMode(E_SMetal, INPUT);
  Serial.begin(9600);
}

void loop() {
  LimitSwitchState = analogRead(E_LimitSwitch);
  Serial.print(" Switch: ");
  Serial.print(LimitSwitchState);
  if (LimitSwitchState >= 1020){
      hayLata = 1; //Calló la lata
      Serial.print(" hayLata: ");
      Serial.print(hayLata);
      delay(1000);
      SensorInductivState = analogRead(E_SMetal);
      Serial.print(" Sensor Metal: ");
      Serial.print(SensorInductivState);
    }
  if (hayLata == 1 && SensorInductivState > 150.0){
      gira_NoMetal();
      
    }
  else if(hayLata == 1 && SensorInductivState < 150.0){
      gira_Metal();
    }
  else if(hayLata == 0 ){
      Serial.println(" Pos Inicial");
    }
  hayLata = 0;
  delay(100);
}

void gira_Metal(){
    Serial.print(" gira a Metal ");
    digitalWrite(reset, LOW);    //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    delay(1000);
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, LOW);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {
      digitalWrite(steps, HIGH);  // This LOW to HIGH change is what creates the
      digitalWrite(steps, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
      delayMicroseconds(VELOCIDAD);     // Regula la velocidad, cuanto mas bajo mas velocidad.
    } 
    digitalWrite(reset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    delay(2000); //Regresa al punto inicial
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
    delay(1000);
    digitalWrite(reset, HIGH);   //Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
    digitalWrite(direccion, HIGH);
    for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
    {
      digitalWrite(steps, HIGH);  // This LOW to HIGH change is what creates the
      digitalWrite(steps, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
      delayMicroseconds(VELOCIDAD);     // Regula la velocidad, cuanto mas bajo mas velocidad.
    } 
    digitalWrite(reset, LOW);   //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
    delay(2000);//Regresa al punto inicial
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
