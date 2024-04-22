#include "Fingerprint-Sensor-SOLDERED.h"

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);
#else
#define mySerial Serial1
#endif

FingerprintSensor finger = FingerprintSensor(&mySerial);

#define FINGERPRINT_ALREADY_EXISTS 0xA0

void setup() {
    Serial.begin(9600);
    while (!Serial) delay(1); // Wait for serial connection

    Serial.println("\n\nAdafruit Fingerprint sensor enrollment + extractor");

    finger.begin(57600);

    if (!finger.verifyPassword()) {
        Serial.println("Did not find fingerprint sensor :(");
        while (1) delay(1);
    }

    finger.getParameters();

    for (int fingerId = 1; fingerId < 20; fingerId++) {
        downloadFingerprintTemplate(fingerId);
    }
}

void downloadFingerprintTemplate(uint16_t id) {
    uint8_t bytesReceived[128];

    Serial.println("------------------------------------");
    Serial.print("Attempting to load #");
    Serial.println(id);

    uint8_t p = finger.loadModel(id);
    if (p != FINGERPRINT_OK) {
        Serial.print("Failed to load template for #");
        Serial.println(id);
        return;
    }

    Serial.print("Attempting to get #");
    Serial.println(id);

    p = finger.getModel();
    if (p != FINGERPRINT_OK) {
        Serial.print("Failed to get template for #");
        Serial.println(id);
        return;
    }

    Serial.println("Decoding packet...");

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
        Serial.println("Timeout occurred while waiting for data.");
        return;
    }

    for (int i = 0; i < sizeof(bytesReceived); ++i) {
        printHex(bytesReceived[i], 2);
    }

    Serial.println("\ndone.");
}

void printHex(int num, int precision) {
    char tmp[4];
    char format[8];

    sprintf(format, "%%.%dX", precision);

    sprintf(tmp, format, num);
    Serial.print(tmp);
}

bool fingerprintExists(uint16_t id) {
 int p = -1;
    uint16_t fingerId = 0;

    Serial.println("Place your finger on the sensor...");

    // Wait for a finger to be detected
    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                Serial.println("Image taken");
                break;
            case FINGERPRINT_NOFINGER:
                Serial.println(".");
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                Serial.println("Communication error");
                break;
            case FINGERPRINT_IMAGEFAIL:
                Serial.println("Imaging error");
                break;
            default:
                Serial.println("Unknown error");
                break;
        }
    }

    // Convert the image to a template
    p = finger.image2Tz(1);
    switch (p) {
        case FINGERPRINT_OK:
            Serial.println("Image converted");
            break;
        case FINGERPRINT_IMAGEMESS:
            Serial.println("Image too messy");
            return p;
        case FINGERPRINT_PACKETRECIEVEERR:
            Serial.println("Communication error");
            return p;
        case FINGERPRINT_FEATUREFAIL:
            Serial.println("Could not find fingerprint features");
            return p;
        case FINGERPRINT_INVALIDIMAGE:
            Serial.println("Could not find fingerprint features");
            return p;
        default:
            Serial.println("Unknown error");
            return p;
    }

    // Search for a matching fingerprint
    p = finger.fingerFastSearch();
    if (p == FINGERPRINT_OK) {
        fingerId = finger.fingerID;
        uint16_t confidence = finger.confidence;

        Serial.print("Found ID #");
        Serial.print(fingerId);
        Serial.print(" with confidence of ");
        Serial.println(confidence);

        return fingerId;
    } else if (p == FINGERPRINT_NOTFOUND) {
        Serial.println("No matching fingerprint found");
        return 0;
    } else {
        Serial.println("Unknown error");
        return 0;
    }
}

