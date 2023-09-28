int fsrReading = 0;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {

  fsrReading = analogRead(A0);

  brightness = map(fsrReading, 0, 990, 0, 255);

  analogWrite(2, brightness);  // 0 - 255

  Serial.print("Pressure sensor: ");
  Serial.print(fsrReading);  // range is 790 - 130

  Serial.print("  Brightness: ");
  Serial.println(brightness);  //
}
