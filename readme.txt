# A Simple Showcase for IoT and Augmented Reality

This project is a very simple full-stack showcase to explain all the steps and technologies to build an augmented reality IoT application. The showcase consiste of the following two elements:
1. A Servo moving from left to right and back in en endless loop. 
2. A tablet app that shows the real device (servo)

## Architecture

Level 1 : Devices with Embedded Control
The physical System, consiting of a Serveo with postion Feedback and an Arduino control.
The embedded software with a simple controller, that controls the movement and tracks the position. 
A serial interface to send and recieve data.

Level 2 : Webserver on Device
A second CPU on the device (on board of the Ardunino You, but in our lab often seperately on a rasperry PI) receives the data from the control and provices a websocket interface to connect to the internet.

Level 3 : IoT Cloud
A Platform (in our case node-red) that connects to all devices and provides an interface to the app on the tablet

Level 4 : Application
The app on the tablet (on our case build on unity with Vuforia towards iOS)


## Authors Remarks

Default Credentials for Arduino are set to rool:walle