/*
  Sketch    SerialDevice
  Author    Freenove (http://www.freenove.com)
  Date      2024/08/06
  Brief     This sketch is used to communicate to Processing sketch running
            on PC. The Processing sketch will automatically detect and
            connect to this board which use the same trans format.
  Copyright Copyright © Freenove (http://www.freenove.com)
  License   Creative Commons Attribution ShareAlike 3.0
            (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
*/
#include "SerialCommand.h"

int analogPins[] = {A0, A1, A2, A3, A4, A5};
int keys[] = {4, 5, 6, 7};
int ledPin = 13;
int keyValue = 0;
int keyValueBuffer=0;

void keyscan() {
  if (digitalRead(keys[0]) == 0) {
    keyValue = 1;
  }
  else if (digitalRead(keys[1]) == 0) {
    keyValue = 2;
  }
  else if (digitalRead(keys[2]) == 0) {
    keyValue = 3;
  }
  else if (digitalRead(keys[3]) == 0) {
    keyValue = 4;
  }
  else keyValue = 0;
}

void setup() {
  int i = 0;
  for (i = 0; i < 4; i++)
    pinMode(keys[i], INPUT_PULLUP);
    
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  
}

void loop() {
  static byte inData[64];
  static byte inDataNum = 0;
  while (Serial.available() > 0)
  {
    byte inByte = Serial.read();// Read the serial port data
    if (inByte == SerialCommand.transStart)// Receive the start flag
      inDataNum = 0;
    inData[inDataNum++] = inByte;// Receive data
    if (inByte == SerialCommand.transEnd)// End of receive flag
      if (inData[0] == SerialCommand.transStart)
        break;
  }
  unsigned long msNow = millis();
  if (msNow % 2000 < 1000)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  keyscan();
  if (inData[0] == SerialCommand.transStart && inData[inDataNum - 1] == SerialCommand.transEnd)// Verify the start and end flags
  {
    Serial.write(SerialCommand.transStart);
    if (inData[1] == SerialCommand.requestEcho)
    {
      Serial.write(SerialCommand.echo);
    }
    else if (inData[1] == SerialCommand.requestAnalog)// Request an analog value
    {
      int analog = analogRead(analogPins[0]);
      Serial.write(SerialCommand.Analog);
      Serial.write(analog / 128);
      Serial.write(analog % 128);
    }
    else if (inData[1] == SerialCommand.requestDigital)// Request a numeric value
    {
      Serial.write(SerialCommand.Digital);
      Serial.write(keyValue);
    }
    else if (inData[1] == SerialCommand.requestAnalogs)// Request multiple simulated values
    {
      int analogs[inData[2]];
      for (int i = 0; i < inData[2]; i++)
        analogs[i] = analogRead(analogPins[i]);
      Serial.write(SerialCommand.Analogs);
      for (int i = 0; i < inData[2]; i++)
      {
        Serial.write(analogs[i] / 128);
        Serial.write(analogs[i] % 128);
      }
    }
    Serial.write(SerialCommand.transEnd);
    for (int i = 0; i < inDataNum; i++)
      inData[i] = 0;
  }
}
