#ifndef __LINECAR_H__
#define __LINECAR_H__

#include <SoftwareSerial.h>
#include <Wire.h>
class Motor
{
  private:
    int _right_In1;
    int _right_In2;
    int _right_pwm;
    int _left_In3;
    int _left_In4;
    int _left_pwm;
    int _right_speed;
    int _left_speed;
  public:
    Motor(int right_In1,int right_In2,int right_pwm,
          int left_In3,int left_In4,int left_pwm,
          int right_speed,int left_speed);
    void moveForward();
    void moveForward2();
    void moveBackward();
    void moveRight();
    void moveRight2();
    void moveLeft();
    void moveLeft2();
    void stop();
};

class Sensor
{
  private:
    int _right_sensor;
    int _mid_sensor;
    int _left_sensor;
  public:
    Sensor(int right_sensor,int mid_sensor,int left_sensor);
    int sensor_read();
};

#endif