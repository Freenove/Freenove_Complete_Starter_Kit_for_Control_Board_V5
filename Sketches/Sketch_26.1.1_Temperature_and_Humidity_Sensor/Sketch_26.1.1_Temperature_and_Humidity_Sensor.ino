/**
 * @author: Vegetable-SYC
 *
 * @file: Sketch_26.1.1_Temperature_and_Humidity_Sensor
 *
 * @description: Temperature & Humidity Sensor
 *
 * @date: 2025/10/23
**/

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 10     // Digital pin connected to the DHT sensor 

#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
  sensor_t sensor;
  // Set delay between sensor readings based on sensor details.
  dht.humidity().getSensor(&sensor);
  dht.temperature().getSensor(&sensor);
}

void loop() {
  // Delay between measurements.
  delay(1000);
  // Get temperature event and print its value.
  sensors_event_t event;

  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.print("%, ");
  }

  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println("℃");
  }
}