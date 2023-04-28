#include "Gps.h"

Gps::Gps(int rxPin, int txPin, uint32_t baudRate) : _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate), _ss(rxPin, txPin) {}

void Gps::begin() {
  Serial.begin(9600);
  _ss.begin(_baudRate);
  Serial.println(F("Latitude   Longitude"));
  Serial.println(F("(deg)      (deg)    "));
  Serial.println(F("--------------------"));
}

void Gps::update() {
  while (_ss.available()) {
    _gps.encode(_ss.read());
  }
}

float Gps::getLatitude() {
  return _gps.location.lat();
}

float Gps::getLongitude() {
  return _gps.location.lng();
}

bool Gps::isDataValid() {
  return _gps.location.isValid();
}

void Gps::smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (_ss.available()) {
      _gps.encode(_ss.read());
    }
  } while (millis() - start < ms);
}

