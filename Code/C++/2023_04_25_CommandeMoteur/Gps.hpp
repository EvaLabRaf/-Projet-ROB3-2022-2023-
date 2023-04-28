#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"

class Gps {
  public:
    Gps();
    void loop();
    float latitude();
    float longitude();

  private:
    static const int RXPin = 2, TXPin = 3;
    static const uint32_t GPSBaud = 9600;
    TinyGPSPlus gps;
    SoftwareSerial ss;
    void smartDelay(unsigned long ms);
    void printFloat(float val, bool valid, int len, int prec);
};

#endif
