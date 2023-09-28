int counter = 0;
int pstate = 0;
int pitch = 500;

void setup() {
  pinMode(2, INPUT); // im connected to a button
  pinMode(3, OUTPUT); // led 1
  pinMode(4, OUTPUT); // led 2
  pinMode(5, OUTPUT); // led 3
  pinMode(9, OUTPUT); // spk
  Serial.begin(9600);
}

void loop() {
  int buttonstate;
  buttonstate = digitalRead(2);
  //Serial.println(buttonstate);

  if (buttonstate == 1 && pstate == 0) {
    counter++;
    pstate = 1;
    pitch = pitch + (counter * 100);
  }

  if (buttonstate == 0 && pstate == 1) {
    pstate = 0;
  }
  //Serial.println(counter);

  tone(9, pitch);
  delay(10);
  noTone(9);
}
