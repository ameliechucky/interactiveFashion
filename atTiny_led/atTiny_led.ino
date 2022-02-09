/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int maxValue = 700;
int minValue = 300;
int ledPin = 0; //// Pin 0 = ADC 0
int sensorPin = 3; // Pin 3 = ADC 3

// the setup routine runs once when you press reset:
void setup() {
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  int b = constrain(sensorValue, minValue, maxValue);
  b = map(b, minValue, maxValue, 255, 0);
  analogWrite(ledPin, b);
  //Serial.println(sensorValue);
}
