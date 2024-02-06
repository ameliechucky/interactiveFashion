//ixfashion week 3
#include <FastLED.h>
//number of leds in your strip
#define NUM_LEDS 24
// pin where you connected your neopixels (digital pin)
#define DATA_PIN 9
// Define the number of leds in your stripe
CRGB leds[NUM_LEDS];

// analog sensor
int sensorPin = A2;

void setup() {
  //neopixels set up
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
void loop() {
  FastLED.clear();
  //read the sensor value
  int sensorValue = analogRead(sensorPin);
  //map the values
  int ledsOn = map(sensorValue, 0, 1023, 1, NUM_LEDS);
  // hue value depending on the sensor value
  int h = map(sensorValue, 0, 1023, 0, 255);
  // Turn on a number of LEDs on according to the values from the sensor
  for (int i = 0; i < ledsOn; i++) {
    // leds[i] = CRGB::White;
    leds[i] = CHSV(h, 255, 50);
  }
  FastLED.show();
  //print the sensor values in the serial monitor
  Serial.println(sensorValue);
}
