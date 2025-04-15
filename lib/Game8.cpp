#include <Arduino.h>
#include <Servo.h>
#define CLK 9
#define DT 8
#define SERVO_PIN 10

int compteur = 0;
int etatCLKPrec = 0;

Servo myServo;

void setup()
{
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    myServo.attach(SERVO_PIN);
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
            if (compteur > 6)
                compteur = 6;

            Serial.print("Compteur = ");
            Serial.println(compteur);

            // Mettre à jour la position du servo
            int angle = map(compteur, 0, 6, 0, 180); // Mapper le compteur à un angle de 0 à 180
            myServo.write(angle);                    // Déplacer le servo à l'angle correspondant

            delay(1);
        }
    }
}
