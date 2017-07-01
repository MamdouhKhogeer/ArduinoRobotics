
// most of the files and classes are made by others (Adafruit and Pololu)
// the classes, files and setups are by them. I only composed them together
// to control the motors with the sensors.

// Adafruit motorShield files.
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);



// Pololu VL53L0X Files
#include <Wire.h>
#include <VL53L0X.h>
// Using VL52L0X class to define two sensors.
VL53L0X sensor23;
VL53L0X sensor29;

// Uncomment ONE of these two lines to get
// - higher speed at the cost of lower accuracy OR
// - higher accuracy at the cost of lower speed

//#define HIGH_SPEED
//#define HIGH_ACCURACY


void setup() {
  // The motors and the sensors are using 9600 bps instead of 115200 that was
  // used by adafruit sensor. Now both of them are used together because they're reading 9600.
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  //i don't understand the difference between them.

  pinMode(9, OUTPUT);  // pin for the shutdown
  digitalWrite(9, LOW); // Kill the device that will remain at the factory default address 0x29 (pololu)
  delay(100);
  sensor23.setAddress(0x23); // write the non-shutdown part with 0x23 (pololu)
  delay(10); // for good luck?
  digitalWrite(9, HIGH); // should now have two addresses on the I2C (pololu)

  sensor23.init();
  sensor23.setTimeout(500);

  sensor29.init();
  sensor29.setTimeout(500);

  // setup the two motors to move near the 0,0 point at the begning.

}

void loop() {
  // put your main code here, to run repeatedly:

}