uint8_t getFingerprintEnroll(uint16_t id) {
int p = -1;
    Serial.print("Waiting for valid finger to enroll as #");
    Serial.println(id);
    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                Serial.println("Image taken");
                break;
            case FINGERPRINT_NOFINGER:
                Serial.println(".");
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                Serial.println("Communication error");
                break;
            case FINGERPRINT_IMAGEFAIL:
                Serial.println("Imaging error");
                break;
            default:
                Serial.println("Unknown error");
                break;
        }
    }

    p = finger.image2Tz(1);
    switch (p) {
        case FINGERPRINT_OK:
            Serial.println("Image converted");
            break;
        case FINGERPRINT_IMAGEMESS:
            Serial.println("Image too messy");
            return p;
        case FINGERPRINT_PACKETRECIEVEERR:
            Serial.println("Communication error");
            return p;
        case FINGERPRINT_FEATUREFAIL:
            Serial.println("Could not find fingerprint features");
            return p;
        case FINGERPRINT_INVALIDIMAGE:
            Serial.println("Could not find fingerprint features");
            return p;
        default:
            Serial.println("Unknown error");
            return p;
    }

    Serial.println("Remove finger");
    delay(2000);
    p = 0;
    while (p != FINGERPRINT_NOFINGER) {
        p = finger.getImage();
    }

    Serial.println("Place same finger again");
    while (p != FINGERPRINT_OK) {
        p = finger.getImage();
        switch (p) {
            case FINGERPRINT_OK:
                Serial.println("Image taken");
                break;
            case FINGERPRINT_NOFINGER:
                Serial.println(".");
                break;
            case FINGERPRINT_PACKETRECIEVEERR:
                Serial.println("Communication error");
                break;
            case FINGERPRINT_IMAGEFAIL:
                Serial.println("Imaging error");
                break;
            default:
                Serial.println("Unknown error");
                break;
        }
    }

    p = finger.image2Tz(2);
    switch (p) {
        case FINGERPRINT_OK:
            Serial.println("Image converted");
            break;
        case FINGERPRINT_IMAGEMESS:
            Serial.println("Image too messy");
            return p;
        case FINGERPRINT_PACKETRECIEVEERR:
            Serial.println("Communication error");
            return p;
        case FINGERPRINT_FEATUREFAIL:
            Serial.println("Could not find fingerprint features");
            return p;
        case FINGERPRINT_INVALIDIMAGE:
            Serial.println("Could not find fingerprint features");
            return p;
        default:
            Serial.println("Unknown error");
            return p;
    }

    Serial.print("Creating model for #");
    Serial.println(id);

    p = finger.createModel();
    if (p == FINGERPRINT_OK) {
        Serial.println("Prints matched!");
    } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
        Serial.println("Communication error");
        return p;
    } else if (p == FINGERPRINT_ENROLLMISMATCH) {
        Serial.println("Fingerprints did not match");
        return p;
    } else {
        Serial.println("Unknown error");
        return p;
    }
  if(!fingerprintExists(id))
  {
    Serial.print("ID ");
    Serial.println(id);
    p = finger.storeModel(id);
    if (p == FINGERPRINT_OK) {
        Serial.println("Stored!");
    } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
        Serial.println("Communication error");
        return p;
    } else if (p == FINGERPRINT_BADLOCATION) {
        Serial.println("Could not store in that location");
        return p;
    } else if (p == FINGERPRINT_FLASHERR) {
        Serial.println("Error writing to flash");
        return p;
    } else {
        Serial.println("Unknown error");
        return p;
    }

    return true;
  }
  else
  {
    Serial.println("finger print already exists");
  }
}

uint8_t readnumber() {
    uint8_t num = 0;

    while (num == 0) {
        while (!Serial.available());
        num = Serial.parseInt();
    }

    return num;
}

void loop() {
    Serial.println("Ready to enroll a fingerprint!");
    Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
    uint8_t id = readnumber();

    if (id == 0) return;

    Serial.print("Enrolling ID #");
    Serial.println(id);

    uint8_t result = getFingerprintEnroll(id);
}
