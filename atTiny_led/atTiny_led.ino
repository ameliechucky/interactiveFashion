/*
  Interactive Fashion, week 1
  Reads the analog input from a sensor and translates into digital PWM signal to turn on an LED
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
