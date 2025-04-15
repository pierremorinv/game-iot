#include <Arduino.h>

int etatBouton = 0;

const int boutonPin = 10;
const int ledPin = 9;

void setup()
{
    // initialize PWM pins
    pinMode(ledPin, OUTPUT); // Red LED
    pinMode(boutonPin, INPUT);
}

void loop()
{

    // Lit l'état du bouton
    etatBouton = digitalRead(boutonPin);

    // Si le bouton est appuyé (état HAUT)
    if (etatBouton == HIGH)
    {
        digitalWrite(ledPin, HIGH); // Allume la LED
    }
    else
    {
        digitalWrite(ledPin, LOW); // Éteint la LED
    }
}