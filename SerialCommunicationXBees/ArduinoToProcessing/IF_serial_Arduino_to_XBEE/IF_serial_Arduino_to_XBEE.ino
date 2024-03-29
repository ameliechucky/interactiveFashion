// IMA NYU Shanghai
// Interactive Fashion
// For sending multiple values from Arduino (Lilypad A) to XBEE
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);
}

void loop() {
  // to send values to an XBee assign the values you want to send
  //this is an example of sending 3 values
  int sensor1 = analogRead(A0);
  int sensor2 = analogRead(A1);
  int sensor3 = analogRead(A2);

  // send the values keeping this format
  mySerial.print(sensor1);
  mySerial.print(",");  // put comma between sensor values
  mySerial.print(sensor2);
  mySerial.print(",");  // put comma between sensor values
  mySerial.print(sensor3);
  mySerial.println(); // add linefeed after sending the last sensor value

  // too fast communication might cause some latency when we receive the values
  // this delay resolves the issue.
  delay(100);

  // end of example sending values
  //follow this format for the number of values you want to send
}
