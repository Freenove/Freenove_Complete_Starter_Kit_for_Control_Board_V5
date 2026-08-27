/**********************************************************************
  Filename    : Sketch_38.1.1_WiFi_Station
  Description : Connect to your router using control board 
  Auther      : www.freenove.com
  Modification: 2026/08/27
**********************************************************************/

#include "WiFiS3.h"
  
const char *ssid_Router     = "********"; //Enter the router name
const char *password_Router = "********"; //Enter the router password

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setup start");

  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid_Router, password_Router);
  }
  while (WiFi.localIP() == IPAddress(0, 0, 0, 0)) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup End");
}
 
void loop() {
}