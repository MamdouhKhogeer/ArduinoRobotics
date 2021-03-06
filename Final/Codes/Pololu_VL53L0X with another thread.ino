/* This example shows how to get single-shot range
  measurements from the VL53L0X. The sensor can optionally be
  configured with different ranging profiles, as described in
  the VL53L0X API user manual, to get better performance for
  a certain application. This code is based on the four
  "SingleRanging" examples in the VL53L0X API.

  The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;


// Uncomment this line to use long range mode. This
// increases the sensitivity of the sensor and extends its
// potential range, but increases the likelihood of getting
// an inaccurate reading because of reflections from objects
// other than the intended target. It works best in dark
// conditions.

//#define LONG_RANGE


// Uncomment ONE of these two lines to get
// - higher speed at the cost of lower accuracy OR
// - higher accuracy at the cost of lower speed

//#define HIGH_SPEED
#define HIGH_ACCURACY

//const int XSHDN_OF0X29  = 9;

//void setAddress(uint8_t new_addr)  //Changes the I²C slave device address of the VL53L0X to the given value (7-bit).

//uint8_t getAddress(void)  //Returns the current I²C address.

void setup()
{
  Serial.begin(9600);
  Wire.begin();


  pinMode(9, OUTPUT);
  digitalWrite(9, LOW); // Kill the device that will remain at the factory default address 0x29
  delay(100);
  sensor23.setAddress(0x23); // write the non-shutdown part with 0x23
  delay(10); // for good luck?
  digitalWrite(9, HIGH); // should now have two addresses on the I2C


  sensor23.init();
  sensor23.setTimeout(500);

  sensor29.init();
  sensor29.setTimeout(500);


#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor23.setSignalRateLimit(0.1);
  sensor29.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor23.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor23.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  sensor29.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor29.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor23.setMeasurementTimingBudget(20000);
  sensor29.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor23.setMeasurementTimingBudget(200000);
  sensor29.setMeasurementTimingBudget(200000);
#endif
}

void loop()
{
  Serial.print(sensor23.readRangeSingleMillimeters());
  Serial.print(sensor29.readRangeSingleMillimeters());
  if (sensor23.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  if (sensor29.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  Serial.println();
}
