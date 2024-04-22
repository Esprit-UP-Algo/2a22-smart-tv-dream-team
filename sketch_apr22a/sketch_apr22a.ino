#include <SoftwareSerial.h>

SoftwareSerial DF1_Serial(1, 2);
byte com = 0;
int greenPin = 9; // G petal on RGB LED module connected to digital pin 9 

void setup()
{
  
        
Serial.begin(9600);

pinMode(greenPin, OUTPUT); // sets the greenPin to be an output
delay(2000);
Serial.write(0xAA);
Serial.write(0x37);
delay(1000);
Serial.write(0xAA);
Serial.write(0x22);
}

void loop() // run over and over again
{
  while(Serial.available())
  {
    com = Serial.read();
    switch(com)
    {
    case 0x11:
        analogWrite(greenPin, 255);
    break;
    case 0x12:
        analogWrite(greenPin, 0);
    break;
    case 0x13:
        analogWrite(greenPin, 255);
    break;
    case 0x14:
        analogWrite(greenPin, 0);
    break;
    case 0x15:
        analogWrite(greenPin, 255);
    break;
    }
  }
}
