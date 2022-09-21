#define Motor_PIN 8
#define BUTTON_PIN 7

int motor1pin1 = 2; //in1 to arduino
int motor1pin2 = 3; //in2 to arduino 

int motor2pin1 = 4; //in3 to arduino
int motor2pin2 = 5; //in4 to arduino

byte lastButtonState = LOW;
byte MotorState = LOW;


unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT); // set pinmode to output 
  pinMode(motor1pin2, OUTPUT); // for High - forward or Low - backward setting
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); // set pin mode 9/10 to be used as speed control for each motor
  pinMode(10,OUTPUT); // 9 is right motor
                      // 10 is for left motor ... vals up to 0-255

  pinMode(Motor_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

}

  
void loop() {


  // put your main code here, to run repeatedly:  
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        MotorState = (MotorState == HIGH) ? LOW: HIGH;
        digitalWrite(Motor_PIN, MotorState);


        analogWrite(9,255); //speed in left motor at 255..highest i think??
        analogWrite(10,250); //slower test speed at 250..but this is for the broken motor it did not run 
  
     
        digitalWrite(motor1pin1, HIGH); // forward
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, HIGH); // forward
        digitalWrite(motor2pin2, LOW);
        delay(7000); //run for 7 seconds..time can vary this is just a test value

        digitalWrite(motor1pin1, LOW); // rotate backward
        digitalWrite(motor1pin2, HIGH);

        digitalWrite(motor2pin1, LOW); // rotate backward
        digitalWrite(motor2pin2, HIGH);
        delay(1000); // for one second
      }
    }
  }
}
