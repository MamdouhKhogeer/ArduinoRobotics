push # ArduinoRobotics
## Homework 1- 5/23/17

## Homework 2- 5/26/17
* I opened the AnalogRead example to read the numbers.
* I found that the numbers are under 400 when the sensor is blocked.
* I chose the perviuous Fade example as I found it easier to read and control because it's more organized.

## Homework 3- 5/31/17

## Homework 4- 6/02/17
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
* from what I understand from the tutorial is 1 means the switch is closed and 0 is open.
