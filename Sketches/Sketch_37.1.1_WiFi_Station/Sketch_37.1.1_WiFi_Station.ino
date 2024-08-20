/**********************************************************************
  Filename    : Sketch_37.1.1_WiFi_Station
  Description : Connect to your router using control board 
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "WiFiS3.h"
  
const char *ssid_Router     = "********"; //Enter the router name
const char *password_Router = "********"; //Enter the router password

void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setup start");
  WiFi.begin(ssid_Router, password_Router);
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup End");
}
 
void loop() {
}
