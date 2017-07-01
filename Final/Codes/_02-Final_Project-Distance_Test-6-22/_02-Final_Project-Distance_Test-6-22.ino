const int pushButton = 10;

const int irSensor = A0;

const int mtr_1_p1 = 2;    // motor_1 polarity_1
const int mtr_1_p2 = 4;    // motor_1 polarity_2
const int mtr_1_spd = 6;   // motor_1 speed
const int mtr_2_p1 = 7;    // motor_1 polarity_1
const int mtr_2_p2 = 8;    // motor_1 polarity_2
const int mtr_2_spd = 11;  // motor_1 speed


void setup() {
  Serial.begin(9600);
  pinMode (pushButton, INPUT);
  pinMode (mtr_1_p1, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_p2, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_spd, OUTPUT);   // motor_1 speed control
  pinMode (mtr_2_p1, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_p2, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_spd, OUTPUT);   // motor_2 speed control
  pinMode(irSensor, INPUT);     // distance sensor pin
}

void loop() {
  int distance = analogRead(irSensor);
  //  int buttonState = digitalRead(pushButton);

  //  Serial.println(buttonState);
  //  delay(1);

  //  if (buttonState == 0) {
  //    digitalWrite (mtr_2_p1, LOW);
  //    digitalWrite (mtr_2_p2, LOW);
  //    analogWrite (mtr_2_spd, LOW);
  //
  //  } else while (buttonState == 1) {

  if (distance < 70 ) {
    Serial.println("Going Left");
    delay(1);
    digitalWrite (mtr_2_p1, HIGH);
    digitalWrite (mtr_2_p2, LOW);
    analogWrite (mtr_2_spd, 255);

  } else if (distance > 550) {
    Serial.println("Going Right");
    delay(1);
    digitalWrite (mtr_2_p1, LOW);
    digitalWrite (mtr_2_p2, HIGH);
    analogWrite (mtr_2_spd, 255);
  } else {
    Serial.println("middle");
  }
}


