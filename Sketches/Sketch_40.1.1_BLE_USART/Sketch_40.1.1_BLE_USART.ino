/**********************************************************************
  Filename    : Sketch_40.1.1_BLE_USART
  Description : BLE USART
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include <ArduinoBLE.h>
#include "String.h"

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214");  // Bluetooth® Low Energy LED Service
// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLECharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite | BLENotify | BLEBroadcast, 20);

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
long lasttime = 0;

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
  switchCharacteristic.writeValue("LED");

  BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  switchCharacteristic.setEventHandler(BLEWritten, switchCharacteristicWritten);

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  long nowtime = millis();
  if (nowtime - lasttime > 1000) {
    BLE.poll();
    Serial.print(".");
    if (Serial.available() > 0) {
      String str = Serial.readString();
      const char *newValue = str.c_str();
      switchCharacteristic.writeValue(newValue);
    }
    lasttime = nowtime;
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
}
