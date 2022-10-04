 #include "Wire.h"
 #include <MPU6050_light.h>
 MPU6050 mpu(Wire);
#define motor1pin1 11
#define motor1pin2 8
#define motor2pin1 4 
#define motor2pin2 2
void setup() {
Wire.begin();
mpu.begin();
mpu.calcOffsets();
pinMode(motor1pin1, OUTPUT);
pinMode(motor1pin2, OUTPUT);
pinMode(motor2pin1, OUTPUT);
pinMode(motor2pin2, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
map;
}

void loop() {
digitalWrite(11, LOW);
digitalWrite(8, HIGH);
digitalWrite(4, HIGH);
digitalWrite(2, LOW);
analogWrite(9, 255);
analogWrite(10, 255);
  mpu.update();
float angle  = mpu.getAngleZ();
  int correction = analogRead(0);
 correction = map(angle, 0, 180, 255, 0);
 Serial.println(angle); 
 if (angle > 91) {
analogWrite(10, correction); //slow down right
}
 else if (angle < 89) {
analogWrite(9, correction); //slow down left
}
else {
analogWrite(9, 255);
analogWrite(10,255);
}
  
}
