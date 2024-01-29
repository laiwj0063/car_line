#include "linecar.h"
#include "Arduino.h"

Motor::Motor(int right_In1,int right_In2,int right_pwm,
             int left_In3,int left_In4,int left_pwm,
             int right_speed,int left_speed)
{
  pinMode(left_In4, OUTPUT);
  pinMode(left_In3, OUTPUT);
  pinMode(right_In2, OUTPUT);
  pinMode(right_In1, OUTPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_pwm, OUTPUT);

  _right_In1 = right_In1;
  _right_In2 = right_In2;
  _right_pwm = right_pwm;
  _left_In3 = left_In3;
  _left_In4 = left_In4;
  _left_pwm = left_pwm;
  _right_speed = right_speed;
  _left_speed = left_speed;
}

void Motor::moveForward(){
  digitalWrite(_left_In3,HIGH);
  digitalWrite(_left_In4,LOW);
  analogWrite(_left_pwm,_left_speed);
  digitalWrite(_right_In2,HIGH);
  digitalWrite(_right_In1,LOW);
  analogWrite(_right_pwm,_right_speed);
  delay(200);
  stop();
}

void Motor::moveForward2(){
  digitalWrite(_left_In3,HIGH);
  digitalWrite(_left_In4,LOW);
  analogWrite(_left_pwm,_left_speed);
  digitalWrite(_right_In2,HIGH);
  digitalWrite(_right_In1,LOW);
  analogWrite(_right_pwm,_right_speed);
  delay(80);
  stop();
}

void Motor::moveBackward(){
  digitalWrite(_left_In3,LOW);
  digitalWrite(_left_In4,HIGH);
  analogWrite(_left_pwm,_left_speed);
  digitalWrite(_right_In2,LOW);
  digitalWrite(_right_In1,HIGH);
  analogWrite(_right_pwm,_right_speed);
  delay(130);
  stop();
}

void Motor::moveRight(){
  digitalWrite(_left_In3,HIGH);
  digitalWrite(_left_In4,LOW);
  analogWrite(_left_pwm,_left_speed);
  digitalWrite(_right_In2,LOW);
  digitalWrite(_right_In1,LOW);
  delay(145);
  stop();
}

void Motor::moveRight2(){
  digitalWrite(_left_In3,HIGH);
  digitalWrite(_left_In4,LOW);
  analogWrite(_left_pwm,_left_speed);
  digitalWrite(_right_In2,LOW);
  digitalWrite(_right_In1,LOW);
  delay(75);
  stop();
}

void Motor::moveLeft(){
  digitalWrite(_left_In3,LOW);
  digitalWrite(_left_In4,LOW);
  digitalWrite(_right_In2,HIGH);
  digitalWrite(_right_In1,LOW);
  analogWrite(_right_pwm,_right_speed);
  delay(145);
  stop();
}

void Motor::moveLeft2(){
  digitalWrite(_left_In3,LOW);
  digitalWrite(_left_In4,LOW);
  digitalWrite(_right_In2,HIGH);
  digitalWrite(_right_In1,LOW);
  analogWrite(_right_pwm,_right_speed);
  delay(75);
  stop();
}

void Motor::stop(){
  digitalWrite(_left_In3,LOW);
  digitalWrite(_left_In4,LOW);
  digitalWrite(_right_In2,LOW);
  digitalWrite(_right_In1,LOW);
  delay(150);
}

Sensor::Sensor(int right_sensor,int mid_sensor,int left_sensor){
  pinMode(right_sensor,INPUT);
  pinMode(mid_sensor,INPUT);
  pinMode(left_sensor,INPUT);

  _right_sensor = right_sensor;
  _mid_sensor = mid_sensor;
  _left_sensor = left_sensor;
}

int Sensor::sensor_read(){
  if(digitalRead(_right_sensor)==1&&digitalRead(_mid_sensor)==0&&digitalRead(_left_sensor)==1){
    return 1;
  }
  if(digitalRead(_right_sensor)==1&&digitalRead(_mid_sensor)==1&&digitalRead(_left_sensor)==1){
    return 2;
  }
  if(digitalRead(_right_sensor)==0&&digitalRead(_left_sensor)==1){
    return 3;
  }
  if(digitalRead(_right_sensor)==1&&digitalRead(_left_sensor)==0){
    return 4;
  }
  if(digitalRead(_right_sensor)==0&&digitalRead(_left_sensor)==0){
    return 0;
  }
  if(digitalRead(_mid_sensor)==0&&digitalRead(_left_sensor)==0){
    return 0;
  }
  if(digitalRead(_right_sensor)==0&&digitalRead(_mid_sensor)==0){
    return 0;
  }
}
