/**********************************************************************
  Filename    : Sketch_35.1.1_Barometer
  Description : Barometer
  Auther      : www.freenove.com 
  Modification: 2024/08/05
**********************************************************************/
// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)

#include <Adafruit_BMP085.h>
Adafruit_BMP085 BMP180;
  
void setup() {
  Serial.begin(9600);
  if (!BMP180.begin()) {
	Serial.println("Could not find a valid BMP180 sensor, check wiring!");
	while (1) {}
  }
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(BMP180.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(BMP180.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(BMP180.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(BMP180.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(BMP180.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
}
