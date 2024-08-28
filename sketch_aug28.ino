#include "SystemControl.h"
SystemControl newSystem(26, 25, 33, 32, 12, 14);
void setup() {
  Serial.begin(9600);
}

void loop() {
  newSystem.checkDistance();
}