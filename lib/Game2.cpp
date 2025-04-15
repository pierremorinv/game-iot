#include <Arduino.h>

void setup()
{
    // initialize PWM pins
    pinMode(9, OUTPUT);  // Red LED
    pinMode(10, OUTPUT); // White LED
    pinMode(11, OUTPUT); // Bleu LED
}

void loop()
{
    digitalWrite(9, HIGH);  // Allumer la LED Rouge
    delay(1000);            // Attendre 1 seconde
    digitalWrite(9, LOW);   // Éteindre la LED Rouge
    delay(1000);            // Attendre 1 seconde
    digitalWrite(10, HIGH); // Allumer la LED Blanche
    delay(1000);            // Attendre 1 seconde
    digitalWrite(10, LOW);  // Éteindre la LED Blanche
    delay(1000);            // Attendre 1 seconde
    digitalWrite(11, HIGH); // Allumer la LED Bleue
    delay(1000);            // Attendre 1 seconde
    digitalWrite(11, LOW);  // Éteindre la LED Bleue
    delay(1000);            // Attendre 1 seconde
}
