#include "Gps.hpp"

Gps::Gps(){};

void Gps::smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (available())
      encode(read());
  } while (millis() - start < ms);
}
