#include <Arduino.h>

// Définition des broches
const int trigPin = 10;   // Broche TRIG du capteur
const int echoPin = 9;    // Broche ECHO du capteur
const int redLedPin = 6;  // Broche de la LED rouge
const int blueLedPin = 5; // Broche de la LED bleue

// Variables pour le calcul de distance
long duree;
float distance;

void setup()
{
    // Configuration des broches
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(redLedPin, OUTPUT);  // LED rouge
    pinMode(blueLedPin, OUTPUT); // LED bleue

    // Initialisation de la communication série
    Serial.begin(9600);
    Serial.println("Capteur de distance à ultrasons");
    Serial.println("------------------------------");
}

void loop()
{
    digitalWrite(redLedPin, LOW);  // Éteint la LED rouge
    digitalWrite(blueLedPin, LOW); // Éteint la LED bleue

    // Envoie une impulsion ultrasonique
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Mesure le temps de retour de l'impulsion
    duree = pulseIn(echoPin, HIGH);

    // Calcule la distance en centimètres
    // La vitesse du son est d'environ 343 m/s ou 0.0343 cm/µs
    distance = (duree * 0.0343) / 2;

    if (distance > 20 && distance < 50)
    {
        digitalWrite(blueLedPin, HIGH); // Allume la LED rouge
    }
    else
    {
        digitalWrite(redLedPin, HIGH); // Allume la LED bleue
    }

    // Affiche la distance dans le moniteur série
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}