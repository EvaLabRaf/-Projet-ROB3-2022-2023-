#include"Capteurdistance.hpp"

Capteurdistance cd;

void setup() {
  Serial.begin(9600);
  Serial.println("test setup");
  cd = Capteurdistance();
}

void loop() {
  Serial.println("test loop");
  Serial.println(cd.distance());
  delay(1000);
}
