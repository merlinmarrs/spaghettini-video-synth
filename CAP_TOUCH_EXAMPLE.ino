#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
//#include <VGAX.h>

//VGAX vga;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(A4,10);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
    pinMode(2, OUTPUT);
        pinMode(5, OUTPUT); // PWR LED
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT); 
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    digitalWrite(5, HIGH); // PWR LED
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);


    //Serial.print(millis() - start);        // check on performance in milliseconds

    Serial.println(total1);                  // print sensor output 1

    delay(100);                             // arbitrary delay to limit data to serial port 

  if (total1 >50 && total1 <400) // turn on first led in first 1/3
  {
    digitalWrite(13, HIGH);
  }

   else if(total1 >=400 && total1 <700) // turn on second led in next 2/3
  {
    digitalWrite(12, HIGH);
  }

     else if(total1 >=700 && total1 <1000) // turn on third led in top 1/3
  {
    digitalWrite(11, HIGH);
  }
  else
  {
        digitalWrite(13, LOW);
       digitalWrite(12, LOW);
       digitalWrite(11, LOW);
  }
  
    
}
