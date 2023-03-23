#include <Wiegand.h>

Wiegand wiegand;

void setup() {
  Serial.begin(9600);
  wiegand.begin();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() == 26) {
      wiegand.sendCode(input);
      Serial.println("Wiegand data sent!");
    } else {
      Serial.println("Invalid Wiegand data!");
    }
  }
}
