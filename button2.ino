#define rightMotor1 4
#define rightMotor2 5
#define button 7

byte lastButtonState;
byte rightMotor1State = LOW; // off
byte rightMotor2State = LOW; // off i think..byte value to mean that motors are off
          //maybe change this to on idk

void setup() {
    pinMode(rightMotor1,OUTPUT);
    pinMode(rightMotor2,OUTPUT);

    pinMode(button, INPUT);
    lastButtonState = digitalRead(button);

}

void loop() {
    byte buttonState = digitalRead(button);
    if (buttonState != lastButtonState) { 
        lastButtonState = buttonState;
        if (buttonState == LOW) { //when button is pressed
            if (rightMotor1State == LOW & rightMotor2State == LOW){ //if motor is off..i think
                rightMotor1State = HIGH; //this sets values to turn it on for the byte values
                rightMotor2State = LOW;
            }
            else {
                rightMotor1State = LOW;
                rightMotor2State = LOW; //maybe HIGH but i think its else..turn it back off if button is pressed again, i think
            }
            digitalWrite(rightMotor1,rightMotor1State);
            digitalWrite(rightMotor2,rightMotor2State); //then digital write w the byte values to turn on the motors
            //i forgot how you wired it initially but hopefully this code works idk

        }
    }
}
