// digital pin 2 has a pushbutton attached to it, but i'm using pin 12 because
//pin 2 is used for the motor... not sure if it would work.
int pushButton = 10;

const int trigPin = 12;
const int echoPin = 9;


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);   // analog pin for reading the pushButton
  pinMode (2, OUTPUT);          // motor_1 polarity
  pinMode (4, OUTPUT);          // motor_1 polarity
  pinMode (6, OUTPUT);          // motor_1 speed control
  pinMode (7, OUTPUT);          // motor_2 polarity
  pinMode (8, OUTPUT);          // motor_2 polarity
  pinMode (11, OUTPUT);         // motor_2 speed control
  pinMode(trigPin, OUTPUT);     // distance sensor pin
  pinMode(echoPin, INPUT);      // distance sensor pin
}

void distanceSensor() {
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
  delay(500);

}

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
