// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

int brightness = 10;  
int fadeAmount = 5;
boolean yeah = true;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int delayval = 100; // delay for half a second

void setup() {

}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  strip.begin(); // This initializes the NeoPixel library.
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
    
  }
}
