void setup() {
  pinMode(2, INPUT); // connected to a button
  pinMode(3, OUTPUT); // led 1
  pinMode(4, OUTPUT); // led 2
  Serial.begin(9600);
}

void loop() {

  int button;// variable to hold button value
  button = digitalRead(2); //stoe digital reading in the button variable
  Serial.println(button); // print out the reading

// if the button is pressed....
// turn led 1 OFF and led 2 ON
  if (button == 1 ) {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }
// if the button is not pressed....
// turn led 1 ON and led 2 OFF
  if (button == 0 ) {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  }
}
