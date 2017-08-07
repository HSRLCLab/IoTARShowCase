# Install on Arudino Yun

## Setup of NodeJS on an Arduino Yum

Follow this tutorial: http://andysigler.com/teaching/nodejs-arduino-yun/
Relevant (mandatory) steps:

  * Update the Yun’s image
  * Expand disk space with SD card
  * Install Node and node-modules with opkg
  * Disable Bridge on the Yun


## Setup of Webserver

Since npm is not running properly on the Arduino Yun (needs to much resources). To properly install ws and serialport use opkg:

```
opkg install node-ws
opkg install node-serialport
```

Then copy serial.js to:
```
sda1/arduino/socket/serial.js
```

## Run serial.js as a bootable service

Add the following line to /etc/rc.local:

```# start the node.js applicaiton to enable websocket to serial bridge
node /mnt/sda1/arduino/socket/serial.js```


Stop webserver with kill command (kill the nodejs service, too).