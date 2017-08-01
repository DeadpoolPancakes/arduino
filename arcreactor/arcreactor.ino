// bytes are half the size of int's, but restricted to a max value of 255
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

int brightness = 10;  
int fadeAmount = 5;
byte button;
byte oldbutton = 0;
byte buttonpin = 2;
byte state = 0;
const int ledPin = 13;
int i = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup()
{
 pinMode(buttonpin, INPUT);
 pinMode(ledPin, OUTPUT);
// initialize serial communication:
 Serial.begin(9600);
}

void loop()
{
 button = digitalRead(buttonpin);
 if(button && !oldbutton) // same as if(button == high && oldbutton == low)
 {
   //we have a new button press
   if(state == 0) // if the state is off, turn it on
   {
     //do stuff
     state = 1;
        strip.begin(); // This initializes the NeoPixel library.
        while  (i < 60){
        for(int i=0;i<NUMPIXELS;i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        
        strip.setPixelColor(i, strip.Color(0,0,255)); // Moderately bright green color.
        strip.show(); // This sends the updated pixel color to the hardware.
        brightness = brightness + fadeAmount;
        if (brightness <= 10 || brightness >= 250) {
        fadeAmount = -fadeAmount;
        }
        strip.setBrightness(brightness);
        delay(delayval); // Delay for a period of time (in milliseconds).
        i = i + 1;
        }
   }
   }
   else // if the state is on, turn it off
   {
     //do stuff
     state = 0; 
     i = 0;
     digitalWrite(ledPin, LOW);
   }
   oldbutton = 1;
 }
 else if(!button && oldbutton) // same as if(button == low && oldbutton == high)
 {
   // the button was released
   oldbutton = 0;
 };
 
}
