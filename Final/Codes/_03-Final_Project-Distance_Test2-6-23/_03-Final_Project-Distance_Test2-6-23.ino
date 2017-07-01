
//#include "Adafruit_VL53L0X.h"
//
//  Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int pushButton = 10;

const int irSensor = A0;

const int mtr_1_p1 = 2;    // motor_1 polarity_1
const int mtr_1_p2 = 4;    // motor_1 polarity_2
const int mtr_1_spd = 6;   // motor_1 speed
const int mtr_2_p1 = 7;    // motor_1 polarity_1
const int mtr_2_p2 = 8;    // motor_1 polarity_2
const int mtr_2_spd = 11;  // motor_1 speed


void setup() {

  distanceSensor();
  pinMode (pushButton, INPUT);
  pinMode (mtr_1_p1, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_p2, OUTPUT);    // motor_1 polarity
  pinMode (mtr_1_spd, OUTPUT);   // motor_1 speed control
  pinMode (mtr_2_p1, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_p2, OUTPUT);    // motor_2 polarity
  pinMode (mtr_2_spd, OUTPUT);   // motor_2 speed control
  pinMode(irSensor, INPUT);     // distance sensor pin

  //      Serial.begin(115200);
  //
  //    // wait until serial port opens for native USB devices
  //    while (! Serial) {
  //      delay(1);
  //    }
  //
  //    Serial.println("Adafruit VL53L0X test");
  //    if (!lox.begin()) {
  //      Serial.println(F("Failed to boot VL53L0X"));
  //      while (1);
  //    }
  //    // power
  //    Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
  //  }
}
void loop() {
  long distance ;
  //  int buttonState = digitalRead(pushButton);

  //  Serial.println(buttonState);
  //  delay(1);

  //  if (buttonState == 0) {
  //    digitalWrite (mtr_2_p1, LOW);
  //    digitalWrite (mtr_2_p2, LOW);
  //    analogWrite (mtr_2_spd, LOW);
  //
  //  } else while (buttonState == 1) {
  
  distance = getDistance();

  if (distance < 50 ) {
    Serial.println("Going Left");
    delay(1);
    digitalWrite (mtr_2_p1, HIGH);
    digitalWrite (mtr_2_p2, LOW);
    analogWrite (mtr_2_spd, 255);

  } else if (distance > 290) {
    Serial.println("Going Right");
    delay(1);
    digitalWrite (mtr_2_p1, LOW);
    digitalWrite (mtr_2_p2, HIGH);
    analogWrite (mtr_2_spd, 255);
  } else {
    Serial.println("middle");
  }
}


