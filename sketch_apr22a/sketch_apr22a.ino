#include <SoftwareSerial.h>

SoftwareSerial mySerial(4, 5);
byte com = 0;
int greenPin = 9; // G petal on RGB LED module connected to digital pin 9 

void setup()
{

 
Serial.begin(9600);

mySerial.begin(9600);

pinMode(greenPin, OUTPUT); // sets the greenPin to be an output
delay(2000);
mySerial.write(0xAA);
mySerial.write(0x37);
delay(1000);
mySerial.write(0xAA);
mySerial.write(0x22);
}

void loop() // run over and over again
{
  /*while (Serial.available())
  {
      com=Serial.read();
      switch(com)
    {
    case 1:
        mySerial.write(0xAA21);
    break;
    case 2:
        mySerial.write(0xAA22);
    break;
    }
  }*/
  /*while(Serial.available())
  {
    com = Serial.read();
    switch(com)
    {
    case 1:
        /*mySerial.write(0xAA);
        mySerial.write((byte)0x00);
        
    
        delay(2000);
        mySerial.write(0xAA);
        mySerial.write(0x21);
    break;
    case 2:
        mySerial.write(0xAA);
        mySerial.write((byte)0x00);
        
    
        delay(2000);
        mySerial.write(0xAA);
        mySerial.write(0x22);
    break;
    }
  }
  */

  
  while(mySerial.available())
  {
    com = mySerial.read();
    switch(com)
    {
    case 0x11:
    
        Serial.write('1');
    break;
    case 0x12:
        Serial.write('2');
    break;
    case 0x13:
        Serial.write('3');
    break;
    case 0x14:
        Serial.write('4');
    break;
    case 0x15:
        Serial.write('5');
    break;
    }
  }

  

  
}
