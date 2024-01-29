#include "linecar.h"

#define RIGHT_IN1 9
#define RIGHT_IN2 8 
#define RIGHT_PWM 5
#define LEFT_IN3 7
#define LEFT_IN4 6
#define LEFT_PWM 3
#define RIGHT_SENSOR 10
#define MID_SENSOR 11
#define LEFT_SENSOR 12
#define RIGHT_SPEED 117
#define LEFT_SPEED 99
#define RX 2
#define TX 4

int mode = 1;
char moterstatus;
char sensorstatus;
SoftwareSerial BT(RX,TX);//RX,TX角位
//定義Arduino PIN2及PIN4分別為RX及TX腳
Motor motor(RIGHT_IN1,RIGHT_IN2,RIGHT_PWM,
            LEFT_IN3,LEFT_IN4,LEFT_PWM,
            RIGHT_SPEED,LEFT_SPEED);
Sensor sensor(RIGHT_SENSOR,MID_SENSOR,LEFT_SENSOR);

void setup() {
  BT.begin(9600); // 設定和 HC-06 通訊的速度 (預設 9600)
}

void loop() {
  if(mode==1){
    /*Serial.print("digital read from pin11 is:");
    Serial.println(digitalRead(12));*/
    sensorstatus = sensor.sensor_read();
    
    switch(sensorstatus){
      case 1:
        motor.moveForward2();
        break;
      case 2:
        motor.moveRight2();
        if(sensorstatus) motor.moveRight2();
        break;
      case 3:
        motor.moveRight();
        break;
      case 4:
        motor.stop();
        mode = 2;
    }
  }

  if(mode == 2){
    if (BT.available()){
      moterstatus=BT.read();
      Serial.println(moterstatus); 
    }
    
    switch (moterstatus){ 
      case 'F':
        // digitalWrite(pin1,HIGH);
        Serial.println(moterstatus);
        motor.moveForward();
        break;
      case 'L':
        // digitalWrite(pin1,LOW);
        Serial.println(moterstatus);
        motor.moveLeft();
        break;
      case 'R':
        // digitalWrite(pin1,LOW);
        Serial.println(moterstatus);
        motor.moveRight();
        break;
      case 'B':
        // digitalWrite(pin1,LOW);
        Serial.println(moterstatus);
        motor.moveBackward();
        break;
      case 'T':
        // digitalWrite(pin1,HIGH);
        Serial.println(moterstatus);
        motor.moveRight2();
        motor.moveLeft2();
        break;
      case 'S':
        // digitalWrite(pin1,HIGH);
        Serial.println(moterstatus);
        motor.moveLeft2();
        break;
      case 'C':
        // digitalWrite(pin1,HIGH);
        Serial.println(moterstatus);
        motor.moveRight2();
        break;
    }
  }
}
