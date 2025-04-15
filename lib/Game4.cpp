#include <Arduino.h>

// Définition des broches
const int boutonPin1 = 10;
const int boutonPin2 = 11;
const int ledPin1 = 9; // LED rouge
const int ledPin2 = 8; // LED bleue

void setup()
{
    // Configuration des broches
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(boutonPin1, INPUT);
    pinMode(boutonPin2, INPUT);

    // Initialisation de la communication série à 9600 bauds
    Serial.begin(9600);
    Serial.println("Programme démarré");
}

void loop()
{
    // Lecture des états des boutons
    int etatBouton1 = digitalRead(boutonPin1);
    int etatBouton2 = digitalRead(boutonPin2);

    // Gestion de la LED rouge
    if (etatBouton1 == LOW)
    {
        digitalWrite(ledPin1, HIGH);
        Serial.println("LED rouge allumée");
    }
    else
    {
        digitalWrite(ledPin1, LOW);
    }

    // Gestion de la LED bleue
    if (etatBouton2 == LOW)
    {
        digitalWrite(ledPin2, HIGH);
        Serial.println("LED bleue allumée");
    }
    else
    {
        digitalWrite(ledPin2, LOW);
    }
    delay(100);
}