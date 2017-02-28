//declaracion de puertos de comunicacion-----
HardwareSerial &pc        = Serial;
HardwareSerial &xbee      = Serial3;
//---variables del programa---
String Recepcion="";
boolean flagRequest=0;
char c;
//-----tiempo-------
int intervalo = 100;//tiempo para acumulamiento de datos,
int ciclo=15000;
//----declaracion array---------
int miArray[6];//cantidad de sensores a medir

void setup() {
  Serial.begin(9600); 
  Serial3.begin(9600);
  delay(300);//tiempo para acumulamiento de datos, 
}
void loop()
{ 
while (Serial3.available()){
 if(Serial3.available()>0)//si hay datos por el modulo
   { 
   humedad();//miArray[0]
   mq8();//hidro
   mq131();//ozo
   mq7();//mono
   mq135;//diox
   temperatura();
 Serial.print(miArray[0]);Serial.println(','); // Serial.print("humedad")
 Serial.print(miArray[2]);Serial.println(',');//Serial.print("monoxido");
 Serial.print(miArray[3]);Serial.println(',');//Serial.print("hidrogeno");
 Serial.print(miArray[4]);Serial.println(',');// Serial.print("ozono");
 Serial.print(miArray[5]);Serial.println(',');// Serial.print("dioxido de carbono");
 Serial.print(miArray[1]);Serial.println(',');// Serial.print("temperatura");
 Serial.println(",,,,,,");
 delay(ciclo);//debe ser mayor de 15 segundos
    }
  }
 
}
  //---------humedad----------------
  void humedad(){
  while(Serial3.available())//si hay datos por el modulo
  {
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
    break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[0]= valor;
    flagRequest=0;
    Recepcion="";
}
   delay(intervalo); //freq envío. 
}
//------------temperatura-------------
void temperatura(){
 while(Serial3.available())//si hay datos por el modulo 
 { 
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
     break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[1]= valor;
    flagRequest=0;
    Recepcion=""; 
     
  }
  delay(intervalo); //freq envío.
}

//---------------monoxido de carbono-----------
void mq7(){
  while(Serial3.available())//si hay datos por el modulo 
  { 
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
     break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[2]= valor;
    flagRequest=0;
    Recepcion="";
 }
  delay(intervalo); //freq envío.
}

 //---------------------------------------hidrogeno--------------
 void mq8(){
  while(Serial3.available())//si hay datos por el modulo 
  { 
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
     break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[3]= valor;
    flagRequest=0;
    Recepcion="";
     
 }
 delay(120); //freq envío.
 }
 
 //--------Ozono---------
 void mq131(){
  while(Serial3.available())//si hay datos por el modulo 
  { 
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
     break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[4]= valor;
    flagRequest=0;
    Recepcion="";
    
 }
  delay(intervalo); //freq envío.
 }
 //-------dioxido de carbono-------------
 void mq135(){
  while(Serial3.available())//si hay datos por el modulo 
  { 
    c=Serial3. read();
    Recepcion+=c;
    if(c=='z')//fin de trama
    {
     flagRequest=1;
     break; 
    }
  }//end while
  if(flagRequest==1)
  {
    int valor =Recepcion.toInt();
    miArray[5]= valor;
    flagRequest=0;
    Recepcion="";
   }
   delay(200); //freq envío.    
 }
 


