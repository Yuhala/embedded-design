/*
Contrôle à distance via Télécommande
Par Peterson Yuhala
Version 1.0
 */ 
 
 /*CODES HEXADECIMAL DU TELECOMMANDE
 MODE: 371A3C86
 OFF: A32AB931
 TIMER: E0984BB6
 SWING: 39D41DC6
 LIGHT: 4EA240AE
 ON/SPEED: 143226DB
 
 */

#include <IRremote.h> //Ce librairie doit etre téléchargé
const int RECV_PIN = 11;//Broche signal du recepteur IR
const int relayPin = 3;//Broche du relai 5V
IRrecv irrecv(RECV_PIN);//Cree un objet serial sur la broche signal. Cet objet va recevoir les messages serials envoyés
decode_results results;
boolean on=true;
void setup()
{
  Serial.begin(9600); //
  irrecv.enableIRIn(); // Start the receiver
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,LOW);// L'ampoule est eteint au debut
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//Affiche la valeur HEX  du signal recu
   
    switch (results.value) {
      case 0x10C8E11E:    
        digitalWrite(relayPin,HIGH);
      break;
      case 0x10C831CE:    
        digitalWrite(relayPin,LOW);
      break;
      }
   
  
      irrecv.resume();     
       }
  // Receive the next value
  //delay(100); 
}
