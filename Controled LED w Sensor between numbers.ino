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
int brightness_1 = 0;    // how bright the LED is 
int fadeAmount_1 = 5;      // how many points to fade the LED by    

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);

  // set the brightness of pin 9:
  analogWrite(led_1, brightness_1);
  
  // change the brightness for next time through the loop:
  brightness_1 = brightness_1 + fadeAmount_1;

  // reverse the direction of the fading at the ends of the fade:
  if (analogRead(A0) <= 400) {
    brightness_1 = 0;
  }
  if (analogRead(A0) >= 800) {
    brightness_1 = 255;
  }
  if (400 < analogRead(A0) < 800) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}
