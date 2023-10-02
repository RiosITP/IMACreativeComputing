/*
Microphone Breakout Volume Detection
Takes analog readings from a an electret mic sensor and displays volume changes.
The sensor output is around 500 when quiet, then alternates high and low with louder sound.
This sketch takes a number of samples and averages the overall changes in amplitude, to give a rough volume.
IMA Creative Computing 2023
*/
int samples = 50;
int preading = 0;
int speaker = 9;

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
}

void loop() {
  int totalChange = 0;
  //use a for loop to take a small sample of readings
  //and average out the change from one reading to the next
  
  for (int i = 0; i < samples; i++) {
    // take reading
    int reading = analogRead(A0);
    // calculate absolute difference from last reading to get "amplitude"
    int amp = abs(reading - preading);
    //add to overall change
    totalChange += amp;
    // update previous reading
    preading = reading;
  }
  //average the changes by the number of samples
  int volume = totalChange/ samples;
  // visualize in serial monitor or plotter
  Serial.println(volume);
}
