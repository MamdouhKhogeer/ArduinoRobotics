/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int led_1 = 11;          // the PWM pin the LED is attached to
int led_2 = 9; 
int brightness_1 = 0;    // how bright the LED is
int brightness_2 = 100;  
int fadeAmount_1 = 5;      // how many points to fade the LED by
int fadeAmount_2 = 15;     
// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // set the brightness of pin 9:
  analogWrite(led_1, brightness_1);
  analogWrite(led_2, brightness_2);
  
  // change the brightness for next time through the loop:
  brightness_1 = brightness_1 + fadeAmount_1;
  brightness_2 = brightness_2 + fadeAmount_2;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness_1 <= 0 || brightness_1 >= 255) {
    fadeAmount_1 = -fadeAmount_1;
  }if (brightness_2 <= 0 || brightness_2 >= 255) {
    fadeAmount_2 = -fadeAmount_2;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
} 
