#ifndef Gps_h
#define Gps_h

#include "Arduino.h"
#include "TinyGPS++.h"
#include "SoftwareSerial.h"

class Gps {
  public:
    Gps(int rxPin, int txPin, uint32_t baudRate);
    void begin();
    void update();
    float getLatitude();
    float getLongitude();
    bool isDataValid();

  private:
    int _rxPin;
    int _txPin;
    uint32_t _baudRate;
    TinyGPSPlus _gps;
    SoftwareSerial _ss;
    unsigned long _lastUpdateTime;

    void smartDelay(unsigned long ms);
};

#endif
