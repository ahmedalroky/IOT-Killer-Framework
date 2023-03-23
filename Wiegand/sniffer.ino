#include <Wiegand.h>

Wiegand wiegand;

void setup() {
  Serial.begin(9600);
  wiegand.begin();
}

void loop() {
  if (wiegand.available()) {
    Serial.print("Wiegand data: ");
    Serial.println(wiegand.getCode());
  }
}
