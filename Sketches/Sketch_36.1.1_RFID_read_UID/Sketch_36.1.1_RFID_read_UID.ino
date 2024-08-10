/**********************************************************************
  Filename    : Sketch_36.1.1_RFID_read_UID
  Description : Read the card type and number, print it on the Serial port monitor
  Auther      : www.freenove.com 
  Modification: 2024/08/05
**********************************************************************/
/*
   RFID522-SDA:   Control board-10
   RFID522-SCK:   Control board-13
   RFID522-MOSI:  Control board-11
   RFID522-MISO:  Control board-12
   RFID522-IRQ:   Control board-NC
   RFID522-GND:   Control board-GND
   RFID522-RST:   Control board-9
   RFID522-3.3V:  Control board-3.3V
*/

#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);
unsigned char status;
unsigned char str[MAX_LEN];  //MAX_LEN is 16: size of the array
void setup()
{
  Serial.begin(115200);
  SPI.begin();
  rfid.init(); //initialization
  delay(3000);
  Serial.println("Please put the card to the induction area...");
}

void loop()
{
  //Search card, return card types
  if (rfid.findCard(PICC_REQIDL, str) == MI_OK) {
    Serial.println("Find the card!");
    // Show card type
    ShowCardType(str);
    //Anti-collision detection, read card serial number
    if (rfid.anticoll(str) == MI_OK) {
      Serial.print("The card's number is  : ");
      //Display card serial number
      for (int i = 0; i < 4; i++) {
        Serial.print(0x0F & (str[i] >> 4), HEX);
        Serial.print(0x0F & str[i], HEX);
      }
      Serial.println("");
    }
    //card selection (lock card to prevent redundant read, removing the line will make the sketch read cards continually)
    rfid.selectTag(str);
  }
  rfid.halt();  // command the card to enter sleeping state
}
void ShowCardType(unsigned char * type)
{
  Serial.print("Card type: ");
  if (type[0] == 0x04 && type[1] == 0x00)
    Serial.println("MFOne-S50");
  else if (type[0] == 0x02 && type[1] == 0x00)
    Serial.println("MFOne-S70");
  else if (type[0] == 0x44 && type[1] == 0x00)
    Serial.println("MF-UltraLight");
  else if (type[0] == 0x08 && type[1] == 0x00)
    Serial.println("MF-Pro");
  else if (type[0] == 0x44 && type[1] == 0x03)
    Serial.println("MF Desire");
  else
    Serial.println("Unknown");
}
