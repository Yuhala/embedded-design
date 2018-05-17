# Arduino-Projects
This repository contains a list of 3 arduino projects I did some time ago. All projects are concerned with controlling devices remotely using an Arduino microcontroller. 

1-In the first project, we use the arduino to control a light bulb over BlueTooth.
2-In the second project, we use the arduino to control the light bulb with a remote control.
3-In the third project, we control the light bulb this time around over wifi using a laptop.

## Prerequisites

To follow this tutorial you would need to install the Arduino IDE on your machine and have sufficient knowledge about programming Arduino boards. An Arduino Uno was used for this project but other boards should produce similar results. 

## Important Components
The different projects were carried out with the help of an Arduino development kit which comes with many components. However, some each project required some important additional components. We list these below:

- An Arduino Bluetooth module \

<img src="https://1abxf1rh6g01lhm2riyrt55k-wpengine.netdna-ssl.com/wp-content/uploads/make-images/T11ETWOOA4peEdBY.jpg" width="250">
2- A Remote Control \
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQOWtYSiqOPK0aAa2Ha7-TJrHOSwPGSt-NP1sPLUHClQsWXkKZUwQ" width="250">

3- A nodemcu esp8266 wifi module \

<img src="http://www.microsolution.com.pk/wp-content/uploads/2017/12/Node-MCU.jpg" width="250">

### Installing Docker
First, add the GPG key for the official Docker repository to the system:

```
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

```
Add the Docker repository to APT sources:

```
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

```
Update the package database with the Docker packages from the newly added repo:

```
sudo apt-get update

```
Install Docker

```
sudo apt-get install -y docker-ce

```

### Tests

To test if the elasticsearch service is up and running, enter the below link in your browser.

```
http://localhost:9200
```

## Built With

* [ELK Stack](https://www.elastic.co/webinars/introduction-elk-stack) - A powerful open-source log management platform


## Authors

* **Peterson Yuhala** 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

