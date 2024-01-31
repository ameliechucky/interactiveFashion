//exercise 2 - Interactive Fashion
int speakerPin = 9; //0 if you are using ATtiny
int sensorPin = A3; // Analog pin 3 if you are using ATtiny
int sensorValue = 0;
int minValue = 50; //start playing at this value
int pitch = 10; //adjust pitch of the sound
void setup() {
  Serial.begin(9600); //Serial Comm doesn't work with ATtiny
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > minValue) {
    makeNoise(speakerPin, sensorValue * pitch, 100);
  }
  Serial.println(sensorValue);  //Serial Comm doesn't work with ATtiny
}

void makeNoise(unsigned char pin, int frequencyInHertz, long timeInMilliseconds) {
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 0.8));
  for (x = 0; x < loopTime; x++)
  {
    tone(pin, frequencyInHertz);
    delayMicroseconds(delayAmount);
    noTone(pin);
    delayMicroseconds(delayAmount);
  }
}
