/**********************************************************************
  Filename    : Sketch_16.1.1_Acceleration_Detection
  Description : Acceleration Detection
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// Reference the library to be used by Adafruit_MPU6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
 
// Create an object for the MPU6050 sensor
Adafruit_MPU6050 mpu;
 
void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  // Check if the MPU6050 sensor is detected
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 connection successful!");
 
  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  // Add a delay for stability
  delay(100);
}
 
void loop() {
  // Get new sensor events with the readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
 
  // Print out the acceleration readings in m/s^2
  Serial.print("Acceleration:   X:");
  Serial.print(a.acceleration.x);
  Serial.print(", Y:");
  Serial.print(a.acceleration.y);
  Serial.print(", Z:");
  Serial.print(a.acceleration.z);
  Serial.println(" (m/s^2)");
 
  // Print out the rotation readings in rad/s
  Serial.print("Rotation:       X:");
  Serial.print(g.gyro.x);
  Serial.print(", Y:");
  Serial.print(g.gyro.y);
  Serial.print(", Z:");
  Serial.print(g.gyro.z);
  Serial.println(" (rad/s)");
 
  // Print out the temperature reading in degrees Celsius
  Serial.print("Temperature:    ");
  Serial.print(temp.temperature);
  Serial.println(" (degC)");
 
  // Add a blank line for readability
  Serial.println("");
 
  // Add a delay to avoid flooding the serial monitor
  delay(250);
}
