/**********************************************************************
  Filename    : Sketch_17.1.2_Acceleration_Detection
  Description : Acceleration Detection
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "IMU_Fusion_SYC.h"

IMU imu(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  imu.begin(CHOOSE_MPU6050);             // Select MPU6050
  // imu.MPU6050_SetGyroOffsets(0, 0, 0);// MPU6050 manually calibrated
  imu.MPU6050_CalcGyroOffsets();         // MPU6050 automatic calibration
}

void loop() {
  imu.Calculate();                       
  // Calculating Angle
  Serial.print("\nangleX : ");
  Serial.print(imu.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(imu.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(imu.getAngleZ());
}