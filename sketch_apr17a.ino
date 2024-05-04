#include <SPI.h>
#include <MFRC522.h>
#include <string.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long UID[4];
String UID1="";
bool t1=true;
void setup() {
  Serial.begin(9600);    // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  //mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  //Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() 
{
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
     t1=true;
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  for(int i=0;i<4;i++)
  {
    UID[i]=mfrc522.uid.uidByte[i];
    if (UID[i]<10)
      UID1+=00;
    else if (UID[i]<100)
      UID1+=0;
      
    UID1+=UID[i];
    
    }
    if (t1)
    {
      Serial.print(UID1);
      t1=false;
      delay(2000);
    }
    
      UID1="";
}
