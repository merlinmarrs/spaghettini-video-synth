#include <VGAX.h>
#include <math.h>

VGAX vga;

// By Anna Offenwanger
// The dial determines how much of the screen is filled with the mixed color
// Pressing the button changes what color is being filled.

// This is the pin for the potentiometer
const int analogInPin = A5;
int sensorValue = 0;
int outputValue = 0;

// this is the button pin
const int buttonPin = 4;
int buttonState = 0;

void setup() {
  // start VGA
  vga.begin();
  // This is for this board specificly to put power on the potentiometer and the button
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);// PWR LED
  digitalWrite(5, HIGH);

  pinMode(13, OUTPUT); // SEL LEDs 1
  pinMode(12, OUTPUT); // SEL LEDs 2

      
  // this is to get input from the button
  pinMode(buttonPin, INPUT);
}

void loop() {
  // hack, turn on the 5V power :P
  digitalWrite(2, HIGH);



  // read from the potentio and the button
  sensorValue = analogRead(analogInPin);
  buttonState = digitalRead(buttonPin);

  // map the potentiometer value to the screen x axis
  outputValue = map(sensorValue, 0, 1023, 0, int(VGAX_WIDTH));

  // draw the potentiometer display at the top of the screen
  for (int i = 0; i < VGAX_WIDTH; i++) {
    if (i < outputValue) {
      vga.putpixel(i, 0, 3);
    } else {
      vga.putpixel(i, 0, 0);
    }
  }

  // draw random pixels
  int x = rand() % VGAX_WIDTH;
  int y = rand() % VGAX_HEIGHT;
  if (x < outputValue) {

    vga.putpixel(x, y, 3);
  } else {
    // check the button state to pick the color
    if (buttonState == HIGH) {
      digitalWrite(13, HIGH);
      vga.putpixel(x, y, 2);
    } else {
      digitalWrite(13, LOW);
      vga.putpixel(x, y, 1);
    }
  }
}
