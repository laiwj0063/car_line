#include "linecar.h"

#define right_In1 9
#define right_In2 8 
#define right_pwm 5
#define left_In3 7
#define left_In4 6
#define left_pwm 3
#define right_sensor 10
#define mid_sensor 11
#define left_sensor 12
#define right_speed 117
#define left_speed 99
#define RX 2
#define TX 4

int mode = 1;
char moterstatus;
char sensorstatus;
SoftwareSerial BT(RX,TX);//RX,TX角位
//定義Arduino PIN2及PIN4分別為RX及TX腳
Motor motor(right_In1,right_In2,right_pwm,
            left_In3,left_In4,left_pwm,
            right_speed,left_speed);
Sensor sensor(right_sensor,mid_sensor,left_sensor);

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
