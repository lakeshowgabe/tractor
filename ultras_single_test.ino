#define motor1pin1  11 //in1 to arduino
#define motor1pin2  8 //in2 to arduino 

#define motor2pin1  4 //in3 to arduino
#define motor2pin2 3 //in4 to arduino

#define trigPin 5 //trigger pyn for ultra sensor
#define echoPin 6 //echo pin 
long duration; //long val for calculating the time it takes for 
//the sensor to get a reading on a onject adn its distance 
float distance;
int stopdist;

byte STOPP = HIGH;


void setup() {

  pinMode(motor1pin1, OUTPUT); // set pinmode to output 
  pinMode(motor1pin2, OUTPUT); // for High - forward or Low - backward setting
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); // set pin mode 9/10 to be used as speed control for each motor
  pinMode(10,OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an output
  pinMode(echoPin, INPUT); // Sets the echoPin as an input
  Serial.begin(9600); // Starts the serial communication for n seconds 
  // put your setup code here, to run once:

  digitalWrite(motor1pin1, LOW); // 
  digitalWrite(motor1pin2, HIGH);
  //delay(1000);

  digitalWrite(motor2pin1, HIGH); // 
  digitalWrite(motor2pin2, LOW);
}

void loop() {
  analogWrite(9,255);
  analogWrite(10,255);
  
 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //resets trigger pin 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, LOW); //reset again
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); //from the excho sent out will get a value
 
  distance = duration * 0.034 / 2; //forumla to calculate distabce in CM
  
  Serial.print("Distance:");
  Serial.println(distance); //println the distance...

  if (distance <= 20){

    digitalWrite(motor1pin1, LOW); // kill
    digitalWrite(motor1pin2, LOW);
  //delay(1000);

    digitalWrite(motor2pin1, LOW); //kill 
    digitalWrite(motor2pin2, LOW);
    
    }
  
}

   

  //analogWrite(9,255); //speed in left motor at 255..highest i think??
  //analogWrite(10,250); //slower test speed at 250..
  
     
 
//}
  // put your main code here, to run repeatedly:

    //if (stopdist == distance){ //if distace read is 20cm or less 
    //digitalWrite(motor1pin1, LOW); // kill
    //digitalWrite(motor1pin2, LOW);

    //digitalWrite(motor2pin1, LOW); // kill
    //digitalWrite(motor2pin2, LOW);
  //}
  //else {
