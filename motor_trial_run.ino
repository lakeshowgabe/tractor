//main code for right now

#define motor1pin1  2 //in1 to arduino
#define motor1pin2  3 //in2 to arduino 

#define motor2pin1  4 //in3 to arduino
#define motor2pin2 5 //in4 to arduino

#define button 7 //define button
byte lastButtonState; //vvalue to be used to calculate last button state

byte motor1pin1State = LOW; //motor STATE values to be 
byte motor1pin2State = LOW; // used in place of HIGH or LOW
byte motor2pin1State = LOW; //set to low to begin
byte motor2pin2State = LOW;

#define trigPin 10 //trigger pyn for ultra sensor
#define echoPin 6 //echo pin 
long duration; //long val for calculating the time it takes for 
//the sensor to get a reading on a onject adn its distance 
int distance; //vars to be used to find distance for ultra sensor


void setup() {
  //define motor setup
  pinMode(motor1pin1, OUTPUT); // set pinmode to output 
  pinMode(motor1pin2, OUTPUT); // for High - forward or Low - backward setting
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); // set pin mode 9/10 to be used as speed control for each motor
  pinMode(10,OUTPUT); // 9 is right motor
                      // 10 is for left motor ... vals up to 0-255


  //define setup for button
  pinMode(button, INPUT); //assign button as an input
  lastButtonState = digitalRead(button); //gets state of last button press

  //define ultra setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an output
  pinMode(echoPin, INPUT); // Sets the echoPin as an input
  Serial.begin(9600); // Starts the serial communication for n seconds 

}

  
void loop() {
  
  byte buttonState = digitalRead(button); //gets button state from button being pressed
  if (buttonState != lastButtonState){ //updated the button state
    lastButtonState = buttonState;
    if (buttonState == LOW){ //if LOW, ie. pressed, 
      if (((motor1pin1State & motor1pin2State) == LOW) & ((motor2pin1State & motor2pin2State) == LOW)){
       //and if motor pin STATE values are also LOW 
        motor1pin1State = HIGH;
        motor1pin2State = LOW;
        //set state values to high which will be used for the digital Write later
        motor2pin1State = HIGH;
        motor2pin2State = LOW;
      }
      else{
        motor1pin1State = LOW;
        motor1pin2State = LOW;

        motor2pin1State = LOW; 
        motor2pin2State = LOW; //and when presed again kill motors
      }
      digitalWrite(motor1pin1, motor1pin1State);
      digitalWrite(motor1pin2, motor1pin2State);

      digitalWrite(motor2pin1, motor2pin1State);
      digitalWrite(motor2pin2, motor2pin2State);//use the motor state values we got 
      //to use them as the values for the digital write to turn on the motors
    }
    
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //resets trigger pin 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, LOW); //reset again
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); //from the excho sent out will get a value
  // Calculating the distance
  distance = duration * 0.034 / 2; //forumla to calculate distabce in CM

  if (distance <= 20){ //if distace read is 20cm or less 
    digitalWrite(motor1pin1, LOW); // kill
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW); // kill
    digitalWrite(motor2pin2, LOW);
  }
  else {
    Serial.println(distance); //println the distance...
  }

   

  //analogWrite(9,255); //speed in left motor at 255..highest i think??
  //analogWrite(10,250); //slower test speed at 250..
  
     
 
}

//repeats
// but for whatever reason it does not 
 //digitalWrite(motor1pin1, HIGH); // forward
  //digitalWrite(motor1pin2, LOW);

  //digitalWrite(motor2pin1, HIGH); // forward
  //digitalWrite(motor2pin2, LOW);
  //delay(7000); //run for 7 seconds..time can vary this is just a test value

  //digitalWrite(motor1pin1, LOW); // rotate backward
  //digitalWrite(motor1pin2, HIGH);

  //digitalWrite(motor2pin1, LOW); // rotate backward
  //digitalWrite(motor2pin2, HIGH);
  //delay(1000); // for one second