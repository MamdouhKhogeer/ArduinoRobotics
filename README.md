      push # ArduinoRobotics
## Homework 1- 5/23/17

## Homework 2- 5/26/17
* I opened the AnalogRead example to read the numbers.
* I found that the numbers are under 400 when the sensor is blocked.
* I chose the perviuous Fade example as I found it easier to read and control because it's more organized.

## Homework 3- 5/31/17

## Homework 4- 6/02/17
### PushButton:
* at first after i did the "pushButton" circut, i plugged it in pin 12 instead of 2 as 2 is already used by one of the motoros
* the "DigitalReadSerial" says that "digital pin 2 has a pushbutton attached to it" does it mean that there is a pre-programmed pushbutton in pin 2?
```Javascript
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 12;
```

* from what I understand from the tutorial is 1 means the switch is closed and 0 is open.
* I uplaoded "DigitalReadSerial" to Arduino to check if pin 12 would work from the reader, and it worked. But it showed "1" without "0". which seemed for me that it's always on and won't turns off. Also i didn't need to push the button to turn it on.
* i plugged it to pin 2 to see if it would change, but it performed the same with on and off. Infact, I removed the pin 2 then Ground and 5V, and it showed the same thing.
* UPDATE, in the reading, i noticed there are some 0s like "11101111001111011100" only in the beggening then it's always 1s.
* i copied "DigitalReadingSerial" to the motors script:
  * ```int pushButton = 12;``` before Void Setup
  * ```Serial.begin(9600); pinMode(pushButton, INPUT);``` in Void Setup to anable pin 12 and the serial begin
  * ```int buttonState = digitalRead(pushButton); Serial.println(buttonState); delay(100); ``` in Void Loope so the button can be read and        then printed every 100, so i can check if the switch is on or off.
* Unfortunatly the button is not working as expected because the reading is always 1 without pushing the button.
### Motor
* the script for the motor is summarized in pinModes, digitalWright and analogWright to control motor's polarity and speed.
```Javascript 
void setup() {

  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT); // put your setup code here, to run once:
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (11, OUTPUT);
}

void loop() {
  
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    analogWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, LOW);
    analogWrite (11, HIGH);
    delay(1000);
    digitalWrite (6, LOW);
    digitalWrite (11, LOW);
    delay(2000);
    digitalWrite (2, LOW);
    digitalWrite (4, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (11, HIGH);
    delay(3000);
    digitalWrite (6, LOW);
    digitalWrite (11, LOW);
    delay(1000);
  
}
```
* i'm having an experience of sometimes the motor respond to the program and work fine, and then it doesn't respond as expected. For example, in low speed sometimes the motor work and other times not. The other thing is with spinning the other side, sometimes it respond to that and other times not.
* i believe that there might be a problem with the circuit as when i removed the analog pin 6 the motor started to spin the other way. analog 6 anabled the motor to stop but it doesn't allow it to turn the other way.
* i had two motors working before, but now only one is owrking.

## Homework 5- 6/05/17

* i used the same script from before with changing the motor motion sequance.
* i tried to make a distnace function so i can return it when it's neccessary, but i couldn't figure out how to return the function in the loop.
`

* i decided to include it void loop() in order for it to function.
* i also had a problem of the place of distance script as when to read, before or after the robot move forward.
* i had to place it in the end because of "if" and "else" statement, but that made the robot turn when it get close to an obstacle then move a little bit forward then turn again instead of turning all the way till the obstacle not there anymore
```Javascript
void loop() {

  // the digitalRead is to read the pushButton state 1=on 0=off.
  int buttonState = digitalRead(pushButton);

  // printIn is to check digitalRead outcomes every 1 milliseconds.
  Serial.println(buttonState);
  delay(1);

  // if statement buttonState, so when the button is pushed the motor start working.
  if (buttonState == 0) {
    Serial.println("stop");
    digitalWrite (6, LOW);
    digitalWrite (11, LOW);
  } else while (buttonState == 1) {

      // the robot move forward
      Serial.println("fORWARD");

      digitalWrite (2, HIGH);
      digitalWrite (4, LOW);
      analogWrite (6, 255);
      digitalWrite (7, HIGH);
      digitalWrite (8, LOW);
      analogWrite (11, 255);
      delay(1000);

      long duration, distance;

      // Distance sensor pulse seting from Michael Shiloh file
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2); // low for 2 microseconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // high for 10 microseconds
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);

      distance = (duration / 2) / 29.1;

      if (distance >= 200 || distance <= 0) {
        Serial.println("Out of range; reading invalid");
      } else {
        Serial.print(distance);
        Serial.println(" cm");
      }

      // when the robot is close to an obstacle withint distance X it turns around
      // for a count of 5
      if  (distance <= 6) {
        for (int count = 0; count < 5; count = count + 1) {

          // one motor is working and the other is stopped
          digitalWrite (2, LOW);
          digitalWrite (4, LOW);
          analogWrite (6, 255);
          digitalWrite (7, HIGH);
          digitalWrite (8, LOW);
          analogWrite (11, 255);
          Serial.println("Turn Around");
          delay(500);
        }
      }
    }
}
```
