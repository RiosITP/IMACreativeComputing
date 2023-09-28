#include <Servo.h>
Servo servomotor;

int ang = 0;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  servomotor.attach(9); // servo
  pinMode(10, OUTPUT); // led
}

void loop() {
  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  int light = analogRead(A2);

  if (Serial.available() > 0) {
    
    int p5info = Serial.read();
   
    Serial.print(pot1);
    Serial.print(",");
    Serial.print(pot2);
    Serial.print(",");
    Serial.print(light);
    Serial.print(",");
    
    brightness = p5info;
    
    Serial.println(brightness);
  }
  //servomotor.write(ang);
  analogWrite(10, brightness);
}
