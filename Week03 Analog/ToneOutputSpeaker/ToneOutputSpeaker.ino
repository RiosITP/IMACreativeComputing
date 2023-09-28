int speaker = 8;
int pitch;
int fsrReading;

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
}

void loop() {
  fsrReading = analogRead(A0);
  pitch = map(fsrReading,0,990,260,1000);
  tone(speaker,pitch);   
  delay(300);
  noTone(speaker);
  delay(300);
}
