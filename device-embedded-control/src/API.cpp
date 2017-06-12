

#include <API.h>

API::API(HardwareSerial *iSerialCom, Rotator *iRotator) : SerialAPI(iSerialCom) {
  rotator = iRotator;
  serialCom->begin(9600);
};

void API::handleSerialInstruction(String task, String value) {
   String msg = "{ action: " + task + ", value : " + value + " }";

   if (task == "start") {
     rotator->start();
   }

   if (task == "stop") {
     rotator->stop();
   }

   if (task == "getState") {

   }
   //DEBUG PRINT
   serialCom->println(msg);

}
