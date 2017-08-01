int motors = 0;    // LED connected to digital pin 9
int rearLights = 4;
int motorLights = 1; 

void setup() {
  // nothing happens in setup

}

void loop() {

  for (int fadeValue = 50 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(rearLights, fadeValue);
    analogWrite(motorLights, fadeValue);
    analogWrite(motors, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 50; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(rearLights, fadeValue);
    analogWrite(motorLights, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  


}


