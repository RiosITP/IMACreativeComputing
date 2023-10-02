int fsr;
int led = 2;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  fsr = analogRead(A0);
  brightness = map(fsr, 0, 990, 0, 255);
  //brightness = map(fsr, 0,990,255,0);
  analogWrite(led, brightness);
}
