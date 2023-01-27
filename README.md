# PC Wake on WaN

The goal of this project is to enable the possibility to turn ON/OFF and monitor your PC power state over the internet (IoT), using a simple ESP8266 enabled device for cheap.

**This project is currently on a prototype phase. Only sketches and small simulations were made.**

# Info

The microcontroller board will be used to comunicate over the internet, using the ESP8266, with a phone app, which can be used to update the user of the current power state of their computer (ON or OFF) and push a signal to change the current power state (ON to OFF / OFF to ON).

The intention of the digital connections on the MC is to use an internal spare USB header to power the device, make use of the PWR IO pins to manipulate the power state (which can be mounted parallel to the physical power button on a PC case), and the PWR_LED+ IO pin (any available) to check the current power state.

Currently the form of connection from the ESP8266 to the app, and vice-versa, over the internet, is through a MQTT protocol.

# Project Sketches
## Materials used
* 1x Arduino board + ESP8266 module (from the following)
  - NodeMCU (used on this guide) **OR**;
  - Wemos D1 mini **OR**;
  - Any other version of arduino, be it a standalone MC or a full board w/ a ESP8266 module.
* 1x USB A micro male to Motherboard "DuPont" female USB header (use prefferable length)
* 3x Arduino "DuPont" male-female cables (use prefferable length)
* 1x Transistor NPN BJT 2N3904
* 1x 1k ohm resistor
* Subscription over https://console.hivemq.cloud/
* My app (avaliable later)

## Simple electric diagram
![image](https://user-images.githubusercontent.com/43782936/215001577-255c7d9d-ec74-45c5-bf5e-ae610282d3f6.png)

## Assembly projection
![image](https://user-images.githubusercontent.com/43782936/215001669-5ea5b947-7eeb-4f3a-bed5-342e83029a38.png)

This was reffering to a NodeMCU. The output and input digital ports can be customized on the code from the top variables.

![image](https://user-images.githubusercontent.com/43782936/215001743-b5dd8095-e434-48a2-a8f1-470cf8286c93.png)

# License

[MIT](https://opensource.org/licenses/MIT)
