#include "Fingerprint-Sensor-SOLDERED.h"

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);
#else
#define mySerial Serial1
#endif

FingerprintSensor finger = FingerprintSensor(&mySerial);

#define FINGERPRINT_ALREADY_EXISTS 0xA0

    int etat=1;
void setup() {
    Serial.begin(9600);
    while (!Serial) delay(1); // Wait for serial connection

    finger.begin(57600);

    if (!finger.verifyPassword()) {
        while (1) delay(1);
    }

    finger.getParameters();

    for (int fingerId = 1; fingerId < 20; fingerId++) {
        downloadFingerprintTemplate(fingerId);
    }
}

void downloadFingerprintTemplate(uint16_t id) {
    uint8_t bytesReceived[128];



    uint8_t p = finger.loadModel(id);
    if (p != FINGERPRINT_OK) {

        return;
    }



    p = finger.getModel();
    if (p != FINGERPRINT_OK) {

        return;
    }


    memset(bytesReceived, 0xff, sizeof(bytesReceived));

    uint32_t startTime = millis();
    int uindx = 9, index = 0;

    while (index < sizeof(bytesReceived) && (millis() - startTime) < 2000) {
        while (index < uindx) ++index;
        uindx += 128;
        while (index < uindx) {
            if (mySerial.available()) {
                bytesReceived[index] = mySerial.read();
                ++index;
            }
        }
        uindx += 2;
        while (index < uindx) ++index;
        uindx = index + 9;
    }

    if ((millis() - startTime) >= 2000) {
        
        return;
    }

    for (int i = 0; i < sizeof(bytesReceived); ++i) {
        printHex(bytesReceived[i], 2);
    }

    
}

void printHex(int num, int precision) {
    char tmp[4];
    char format[8];

    sprintf(format, "%%.%dX", precision);

    sprintf(tmp, format, num);

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

    // Convert the image to a template
    p = finger.image2Tz(1);
    switch (p) {
        case FINGERPRINT_OK:

            break;
        case FINGERPRINT_IMAGEMESS:

            return p;
        case FINGERPRINT_PACKETRECIEVEERR:

            return p;
        case FINGERPRINT_FEATUREFAIL:

            return p;
        case FINGERPRINT_INVALIDIMAGE:

            return p;
        default:

            return p;
    }

    // Search for a matching fingerprint
    p = finger.fingerFastSearch();
    if (p == FINGERPRINT_OK) {
        fingerId = finger.fingerID;
        uint16_t confidence = finger.confidence;
        return fingerId;
    } else if (p == FINGERPRINT_NOTFOUND) {
        return 0;
    } else {
        return 0;
    }
}

uint8_t getFingerprintEnroll(uint16_t id) {
int p = -1;
    Serial.print("a");
    delay(2000);
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

            return p;
        case FINGERPRINT_PACKETRECIEVEERR:

            return p;
        case FINGERPRINT_FEATUREFAIL:

            return p;
        case FINGERPRINT_INVALIDIMAGE:
        
            return p;
        default:
   
            return p;
    }

    Serial.print("b");
    delay(2000);
    p = 0;
    while (p != FINGERPRINT_NOFINGER) {
        p = finger.getImage();
    }

    Serial.print("c");
    delay(2000);
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
            
            return p;
        case FINGERPRINT_PACKETRECIEVEERR:
            
            return p;
        case FINGERPRINT_FEATUREFAIL:
            
            return p;
        case FINGERPRINT_INVALIDIMAGE:
            
            return p;
        default:
            
            return p;
    }

    p = finger.createModel();
    if (p == FINGERPRINT_OK) {
        Serial.print("d");
        delay(2000);
    } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
        return p;
    } else if (p == FINGERPRINT_ENROLLMISMATCH) {
        Serial.print("e");
        delay(2000);
        return p;
    } else {
        return p;
    }
  if(!fingerprintExists())
  {
     
    p = finger.storeModel(id);
    if (p == FINGERPRINT_OK) {
        Serial.print("f");
        
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
  }
  else
  {

    Serial.print("g");
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop() {
    if (etat==1) 
    { 
     Serial.print(fingerprintExists());
    }
     etat=2;
    if (etat==2)
     {
          uint8_t id = readnumber();
          uint8_t result = getFingerprintEnroll(id);
          if (id == 0) return;
     }


}
