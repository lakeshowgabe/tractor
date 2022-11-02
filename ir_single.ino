#include "Wire.h"
#include <MPU6050_light.h>
 MPU6050 mpu(Wire);

//#define emitterIR 5 //needs to be pwm 
//#define reciverIR 13

#define IR A0 
#define motor1pin1  11 //in1 to arduino
#define motor1pin2  8 //in2 to arduino 

#define motor2pin1  4 //in3 to arduino
#define motor2pin2 3 //in4 to arduino

int IRread;

boolean myBool = true;

boolean runOnce = false;
unsigned long timer = 0;


void setup() {



  pinMode(motor1pin1, OUTPUT); // set pinmode to output 
  pinMode(motor1pin2, OUTPUT); // for High - forward or Low - backward setting
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);

  digitalWrite(motor1pin1, HIGH); // 
  digitalWrite(motor1pin2, LOW);
  //delay(1000);

  digitalWrite(motor2pin1, LOW); // 
  digitalWrite(motor2pin2, HIGH);

  Serial.begin(9600); 
  Wire.begin();

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  //Serial.println("Done!\n");
  
  
}


void loop() {
  // put your main code here, to run repeatedly:

  //motorON();

  analogWrite(9,200);
  analogWrite(10,200);
  
  IRread = analogRead(IR); //set int var to value of analogread of A0 pin

  Serial.println(IRread);
  delay(500);

  mpu.update();
  
  if((millis()-timer)>10){ // print data every 10ms
  Serial.print("X : "); // not needed
  Serial.print(mpu.getAngleX()); // not needed
  Serial.print("\tY : ");// not needed
  Serial.print(mpu.getAngleY());// not needed
  Serial.print("\tZ : "); //get z angle aka YAW
  Serial.println(mpu.getAngleZ()); //print for verification 
  delay(500);
  timer = millis();  // set timer 
  }

  int yawAngle = mpu.getAngleZ(); //var to get use yaw angle as a float
  

  if (IRread <= 120){ //might need to change for in lab light conditions //60 for cardboard
 
      turnleft();
  }
  if (yawAngle >= 75){
        kill();
      }
  

}


void leftTurn(){
  


//  analogWrite(9,255);
//  analogWrite(10,255);

  int counter = 1;
  int turn_count = 2;
  
  if (counter = 1) {

    counter -= 1;
    
    digitalWrite(motor2pin1, HIGH); 
    digitalWrite(motor2pin2, LOW); //left turn 
    //if (yawAngle = -90){
      kill(); //stop turning
    }
  }
  


void motorON(){
  digitalWrite(motor1pin1, LOW); // keep motors running normally forward
  digitalWrite(motor1pin2, HIGH);
  //delay(1000);

  digitalWrite(motor2pin1, HIGH); // 
  digitalWrite(motor2pin2, LOW);
  
}



void turnleft(){
  digitalWrite(motor1pin1, LOW); // keep motors running normally forward
  digitalWrite(motor1pin2, LOW);
  //delay(1000);

  digitalWrite(motor2pin1, LOW); // 
  digitalWrite(motor2pin2, HIGH);
}

void kill(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
} 
