//exercise 2 - Interactive Fashion
int speakerPin = 8; //0 if you are using ATtiny
int sensorPin = A0; // Analog pin 3 if you are using ATtiny
int sensorValue = 0;
int minValue = 500; //adjuts this accordingly

void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600); //Serial Comm doesn't work with ATtiny
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > minValue) {
    makeNoise(speakerPin, sensorValue * 3, 100);
  }
  Serial.println(sensorValue);  //Serial Comm doesn't work with ATtiny
}

void makeNoise(unsigned char pin, int frequencyInHertz, long timeInMilliseconds) {
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(pin, LOW);
    delayMicroseconds(delayAmount);
  }
}
