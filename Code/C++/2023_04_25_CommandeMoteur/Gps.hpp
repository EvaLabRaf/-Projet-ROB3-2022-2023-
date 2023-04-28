#ifndef GPS_H
#define GPS_H
#include "Arduino.h"
#include "TinyGPS++.h"
#include "SoftwareSerial.h"

class Gps : public SoftwareSerial {
public:
  Gps();
  void smartDelay(unsigned long ms);
  static const int RXPin = 2;
  static const int TXPin = 3;
  
};

#endif