

#include "Fingerprint-Sensor-SOLDERED.h"
#include <SPI.h>
#include <MFRC522.h>
#include <string.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif


FingerprintSensor finger = FingerprintSensor(&mySerial);

uint8_t id;
int etat;
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long UID[4];
String UID1="";
bool t1=true;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ; // For Yun/Leo/Micro/Zero/...
    delay(100);
    etat=1;
    SPI.begin();
    mfrc522.PCD_Init();
    

    // set the data rate for the sensor serial port
    finger.begin(57600);

    if (finger.verifyPassword())
    {
        
    }
    else
    {
       
        while (1)
        {
            delay(1);
        }
    }

  
    finger.getParameters();
    
}
int fingerprintExists() {
    int p = -1;
    uint16_t fingerId = 0;
    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                break;
            case FINGERPRINT_NOFINGER:
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                break;
            case FINGERPRINT_IMAGEFAIL:
                break;
            default:
                break;
        }
    }

    p = finger.image2Tz(1);
    switch (p) {
        case FINGERPRINT_OK:
            break;
        case FINGERPRINT_IMAGEMESS:
        case FINGERPRINT_PACKETRECIEVEERR:
        case FINGERPRINT_FEATUREFAIL:
        case FINGERPRINT_INVALIDIMAGE:
        default:
            return p;
    }

    p = finger.fingerFastSearch();
    delay(1000);
    if (p == FINGERPRINT_OK) {
        fingerId = finger.fingerID;
        uint16_t confidence = finger.confidence;
        return fingerId;
        delay(1000);
    } else if (p == FINGERPRINT_NOTFOUND) {
        return 0;
    } else {
        return 0;
    }
}
uint8_t getFingerprintEnroll(uint16_t id) {
    int p = -1;
    Serial.print("a");
    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                break;
            case FINGERPRINT_NOFINGER:
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                break;
            case FINGERPRINT_IMAGEFAIL:
                break;
            default:
                break;
        }
    }

    p = finger.image2Tz(1);
    switch (p) {
        case FINGERPRINT_OK:
            break;
        case FINGERPRINT_IMAGEMESS:
        case FINGERPRINT_PACKETRECIEVEERR:
        case FINGERPRINT_FEATUREFAIL:
        case FINGERPRINT_INVALIDIMAGE:
        default:
            return p;
    }

    p = 0;
    while (p != FINGERPRINT_NOFINGER) {
        p = finger.getImage();
    }


    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                break;
            case FINGERPRINT_NOFINGER:
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                break;
            case FINGERPRINT_IMAGEFAIL:
                break;
            default:
                break;
        }
    }

    p = finger.image2Tz(2);
    switch (p) {
        case FINGERPRINT_OK:
            break;
        case FINGERPRINT_IMAGEMESS:
        case FINGERPRINT_PACKETRECIEVEERR:
        case FINGERPRINT_FEATUREFAIL:
        case FINGERPRINT_INVALIDIMAGE:
        default:
            return p;
    }

    p = finger.createModel();
    if (p == FINGERPRINT_OK) {

    } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
        return p;
    } else if (p == FINGERPRINT_ENROLLMISMATCH) {

        return p;
    } else {
        return p;
    }
    if (!fingerprintExists()) {
        p = finger.storeModel(id);
        if (p == FINGERPRINT_OK) {

        } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
            return p;
        } else if (p == FINGERPRINT_BADLOCATION) {
            return p;
        } else if (p == FINGERPRINT_FLASHERR) {
            return p;
        } else {
            return p;
        }
        return true;
    } else {

    }
}
bool isFingerprintSlotEmpty(uint8_t slot) {
    if (finger.loadModel(slot) == FINGERPRINT_OK) {
        return false; // Slot is not empty
    } else {
        return true; // Slot is empty
    }
}
uint8_t readnumber() {
    uint8_t num = 1;
    while (num <= 172) {
        if (isFingerprintSlotEmpty(num)) {
            return num;
        }
        num++;
    }
    return 0;
}

void loop() // run over and over again
{

    if (etat == 1) { 
        int id = fingerprintExists();
        Serial.print(id);
        if (id != 0) {
            etat = 2;
        }
    }
    if (etat == 2) {
        uint8_t id = readnumber();
        uint8_t result = getFingerprintEnroll(id);
        Serial.print(id);
        etat=1;
    }

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
