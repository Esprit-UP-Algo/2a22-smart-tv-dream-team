#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address and dimensions of the LCD
const int scrollDelay = 300;        // Delay between scrolls (in milliseconds)
const int charDelay = 100;          // Delay between each character movement (in milliseconds)

bool welcomeDisplayed = false; // Flag to track if welcome message is displayed

// Function prototype
void displayMessage(String message);

void setup() {
  lcd.init();        // Initialize the LCD screen
  lcd.backlight();   // Turn on the backlight
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Check if a message is received from the serial port
  if (Serial.available() > 0) {
    String receivedMessage = Serial.readStringUntil('\n'); // Read the message until newline character
    
    // Check if the received message contains the "deleted row with ID" prefix
    if (receivedMessage.startsWith("Deleted row with ID")) {
      // Display the received message on the LCD without scrolling
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(receivedMessage);
    } else {
      // Check if the message ends with "!"
      if (receivedMessage.endsWith("!")) {
        // Remove the "!" from the message
        receivedMessage.remove(receivedMessage.length() - 1);
      }
      // Display the received message on the LCD
      displayMessage(receivedMessage);
    }
  }
}

void displayMessage(String receivedMessage) {
  int receivedMessageLength = receivedMessage.length();
  lcd.clear();
  lcd.setCursor(0, 0);
  
  // If the message is longer than the LCD width, scroll it
  if (receivedMessageLength > 16) {
    for (int i = 0; i <= receivedMessageLength - 16; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(receivedMessage.substring(i, i + 16)); // Using substring() to get substring
      delay(charDelay); // Consider removing this delay
    }
    delay(scrollDelay); // Consider removing this delay
  } else {
    lcd.print(receivedMessage); // If the message fits on one line, print it directly
  }
}
