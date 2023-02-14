// IMA NYU Shanghai
// Interactive Fashion

/**
  This example is to send multiple values from an XBee to an Arduino (or Lilypad B).
 **/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#define NUM_OF_VALUES_FROM_XBEE 3    /** YOU MUST CHANGE THIS ACCORDING TO YOUR PROJECT **/


/** DO NOT REMOVE THESE **/
int tempValue = 0;
int valueIndex = 0;

/* This is the array of values storing the data from the XBee. */
int xbee_values[NUM_OF_VALUES_FROM_XBEE];


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  // example if you are using an LED
  // pinMode(13, OUTPUT);
}

void loop() {
  getSerialData();

  // add your code here using elements in the values array
  //this is an example connecting an LED to pin 13 and a buzzer to pin 8
  /*
    if (xbee_values[0] == 1) {
      //turn on an LED when a button is pressed. This button is connected to Lilypad A
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
    // map values from the sensor to frequency. This sensor is connected to Lilypad A
    //from (0 - 1023) to the output pitch range (120 - 1500Hz)
    int f = map(xbee_values[1], 0, 1023, 120, 1500);
    tone(8, xbee_values[1], 50);
    delay(10);        // delay in between reads for stability
  */
  //end of example

} //end of the loop function

//receive serial data from Processing
void getSerialData() {
  while (mySerial.available()) {
    char c = mySerial.read();
    //switch - case checks the value of the variable in the switch function
    //in this case, the char c, then runs one of the cases that fit the value of the variable
    //for more information, visit the reference page: https://www.arduino.cc/en/Reference/SwitchCase
    switch (c) {
      //if the char c from Processing is a number between 0 and 9
      case '0'...'9':
        //save the value of char c to tempValue
        //but simultaneously rearrange the existing values saved in tempValue
        //for the digits received through char c to remain coherent
        //if this does not make sense and would like to know more, send an email to me!
        tempValue = tempValue * 10 + c - '0';
        break;
      //if the char c from Processing is a comma
      //indicating that the following values of char c is for the next element in the values array
      case ',':
        xbee_values[valueIndex] = tempValue;
        //reset tempValue value
        tempValue = 0;
        //increment valuesIndex by 1
        valueIndex++;
        break;
      //if the char c from Processing is character 'n'
      //which signals that it is the end of data
      case '\n':
        //save the tempValue
        //this will b the last element in the values array
        xbee_values[valueIndex] = tempValue;
        Serial.println(tempValue);
        //reset tempValue and valueIndex values
        //to clear out the values array for the next round of readings from Processing
        tempValue = 0;
        valueIndex = 0;
        break;
    }
  }
}
