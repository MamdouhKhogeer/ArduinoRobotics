#define XSHDN_OF0X29  9 // for XSHDN of factory default sensor

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    pinMode(XSHDN_OF0X29, OUTPUT);
    digitalWrite(XSHDN_OF0X29, LOW); // Kill the device that will remain at the factory default address 0x29
    delay(100);
     sensor23.setAddress(0x23); // write the non-shutdown part with 0x23
    delay(10); // for good luck?
    digitalWrite(XSHDN_OF0X29, HIGH); // should now have two addresses on the I2C
  // Now initialize both of them
    sensor23.init();
    sensor23.setTimeout(500);
    sensor23.startContinuous();
   
    sensor29.init();
    sensor29.setTimeout(500);
    sensor29.startContinuous();
}
// i don't know why it is not working?!
