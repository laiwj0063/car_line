int right_In1 =9;
int right_In2 =8; 
int right_pwm = 5;
int left_In3 =7;
int left_In4 =6;
int left_pwm = 3;
int right_sensor = 10;
int mid_sensor = 11;
int left_sensor = 12;
int mode = 1;

int right_speed = 117;
int left_speed = 99;
#include <SoftwareSerial.h>
#include <Wire.h>
// int pin1 = 5;	//LED
char moterstatus;
SoftwareSerial BT(2,4);//RX,TX角位
//定義Arduino PIN2及PIN4分別為RX及TX腳

#include <Servo.h>
Servo myservo;
int pos =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);

  
  BT.begin(9600); // 設定和 HC-06 通訊的速度 (預設 9600)
  // pinMode(pin1, OUTPUT);

  //myservo.attach(10);
}

void moveForward2(){
  digitalWrite(left_In3,HIGH);
  digitalWrite(left_In4,LOW);
  analogWrite(left_pwm,left_speed);
  digitalWrite(right_In2,HIGH);
  digitalWrite(right_In1,LOW);
  analogWrite(right_pwm,right_speed);
  delay(80);
  stop();
}
void moveBackward(){
  digitalWrite(left_In3,LOW);
  digitalWrite(left_In4,HIGH);
  analogWrite(left_pwm,left_speed);
  digitalWrite(right_In2,LOW);
  digitalWrite(right_In1,HIGH);
  analogWrite(right_pwm,right_speed);
  delay(130);
  stop();
}
void moveRight2(){
  digitalWrite(left_In3,HIGH);
  digitalWrite(left_In4,LOW);
  analogWrite(left_pwm,left_speed);
  digitalWrite(right_In2,LOW);
  digitalWrite(right_In1,LOW);
  delay(75);
  stop();
}
void moveLeft2(){
  digitalWrite(left_In3,LOW);
  digitalWrite(left_In4,LOW);
  digitalWrite(right_In2,HIGH);
  digitalWrite(right_In1,LOW);
  analogWrite(right_pwm,right_speed);
  delay(75);
  stop();
}
void moveRight(){
  digitalWrite(left_In3,HIGH);
  digitalWrite(left_In4,LOW);
  analogWrite(left_pwm,left_speed);
  digitalWrite(right_In2,LOW);
  digitalWrite(right_In1,LOW);
  delay(145);
  stop();
}
void moveLeft(){
  digitalWrite(left_In3,LOW);
  digitalWrite(left_In4,LOW);
  digitalWrite(right_In2,HIGH);
  digitalWrite(right_In1,LOW);
  analogWrite(right_pwm,right_speed);
  delay(145);
  stop();
}
void moveForward(){
  digitalWrite(left_In3,HIGH);
  digitalWrite(left_In4,LOW);
  analogWrite(left_pwm,left_speed);
  digitalWrite(right_In2,HIGH);
  digitalWrite(right_In1,LOW);
  analogWrite(right_pwm,right_speed);
  delay(200);
  stop();
}
void stop(){
  digitalWrite(left_In3,LOW);
  digitalWrite(left_In4,LOW);
  digitalWrite(right_In2,LOW);
  digitalWrite(right_In1,LOW);
  delay(150);
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);
  if(mode==1){
    /*Serial.print("digital read from pin11 is:");
    Serial.println(digitalRead(12));*/
 
    if(digitalRead(right_sensor)==1&&digitalRead(mid_sensor)==0&&digitalRead(left_sensor)==1){
      moveForward2();
    }
    if(digitalRead(right_sensor)==1&&digitalRead(mid_sensor)==1&&digitalRead(left_sensor)==1){
      moveRight2();
      if(digitalRead(right_sensor)==1&&digitalRead(mid_sensor)==1&&digitalRead(left_sensor)==1){
        moveLeft2();
      }
    }
    if(digitalRead(right_sensor)==0&&digitalRead(left_sensor)==1){
      moveRight();
    }
    if(digitalRead(right_sensor)==1&&digitalRead(left_sensor)==0){
      moveLeft();
    }
    if(digitalRead(right_sensor)==0&&digitalRead(left_sensor)==0){
      stop();
      mode = 2;
    }
    if(digitalRead(mid_sensor)==0&&digitalRead(left_sensor)==0){
      stop();
      mode = 2;
    }
    if(digitalRead(right_sensor)==0&&digitalRead(mid_sensor)==0){
      stop();
      mode = 2;
    }
  }

  if(mode == 2){
    if (BT.available()){
      moterstatus=BT.read();
      Serial.println(moterstatus); 
    }
//判斷LED開關條件
    switch (moterstatus){ 
      case 'F':
      // digitalWrite(pin1,HIGH);
      Serial.println(moterstatus);
      moveForward();
      break;
      case 'L':
      // digitalWrite(pin1,LOW);
      Serial.println(moterstatus);
      moveLeft();
      break;
      case 'R':
      // digitalWrite(pin1,LOW);
      Serial.println(moterstatus);
      moveRight();
      break;
      case 'B':
      // digitalWrite(pin1,LOW);
      Serial.println(moterstatus);
      moveBackward();
      break;
      case 'T':
      // digitalWrite(pin1,HIGH);
      Serial.println(moterstatus);
      moveRight2();
      moveLeft2();
      break;
      case 'S':
      // digitalWrite(pin1,HIGH);
      Serial.println(moterstatus);
      moveLeft2();
      break;
      case 'C':
      // digitalWrite(pin1,HIGH);
      Serial.println(moterstatus);
      moveRight2();
      break;
    }
  }
}
