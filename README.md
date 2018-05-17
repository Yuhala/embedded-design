# Arduino-Projects
This repository contains a list of 3 arduino projects I did some time ago. All projects are concerned with controlling devices remotely using an Arduino microcontroller. 

1- In the first project, we use the arduino to control an LED over BlueTooth. \
2- In the second project, we use the arduino to control the LED with a remote control. \
3- In the third project, we control the LED this time around over wifi using a laptop. 

## Prerequisites

To follow this tutorial you would need to install the Arduino IDE on your machine and have sufficient knowledge about programming Arduino boards. Install appropriate libraries for the remote control and nodemcu esp8266 wifi modules. An Arduino Uno was used for this project but other boards should produce similar results. 

## Important Components
The different projects were carried out with the help of an Arduino development kit which comes with many components. However, each project requires some important additional components. We list these below:

- An Arduino Bluetooth module 

<img src="https://1abxf1rh6g01lhm2riyrt55k-wpengine.netdna-ssl.com/wp-content/uploads/make-images/T11ETWOOA4peEdBY.jpg" width="250">
- A Remote Control 

<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQOWtYSiqOPK0aAa2Ha7-TJrHOSwPGSt-NP1sPLUHClQsWXkKZUwQ" width="250">

- A nodemcu esp8266 wifi module 

<img src="http://www.microsolution.com.pk/wp-content/uploads/2017/12/Node-MCU.jpg" width="250">

## Wiring up components
The complete wiring up of components is beyond the scope of this tutorial. I assume that you understand the basics of Arduino programming. The code for each project gives clues on how to wire up your different pins.

## Testing our programs
In order to test the programs on an Arduino board, you would have to tweak the code a little to adapt to your particular case. The following tweaks are needed for each project: 

### Arduino Remote Control
- In order to control equipment using our remote control, we need to know the hexadecimal codes produced by the buttons we wish to use. By using an IR sensor, we could print these codes to our serial output. The corresponding codes should be replaced in the [source code](remote-control.ino).

```
 switch (results.value) {
      case 0x10C8E11E:    
        digitalWrite(relayPin,HIGH);
      break;
      case 0x10C831CE:    
        digitalWrite(relayPin,LOW);
      break;
      }
```
- To test the code, compile and upload to the Arduino board. Press the corresponding buttons on the remote control and see how it goes...

### Arduino Wifi Control 
For controlling our LED over wifi, we first of all need to create a wifi hotspot. This can easily be done with a smartphone. The hotspot credentials in the code should be modified appropriately. 

```
const char* ssid = "Projet-Micro";  // Name of WiFi Network
const char* password = "1234567890";  // Password of WiFi Network

```
Compile and upload the program to your Nodemcu esp8266. After a successful connection to the network, the link to the web server created on your nodemcu will be printed on the serial monitor. Connect your PC to the same network and enter this link in your browser. You control the LED by clicking either the "ON" or "OFF" buttons on the web page.

### Arduino Bluetooth Control
- For controlling the LED over bluetooth, we need a device to send signals to our microcontroller over bluetooth; our smartphone is a good candidate. Download the [bluetooth control app](https://play.google.com/store/apps/details?id=appinventor.ai_hobbyprojects_com.BluetoothRoboControl) from google playstore and install on your smartphone. 

- Connect and pair your phone to your bluetooth module (Default code: 1234). To see the code corresponding to a button in the app, we click on the button and verify the code using our serial monitor in Arduino IDE. Modify the [source code](bluetooth-control.ino) appropriately. 
```
const char* ssid = "Projet-Micro";  // Name of WiFi Network
const char* password = "1234567890";  // Password of WiFi Network

```
- To test the program, compile and upload to your Arduino board and have fun...

## Built With

* [Arduino Kit](https://www.arduino.cc/) - Arduino is an open-source electronics platform based on easy-to-use hardware and software. 


## Authors

* **Peterson Yuhala** 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

