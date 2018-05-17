#include "ESP8266WiFi.h"  // WiFi Library
 

 
const char* ssid = "Projet-Micro";  // Name of WiFi Network
const char* password = "1234567890";  // Password of WiFi Network
 
int firstrun = 0;  // Check if system was just powered on
int buttonpressed = 5;  // To hold which button was pressed on Web Page
int relayPin=13; 
 
 
WiFiServer server(80);  // Definir le port du serveur web
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,LOW);
 
// Connecter au reseau Wifi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
// Wait until connected to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
 
// Confirmation de la connection Wifi
  Serial.println("");
  Serial.println("WiFi connected");
 
// Start the Web Server
  server.begin();
  Serial.println("Web Server Started");
 
// Display IP address
  Serial.print("You can connect to the Server here: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println();
  Serial.println(); 
} 
 
void loop() {
  
// Check if someone is connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
// Read which button was pressed on the Web Page
  String request = client.readStringUntil('\r');
 
// Light Up leds based on the button pressed 
  if (request.indexOf("/ON=1") != -1)  {
    digitalWrite(relayPin,HIGH);
    buttonpressed = LOW;
    firstrun=1;
  }
  if (request.indexOf("/OFF=0") != -1)  {
   digitalWrite(relayPin,LOW);
    buttonpressed = HIGH;
    firstrun=1;
  }
 
// Create Web Page
  client.println("HTTP/1.1 200 OK");  // HTML Header
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  
  client.println("<html>");  // Start of HTML
  
  client.println("<style>");
  client.println("body {background-color: #ACAEAD;}"); // Set Background Color
  client.println("</style>");
  
  if (firstrun == 0) {
    client.print("Please Click a Button ");
  }
  else {
    client.print("BULB ");
  }
 
  if(buttonpressed == LOW) {
    client.print("ON");
  } 
  if (buttonpressed == HIGH){
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/ON=1\"\"><button>ON</button></a>");
  client.println("<a href=\"/OFF=0\"\"><button>OFF</button></a><br />");  
  client.println("</html>"); 
  delay(10); 
 
}
