#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {9, 8, 7, 6};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String currentInput = "";
long firstNum = 0;
long secondNum = 0;
long result = 0;
char operation = ' ';
bool newOperation = true;

// Déclarations préalables des fonctions (prototypes)
void displayInput();
void calculateResult();
void displayResult();

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);        // Initialize the LCD with 16 columns and 2 rows
    lcd.print("Calculator"); // Display a message on the LCD
    lcd.setCursor(0, 1);     // Move cursor to the second line
    lcd.print("Press key");  // Display another message
    delay(2000);
    lcd.clear();
}

void loop()
{
    char customKey = customKeypad.getKey();

    if (customKey)
    {
        Serial.println(customKey);

        // Gestion des chiffres
        if (isDigit(customKey))
        {
            if (newOperation)
            {
                lcd.clear();
                currentInput = "";
                newOperation = false;
            }
            currentInput += customKey;
            displayInput();
        }

        // Gestion des opérations
        switch (customKey)
        {
        case '*': // Effacer
            lcd.clear();
            currentInput = "";
            firstNum = 0;
            secondNum = 0;
            operation = ' ';
            lcd.setCursor(0, 0);
            lcd.print("Cleared");
            delay(1000);
            lcd.clear();
            break;

        case '#': // Addition
            if (currentInput != "")
            {
                if (operation == ' ')
                {
                    firstNum = currentInput.toInt();
                    operation = '+';
                    currentInput = "";
                    lcd.setCursor(0, 1);
                    lcd.print("+");
                }
            }
            break;

        case 'A': // Soustraction
            if (currentInput != "")
            {
                if (operation == ' ')
                {
                    firstNum = currentInput.toInt();
                    operation = '-';
                    currentInput = "";
                    lcd.setCursor(0, 1);
                    lcd.print("-");
                }
            }
            break;

        case 'B': // Multiplication
            if (currentInput != "")
            {
                if (operation == ' ')
                {
                    firstNum = currentInput.toInt();
                    operation = '*';
                    currentInput = "";
                    lcd.setCursor(0, 1);
                    lcd.print("*");
                }
            }
            break;

        case 'C': // Division
            if (currentInput != "")
            {
                if (operation == ' ')
                {
                    firstNum = currentInput.toInt();
                    operation = '/';
                    currentInput = "";
                    lcd.setCursor(0, 1);
                    lcd.print("/");
                }
            }
            break;

        case 'D': // Égal
            if (operation != ' ' && currentInput != "")
            {
                secondNum = currentInput.toInt();
                calculateResult();
                displayResult();
                newOperation = true;
                operation = ' ';
            }
            break;
        }
    }
}

void displayInput()
{
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(currentInput);
}

void calculateResult()
{
    switch (operation)
    {
    case '+':
        result = firstNum + secondNum;
        break;
    case '-':
        result = firstNum - secondNum;
        break;
    case '*':
        result = firstNum * secondNum;
        break;
    case '/':
        if (secondNum != 0)
        {
            result = firstNum / secondNum;
        }
        else
        {
            lcd.clear();
            lcd.print("Error: Div by 0");
            delay(2000);
            lcd.clear();
            return;
        }
        break;
    }
}

void displayResult()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(" ");
    lcd.print(operation);
    lcd.print(" ");
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("= ");
    lcd.print(result);
}