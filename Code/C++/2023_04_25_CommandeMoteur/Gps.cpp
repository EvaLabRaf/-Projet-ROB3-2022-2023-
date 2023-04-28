#include "Gps.hpp"

Gps::Gps() : ss(RXPin, TXPin) {}

void Gps::begin() {
  Serial.begin(9600);
  ss.begin(GPSBaud);
  Serial.println(F("Latitude   Longitude"));
  Serial.println(F("(deg)      (deg)    "));
  Serial.println(F("--------------------"));
}

void Gps::loop() {
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  Serial.println();
  smartDelay(1000);
  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
}

float Gps::latitude() {
  return gps.location.lat();
}

float Gps::longitude() {
  return gps.location.lng();
}

void Gps::smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

void Gps::printFloat(float val, bool valid, int len, int prec) {
  if (!valid) {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  } else {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1);  // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3
                           : vi >= 10  ? 2
                                       : 1;
    for (int i = flen; i < len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}
