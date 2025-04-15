#include <Arduino.h>

#define CLK 3
#define DT 4

const int numLeds = 5;
const int ledPins[numLeds] = {12, 11, 10, 6, 5};

int compteur = 0;
int etatCLKPrec = 0;

void setup()
{
    for (int i = 0; i < numLeds; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }

    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    Serial.begin(9600);
    etatCLKPrec = digitalRead(CLK);
}

void loop()
{
    int etatCLK = digitalRead(CLK);
    int etatDT = digitalRead(DT);

    if (etatCLK != etatCLKPrec)
    {
        etatCLKPrec = etatCLK;

        if (etatCLK == LOW)
        {
            if (etatDT != etatCLK)
            {
                compteur++;
            }
            else
            {
                compteur--;
            }

            // Limiter compteur de 0 à 4
            if (compteur < 0)
                compteur = 0;
            if (compteur > 4)
                compteur = 4;

            Serial.print("Compteur = ");
            Serial.println(compteur);

            // Mettre à jour l'état des LEDs
            for (int i = 0; i < numLeds; i++)
            {
                if (i == compteur)
                {
                    analogWrite(ledPins[i], 255); // LED principale à fond
                }
                else if (i == compteur - 1 || i == compteur + 1)
                {
                    analogWrite(ledPins[i], 50); // Voisins à moitié
                }
                else
                {
                    analogWrite(ledPins[i], 0); // Autres éteintes
                }
            }

            delay(1);
        }
    }
}
