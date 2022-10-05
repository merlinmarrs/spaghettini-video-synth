/*
By Anna Offenwanger 
*/

#include <VGAX.h>
#include <math.h>

VGAX vga;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  vga.begin();
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(5, HIGH);
}

void loop() {

  digitalWrite(2, HIGH);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    for (int i = 0; i < VGAX_WIDTH; i++) {
      for (int j = 0; j < VGAX_HEIGHT; j++) {
        vga.putpixel(i, j, 3);
      }
    }
  } else {
    // turn LED off:
    for (int i = 0; i < VGAX_WIDTH; i++) {
      vga.clear(0);
      vga.putpixel(i, 0, 1);
    }
  }
}
