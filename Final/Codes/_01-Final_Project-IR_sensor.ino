
// digital pin 2 has a pushbutton attached to it, but i'm using pin 12 because
//pin 2 is used for the motor... not sure if it would work.
int pushButton = 10;

const int ir_Sensor = A0;

const int mtr_1_p1 = 2;    // motor_1 polarity_1
const int mtr_1_p2 = 4;    // motor_1 polarity_2
const int mtr_1_spd = 6;   // motor_1 speed
const int mtr_2_p1 = 7;    // motor_1 polarity_1
const int mtr_2_p2 = 8;    // motor_1 polarity_2
const int mtr_2_spd = 11;  // motor_1 speed


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);    // analog pin for reading the pushButton
  pinMode (mtr_1_p1, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_p2, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_spd, OUTPUT);   // motor_1 speed control
  pinMode (mtr_2_p1, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_p2, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_spd, OUTPUT);   // motor_2 speed control
     // distance sensor pin
  pinMode(ir_Sensor, INPUT);       // distance sensor pin
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
    digitalWrite (mtr_1_spd, LOW);
    digitalWrite (mtr_2_spd, LOW);
  } else while (buttonState == 1) {

      long distance = getDistance();
      if (distance == -1) {
        Serial.print("something wrong");

      } else {
        Serial.print(distance);
        Serial.println(" cm");
      }

      // when the robot is close to an obstacle withint distance X it turns around
      if  (distance <= 6) {

        // one motor is working and the other is stopped
        turnAround();
        delay(500);

      } else {

        // the robot move forward
        forward();
        delay(1000);
      }
    }
}
