// ixfashion week 3
#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 9
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN);

// analog sensor
int sensorPin = A2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.begin();
}

void loop() {
  //read the sensor value
  int sensorValue = analogRead(sensorPin);
  //map the values
  int ledsOn = map(sensorValue, 0, 1023, 1, NUMPIXELS);
  
  pixels.clear();  // Set all pixel colors to 'off'
  //turn on a number of LEDs on according to the values from the sensor
  for (int i = 0; i < ledsOn; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
    pixels.show();  // Send the updated pixel colors to the hardware.
  }
  Serial.println(sensorValue);
}
