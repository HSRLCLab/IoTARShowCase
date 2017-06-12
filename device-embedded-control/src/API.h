#ifndef API_h
#define API_h

#include <Arduino.h>
#include <patterns/SerialAPI.h>
#include <Rotator.h>

/*
  Implementation of SerialAPI
*/

class API : public SerialAPI
{
  public:
    API(HardwareSerial *iSerialCom, Rotator *iRotator);
    void handleSerialInstruction(String task, String value);

  private:
    Rotator *rotator;
};

#endif
