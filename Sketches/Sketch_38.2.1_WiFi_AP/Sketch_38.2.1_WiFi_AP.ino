/**********************************************************************
  Filename    : Sketch 38.2.1_WiFi_AP
  Description : Set control board to open an access point
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "WiFiS3.h"

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "WiFi_Name";        // your network SSID (name)
char pass[] = "12345678";        // your network password (use for WPA, or use as key for WEP)

int status = WL_IDLE_STATUS;
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  delay(3000);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
  // by default the local IP address will be 192.168.4.1
  // you can override it with the following:
  WiFi.config(IPAddress(192,48,56,2));
  // print the network name (SSID);
  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid, pass);
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    // don't continue
    while (true);
  }

  // wait 5 seconds for connection:
  delay(5000);
  // you're connected now, so print out the status
  printWiFiStatus();
}

void loop() {
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}