/**********************************************************************
  Filename    : Sketch_41.2.1_Control_LED_with_Bluetooth
  Description : Control LED with Bluetooth
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include <ArduinoBLE.h>
#include "String.h"

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214");  // Bluetooth® Low Energy LED Service
// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLECharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite | BLENotify | BLEBroadcast, 20);

const int ledPin = LED_BUILTIN;  // pin to use for the LED
void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);
  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  BLE.setLocalName("Control_Board_V5.0_Bluetooth");
  BLE.setAdvertisedService(ledService);
  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);
  // add service
  BLE.addService(ledService);
  // set the initial value for the characeristic:
  switchCharacteristic.writeValue("Led");

  BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  switchCharacteristic.setEventHandler(BLEWritten, switchCharacteristicWritten);

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    central.poll();
    delay(1000);
    Serial.print(".");  
  }
}

void blePeripheralConnectHandler(BLEDevice central) {
  Serial.print("Connected event, central: ");
  Serial.println(central.address());
}

void blePeripheralDisconnectHandler(BLEDevice central) {
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
}

void switchCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic) {
  Serial.print("Characteristic event, written: ");

  uint8_t characteristicValue[20];
  int bytesRead = characteristic.readValue(characteristicValue, sizeof(characteristicValue));

  Serial.print("Received bytes: ");
  for (int i = 0; i < bytesRead; i++) {
    Serial.print(characteristicValue[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  String receivedString = "";

  for (int i = 0; i < bytesRead; i++) {
    receivedString += (char)characteristicValue[i];
  }
  Serial.println("Value: " + receivedString);
  if (receivedString == "led_on") {
    Serial.println("LED on");
    digitalWrite(ledPin, HIGH);  // will turn the LED on
  }
  if (receivedString == "led_off") {  
    Serial.println(F("LED off"));
    digitalWrite(ledPin, LOW);  // will turn the LED off
  }
}