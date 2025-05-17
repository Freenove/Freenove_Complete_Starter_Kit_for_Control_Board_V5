/**********************************************************************
  Filename    : Sketch_17.1.1_Acceleration_Detection
  Description : Acceleration Detection
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "IMU_Fusion_SYC.h"

IMU imu(Wire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// Set baud rate
  Wire.begin();
  imu.begin(CHOOSE_MPU6050);// IMU initialization
  imu.MPU6050_CalcGyroOffsets();// MPU6050 calibration
}

void loop() {
  // put your main code here, to run repeatedly:
  imu.Calculate();// calculating data
  Serial.println("\n****************************************************\n");
  // Calculated data Output raw accelerometer and gyroscope data
  Serial.print("accx:");
  Serial.print(imu.getaccx());
  Serial.print("\t");
  Serial.print("accy:");
  Serial.print(imu.getaccy());
  Serial.print("\t");
  Serial.print("accz:");
  Serial.println(imu.getaccz());

  Serial.print("gyrox:");
  Serial.print(imu.getgyrox());
  Serial.print("\t");
  Serial.print("gyroy:");
  Serial.print(imu.getgyroy());
  Serial.print("\t");
  Serial.print("gyroz:");
  Serial.println(imu.getgyroz());
  Serial.println("\n****************************************************\n");
  delay(1000);
}