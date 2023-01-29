# PC Wake on WaN (IoT)

The goal of this project is to enable the possibility to turn ON/OFF and monitor your PC power state over the internet (IoT), using a simple ESP8266 enabled device for cheap.

**This project is currently on a prototype phase. Only sketches and small simulations were made.**

# Info

The microcontroller (MC) board is used to comunicate over the internet, using a ESP8266, to a phone app which can be used to update the user of the current power state of their computer (ON or OFF) and push a signal to change its current power state (ON to OFF / OFF to ON) remotely.

The intention of the digital connections on the MC is to make use of the PWR IO pins to manipulate the power state (which can be mounted parallel to the physical power button on a PC case), and the PWR_LED+ IO pin (any available) to check the current power state.

The board will be powered using an internal motherboard spare USB header. If this is not an option, it can be circumvented by routing a cable from any external USB ports (either from the computer itself or an external power supply) or supplying any sort of 5~12V to the connectors.

Currently the form of connection from the ESP8266 to the app, and vice-versa, over the internet, is through a MQTT protocol. Since its advised for the user to create and setup their own connections, only those with the connection strings/keys will be able to "control" your PC over the internet.

# Project Sketches
## Materials used
* 1x Arduino board + ESP8266 module (from the following)
  - NodeMCU (used on this guide) **OR**;
  - Wemos D1 mini **OR**;
  - Any other version of arduino, be it a standalone MC or a full board w/ a ESP8266 module.
* Code on this repo
* 1x USB A micro male to Motherboard "DuPont" female USB header (use prefferable length)
* 3x Arduino "DuPont" male-female cables (use prefferable length)
* 1x Transistor NPN BJT 2N3904
* 1x 1k ohm resistor
* Subscription over a MQTT broker (such as https://console.hivemq.cloud/ or https://test.mosquitto.org/)
* My app (available later)

## Simple electric diagram
![electrical](https://user-images.githubusercontent.com/43782936/215306770-68f22943-b282-425f-b307-58f1ca4b225f.png)

## Assembly projection
![physical_wiring_diagram](https://user-images.githubusercontent.com/43782936/215306830-afaeb133-cea3-4384-8475-0c226ba700f1.png)

This was reffering to a NodeMCU. The output and input digital ports can be customized on the code from the top variables.

![image](https://user-images.githubusercontent.com/43782936/215001743-b5dd8095-e434-48a2-a8f1-470cf8286c93.png)

# License

[MIT](https://opensource.org/licenses/MIT)
