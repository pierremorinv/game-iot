#include <Arduino.h>

// Structure pour stocker les infos de chaque LED
struct LED
{
    int pin;
    String name;
};

// Configuration des LEDs
const LED leds[] = {
    {10, "bleue"},   // LED1
    {11, "rouge"},   // LED2
    {12, "blanche"}, // LED3
};
const int NUM_LEDS = 3;

void setup()
{
    // Configuration des broches
    for (int i = 0; i < NUM_LEDS; i++)
    {
        pinMode(leds[i].pin, OUTPUT);
    }

    // Initialisation de la communication série
    Serial.begin(9600);
    Serial.println("Programme démarré");
    Serial.println("Commandes : 'LED1 ON', 'LED1 OFF', 'LED2 ON', 'LED2 OFF', 'LED3 ON', 'LED3 OFF'");
}

void controleLED(int ledIndex, bool etat)
{
    digitalWrite(leds[ledIndex].pin, etat);
    Serial.print("LED ");
    Serial.print(leds[ledIndex].name);
    Serial.println(etat ? " allumée" : " éteinte");
}

void loop()
{
    // Attente input utilisateur
    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        Serial.println(input);

        bool commandeReconnue = false;

        // Traitement de la commande
        for (int i = 0; i < NUM_LEDS; i++)
        {
            String ledOnCmd = "LED" + String(i + 1) + " ON";
            String ledOffCmd = "LED" + String(i + 1) + " OFF";

            if (input.equalsIgnoreCase(ledOnCmd))
            {
                controleLED(i, HIGH);
                commandeReconnue = true;
                break;
            }
            else if (input.equalsIgnoreCase(ledOffCmd))
            {
                controleLED(i, LOW);
                commandeReconnue = true;
                break;
            }
        }

        if (!commandeReconnue)
        {
            Serial.println("Commande non reconnue. Utilisez 'LED1 ON', 'LED1 OFF', 'LED2 ON', 'LED2 OFF', 'LED3 ON' ou 'LED3 OFF'.");
        }
    }

    delay(50);
}