/*Controlling an LED via Bluetooth
 *Created by Peterson Yuhala
 * 4GI,ENSP Yaounde
 */
#include <SoftwareSerial.h>
 
 int serialValue;  //contains the value received by the Bluetooth module
 
 const int txPin=10; //goes top bluetooth module TX pin
 const int rxPin=11; //connect to bluetooth module RX pin
 const int ledPin=7; //Connect your LED on this pin

 SoftwareSerial BT(txPin,rxPin); //Creates a serial object with the given transmission TX and reception pins RX

void setup() {
 
  
 //digitalWrite(relayPin,LOW);  
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW); 
  BT.begin(9600); //Transmission rate
 

}
  
void loop() {
  Serial.begin(9600);
  if(BT.available()){ //If there is serial information available, read it    
    serialValue=BT.read();
    Serial.println(serialValue); 
    
  }     
  switch (serialValue) {//UP:67 DOWN:68 LEFT:66 RIGHT:65 MID:69
      case 69:
        digitalWrite(ledPin,HIGH);
        break;
      case 65:
        digitalWrite(ledPin,LOW);
        break;      
  }
 
   delay(100);//This delay is very important! Do not remove; Helps return good serial values!!!
    
}
