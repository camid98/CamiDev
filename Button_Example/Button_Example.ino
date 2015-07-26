/*

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
#define BUTTONPIN 10
#define rpin A2

void setup() {
  
  Serial.begin(9600);      // open the serial port at 9600 bps for Debug Output: 
  // initialize the LED pin as an output:
  pinMode(rpin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTONPIN, INPUT_PULLUP);
  
}

void loop() {
  Serial.println(digitalRead(BUTTONPIN), DEC);
  Serial.write("\n");
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (digitalRead(BUTTONPIN) == HIGH) {
    Serial.write("button is on");
    // turn LED on:
     analogWrite(rpin, 0);
  }
  else {
    // turn LED off:
    analogWrite(rpin, 255);
  }
}
