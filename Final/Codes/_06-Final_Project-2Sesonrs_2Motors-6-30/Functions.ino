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


