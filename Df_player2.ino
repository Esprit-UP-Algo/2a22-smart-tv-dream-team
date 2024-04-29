#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// Utilisez les broches 2 et 3 pour communiquer avec le DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connecté au RX du module
static const uint8_t PIN_MP3_RX = 3; // Connecté au TX du module
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Créez l'objet Player
DFRobotDFPlayerMini player;

void setup() {
  // Initialise le port série USB pour le débogage
  Serial.begin(9600);
  // Initialise le port série pour le DFPlayer Mini
  softwareSerial.begin(9600);

  // Démarre la communication avec le DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
    // Réglez le volume au maximum (0 à 30).
    player.volume(30);
  } else {
    Serial.println("Échec de la connexion au DFPlayer Mini !");
  }
}

void loop() {
  // Vérifie s'il y a des données disponibles à lire depuis le port série
  if (Serial.available() > 0) {
    // Lit la commande envoyée depuis l'ordinateur
    char command = Serial.read();
    // Vérifie la commande reçue
    if (command == 'P') {
      // Attendre que le numéro de fichier soit disponible
      while (!Serial.available()) {
        delay(10);
      }
      // Lit le numéro de fichier à jouer
      char fileNumber = Serial.read();
      // Vérifie si le numéro de fichier est un chiffre valide
      if (fileNumber >= '0' && fileNumber <= '9') {
        // Convertit le numéro de fichier en entier
        int fileNum = fileNumber - '0';
        // Joue le fichier correspondant sur la carte SD
        player.play(fileNum);
      } else {
        Serial.println("Numéro de fichier invalide !");
      }
    }
  }
}
