# Final Project

## Project Discription
  The robot is a two axis printer that prints with a pen. the robot was extracted from an HP inkjet printer with a scanner.
  I took the printer apart to look for usefull parts inside of it. Then i found out that i could use the printer structure, motor mechanism, 
  and wires to make the robot.
  
## Easrly explorations & Research
  * At first, i wanted to make the two axis printer looks like an arm. I found out that the mechanism of this would be diffuclt to build as the class and the teacher agreed to that.
![img_0868 copy](https://github.com/MamdouhKhogeer/ArduinoRobotics/blob/master/Final/Research/590a65fe4c65ab0ffe659f8c861ea95a%5B1%5D.jpg)

  * Michelle Herrera (a classmate) shared with me some links of other simpler drawing robots. From these links i found other intriguing robots. For examples, using two DVD writers to build a small CNC machine https://www.youtube.com/watch?v=2VFOU-WUQIY&t=5s , a cardbaord 3 axis machine http://www.instructables.com/id/High-Precision-Cardboard-CNC-Drawing-Machine/, and a two axis machine https://www.youtube.com/watch?v=xnZI0ovzb4c
  
  * Most of these machines use stepper motors, a CNC shield, and a ready to use code. So it seemed to me if i addapted any of them, i would be bound by its boundries.
  * Later, I found the printer that i'm using its parts for the robot.
  
## Hardware
  ### Most of the mechanical parts are from the printer which inclueds:
  * two DC motors for X,Y axises.
  * Gears.
  * structure
  ### Other parts
  * Arduino
  * Breadbaord
  * Two VL53L0X measuring Sensors
  * AdaFruit Motor Shield

## Working Process
  ### 6/19
  * Used a previous motor with sensor code.
  * Adjusted the code to make it work with IR sensor instead of the sonar sensor.
  * removed the PushBotton from the code to make it simpler.
  * The IR sensor worked with the motor shown in the video.
  * The problem with IR sensor:
    * it reads from 10cm to 80cm (begins after half of the x axis).
    * the read between 0-10cm was different wich caused the axis to stuck.
    * It wasn't accurate enough, and the numbers change constantly.
  * I found another distance sensor which is more accurate and asked the professor about it (VL53L0X) and set the order.
  #### 6/22
  * one VL53L0X came after class.
  * as i couldn't work with the new sensor, i had to work with the Y-axis mechanically.
  ### 6/23
  * the day before the class i had to go and solder the VL53L0X to make it work.
  * It was the first time for me to solder headers to a microship.
  * i plugged the sensor to Arduino and followed the Adafruit tutorial.
  * the sensor didn't work, so i had to as Zoe for help.
  * She re-solder the sensor and we plugged it again to Arduino and it Worked!!
  ### 6/24
  * 
  
  

  
  
  

  
