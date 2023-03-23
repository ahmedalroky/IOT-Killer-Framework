#include <Wiegand.h>
#include <Random.h>

Wiegand wiegand;
Random random;

void setup() {
  Serial.begin(9600);
  wiegand.begin();
  randomSeed(analogRead(0));
}

void loop() {
  String data = "";
  int bitCount = random(10, 100);
  for (int i = 0; i < bitCount; i++) {
    data += String(random(0, 2));
  }
  wiegand.sendCode(data);
  Serial.print("Wiegand data sent: ");
  Serial.println(data);
  delay(500);
}
