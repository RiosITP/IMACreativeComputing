#include <Servo.h>
Servo motor;

int fsr;
int angle = 0;

void setup() {
  Serial.begin(9600);
  motor.attach(9);
}

void loop() {
  fsr = analogRead(A0);
  angle = map(fsr, 0, 990, 0, 179);
  motor.write(angle);
}
