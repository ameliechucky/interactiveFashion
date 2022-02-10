/*
  Interactive Fashion, week 1
  Reads the analog input from a sensor and translates into digital PWM signal to turn on an LED
*/
int maxValue = 700;
int minValue = 300;
int ledPin = 0; //// Pin 0 = PWM
int sensorPin = 3; // Pin 3 = ADC 

// the setup routine runs once:
void setup() {
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600); //this works if you are using arduino
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  int b = constrain(sensorValue, minValue, maxValue);
  b = map(b, minValue, maxValue, 255, 0);
  analogWrite(ledPin, b);
  //Serial.println(sensorValue); //this works if you are using arduino
}
