#include <LedControl.h>

int DIN = 11;
int CS = 7;
int CLK = 13;
LedControl lc = LedControl(DIN, CLK, CS, 1);

const int VRX_PIN = A0; // Position X du joystick
const int VRY_PIN = A1; // Position Y du joystick

// Position actuelle du point lumineux
int pointX = 3;
int pointY = 3;
int incrementer = 1; // Incrémentation pour le mouvement
int decrementer = -1; // Décrémentation pour le mouvement

int joystickXCenter = 512;
int joystickYCenter = 512;

// Seuil pour détecter un mouvement du joystick
const int JOYSTICK_THRESHOLD = 100;

// Délai entre les mouvements
const int MOVEMENT_DELAY = 10;

void updateLedDisplay();

void setup()
{
    Serial.begin(9600);

    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);

    delay(500);
    joystickXCenter = analogRead(VRX_PIN);
    joystickYCenter = analogRead(VRY_PIN);

    updateLedDisplay();
}

void loop()
{
//     // Lecture des valeurs du joystick
//     int joystickX = analogRead(VRX_PIN);
//     int joystickY = analogRead(VRY_PIN);

//     boolean moved = false;

//     int oldPointX = pointX;
//     int oldPointY = pointY;

//     // Mouvement horizontal
//     if (joystickX > joystickXCenter + JOYSTICK_THRESHOLD)
//     {
//         pointX = min(7, pointX + 1);
//         moved = true;
//     }
//     else if (joystickX < joystickXCenter - JOYSTICK_THRESHOLD)
//     {
//         pointX = max(0, pointX - 1);
//         moved = true;
//     }

//     // Mouvement vertical
//     if (joystickY > joystickYCenter + JOYSTICK_THRESHOLD)
//     {
//         pointY = min(7, pointY + 1);
//         moved = true;
//     }
//     else if (joystickY < joystickYCenter - JOYSTICK_THRESHOLD)
//     {
//         pointY = max(0, pointY - 1);
//         moved = true;
//     }

//     if (moved && (oldPointX != pointX || oldPointY != pointY))
//     {
//         updateLedDisplay();
//         delay(MOVEMENT_DELAY);
//     }
updateLedDisplay();
}

void updateLedDisplay()
{
    lc.clearDisplay(0);
    lc.setLed(0, pointY, pointX, true);
}