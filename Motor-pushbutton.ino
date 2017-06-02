// digital pin 2 has a pushbutton attached to it, but i'm using pin 12 because
//pin 2 is used for the motor... not sure if it would work.
int pushButton = 12;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);   // analog pin for reading the pushButton
  pinMode (2, OUTPUT);          // motor_1 polarity
  pinMode (4, OUTPUT);          // motor_1 polarity 
  pinMode (6, OUTPUT);          // motor_1 speed control
  pinMode (7, OUTPUT);          // motor_2 polarity
  pinMode (8, OUTPUT);          // motor_2 polarity
  pinMode (11, OUTPUT);         // motor_2 speed control
}

void loop() {

  // the digitalRead is to read the pushButton state 1=on 0=off.
  int buttonState = digitalRead(pushButton);

  // printIn is to check digitalRead outcomes every 1 milliseconds.
  Serial.println(buttonState);
  delay(1);

  // if statement buttonState, so when the button is pushed the motor start working.
  if (buttonState = 1) {
    
    // controling the voltage from polarity's pins for direction of the motor
    //digitalWrite (2, HIGH);
    //digitalWrite (4, LOW);
    //analogWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, LOW);
    analogWrite (11, HIGH);
    delay(1000);

    // stop the motor by lowering the speed
    digitalWrite (6, LOW);
    //digitalWrite (11, LOW);
    delay(2000);

    // changing the polarity to change the spinning direction of the motor
    //digitalWrite (2, LOW);
    //digitalWrite (4, HIGH);
    //digitalWrite (6, HIGH);
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (11, HIGH);

    //stop again
    delay(3000);
    digitalWrite (6, LOW);
    //digitalWrite (11, LOW);
    delay(1000);
  }
}
