/*programa emisor para arduino con conexion thingspeak lectura de sensores por serial 1 y envio por serial 3 y enviar medicones cada 15 segundos*/
//-----activacion de los puertos de comunicacion------------
HardwareSerial &pc        = Serial;
HardwareSerial &xbee      = Serial3;
//---variables del programa---
String Recepcion="";
boolean flagRequest=0;
char c;
//-----tiempo---
int intervalo = 100;
int ciclo = 5000;
//----declaracion array---
int miArray[6];//numero de variables a medir 
//---- humedad temperatura pin 4 ------- 
#include "DHT.h"
#define DHTPIN 4     // Pin donde está conectado el sensor
//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22
DHT dht(DHTPIN, DHTTYPE);
int h;
int t;
//-------paquete matematica------
#include <math.h> 
//---------definicon de puertos de entrada arduino SENSORes
#define MQ7 0//Definimos el pin de entrada
#define MQ8 1
#define MQ131 2
#define MQ135 3
//-variables de los sensores
 float PPM_C0;
 float PPM_H2;
 int PPBO3; 
 float PPM_CO2;
 
void setup() {
  Serial.begin(9600); 
  Serial3.begin(9600);
  delay(300);
}
void loop() { 
    int h = dht.readHumidity(); //Leemos la Humedad
    int t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
    int f = dht.readTemperature(true);
     Serial3.print(h);Serial3.println("Z ");
     Serial3.print(t);Serial3.println("z");
  sensor_mq7();//monoxido de carbono
  sensor_mq8();//hidrogeno
  sensor_mq131();//ozono
  sensor_mq135(); //dioxido de carbono
  //impresion de valores para envio por seria3.print
 // Serial.print(PPM_C0);Serial3.println("z");//mc: es monoxido de carbono
 // Serial.print(PPM_H2);Serial3.println("z");//h: es hidrogeno
 //Serial3.print(PPBO3);
 //Serial3.println("ozono");//o: es ozono
 //Serial.print(PPM_CO2);Serial3.println("z");//dc: es dioxido de carbono
  delay(ciclo);
}
 //----sensor monoxido de carbono----------------- -
    void sensor_mq7(){ 
      const float R0MQ7 = 5.3858; //resistencia en aire limpio del sensor mq7.
      float a =  3.288688549324245;
      float b = -3.921567161065982;
      float c = -0.7013185659637325;
      float sensorValueMQ7;
      float sensor_voltMQ7;
      float RS_gasMQ7;
      float ratioMQ7;
      float ppmQ7;
     
 
      sensorValueMQ7 = analogRead(A0);
      sensor_voltMQ7= sensorValueMQ7/1024*5.0;
      RS_gasMQ7 = (5.0-sensor_voltMQ7)/sensor_voltMQ7; // omit *RL
      /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
      ratioMQ7 = RS_gasMQ7/R0MQ7; // ratio = RS/R0, R0MQ7=5.3858
      ppmQ7= exp(a+ b/ratioMQ7 + c * log (ratioMQ7));
      
      //------TEMPERATURA--------------
      float h = dht.readHumidity(); //Leemos la Humedad
      float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
      float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  
     //------COMPENSACION POR TEMPERATURA Y HUMEDAD----
     if (h >=60){    
     float a =  0.4717253536;
     float b = -1.1609521558;
     float c = -0.1884305413;
     float comp;
     float PPM_C0;
     
     comp = exp(a+ b/t + c * log (t));
     PPM_C0 = ppmQ7 + comp;
     int CO;
     CO = (int)PPM_C0;
    Serial3.print(CO); Serial3.println("z");
     }
      else if(h <= 59){
      float a =  0.6463108533;
      float b = -1.4420883750;
      float c = -0.1904948863;
      float comp;
      float PPM_C0; 
     
      comp = exp(a+ b/t + c * log (t));
      PPM_C0 = ppmQ7 + comp;
      int CO;
      CO = (int)PPM_C0;
      Serial3.print(CO); Serial3.println("z");
    }   
 }
     //-----------SENSOR GAS MQ8 hidrogeno------------ 
    void sensor_mq8(){

      const float R0MQ8 = 3.9568; //resistencia en aire limpio del sensor mq8.
      float a = 6.989573031774370;
      float b = -00.3382186113564376;
      float c = -0.6624358680688767;
      float sensorValueMQ8;
      float sensor_voltMQ8;
      float RS_gasMQ8;
      float ratioMQ8;
      float ppmQ8;
  
      sensorValueMQ8 = analogRead(A1);
      sensor_voltMQ8= sensorValueMQ8/1024*5.0;
      RS_gasMQ8 = (5.0-sensor_voltMQ8)/sensor_voltMQ8; // omit *RL
      /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
      ratioMQ8 = RS_gasMQ8/R0MQ8; // ratio = RS/R0, R0MQ8
      ppmQ8= exp(a+ b/ratioMQ8 + c * log (ratioMQ8));
      
      //------TEMPERATURA--------------
      float h = dht.readHumidity(); //Leemos la Humedad
      float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
      float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
      //------COMPENSACION POR TEMPERATURA Y HUMEDAD----
      if (h >=60){    
      float a = -0.401905965326;
      float b =  1.834252209401;
      float c =  0.049151057636;
      float comp;
      float PPM_H2;
    
     comp = exp(a+ b/t + c * log (t));
     PPM_H2 = ppmQ8 + comp;
      int H2;
      H2 = (int)PPM_H2;
      Serial3.print(H2); Serial3.println("z");
     }
      else if(h <= 59){
      float a = -0.27679855739;
      float b =  1.62658498677;
      float c =  0.02944895012;
      float comp;
      float PPM_H2;
      
      comp = exp(a+ b/t + c * log (t));
      PPM_H2 = ppmQ8 + comp;
      int H2;
      H2 = (int)PPM_H2;
      Serial3.print(H2); Serial3.println("z");
      }
  }
  //-----------ozono---------------
  void sensor_mq131(){
{
int sensormq131 = analogRead(A2);
int PPBO3=(0.6479*sensormq131)-521;
Serial3.print(PPBO3);Serial3.println("z");
}
  } 
  //---------------dioxido de carbono-------------
   void sensor_mq135(){
      const float R0MQ135=4.2982; //resistencia en aire limpio
      float a = 8.112093710363418;
      float b = -3.246601407528687;
      float c = -5.577729718734205;
      float sensorValueMQ135;
      float sensor_voltMQ135;
      float RS_gasMQ135;
      float ratioMQ135;
      float ppmQ135;
   
      sensorValueMQ135 = analogRead(A3);
      sensor_voltMQ135= sensorValueMQ135/1024*5.0;
      RS_gasMQ135 = (5.0-sensor_voltMQ135)/sensor_voltMQ135; // omit *RL
      /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
      ratioMQ135 = RS_gasMQ135/R0MQ135; // ratio = RS/R0, R0MQ8
      ppmQ135= exp(a+ b/ratioMQ135 + c * log (ratioMQ135));
      
      //------TEMPERATURA--------------
      float h = dht.readHumidity(); //Leemos la Humedad
      float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
      float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
      //------COMPENSACION POR TEMPERATURA Y HUMEDAD----
      if (h >=60){    
      float a =  0.092060978684;
      float b =  1.390088106409;
      float c = -0.084380853248;
      float comp;
      float PPM_CO2;
     
     comp = exp(a+ b/t + c * log (t));
     PPM_CO2= ppmQ135 + comp;
      int CO2;
     CO2 = (int)PPM_CO2;
      Serial3.print(CO2); Serial3.println("z");
     }
      else if(h <= 59){
      float a = -0.181113650231;
      float b =  2.923421389066;
      float c =  0.012302879906;
      float comp;
      float PPM_CO2;
      comp = exp(a+ b/t + c * log (t));
      PPM_CO2 = ppmQ135 + comp;
       int CO2;
     CO2 = (int)PPM_CO2;
      Serial3.print(CO2); Serial3.println("z");
   }
 }
  

