<<<<<<< Updated upstream
#include "RGBLedManager.h"
#include "Color.h"

RGBLedManager::RGBLedManager()
{
    Serial.begin(9600);
    ledcAttachPin(ledR, 1); 
    ledcAttachPin(ledG, 2);
}

// NOTE: les couleurs sont présentes pour les tests.
Color RGBLedManager::getColor(int nbPM25)
=======
<<<<<<< Updated upstream
=======
#include "RGBLedManager.h"

RGBLedManager::RGBLedManager(int pinR, int pinG, int pinB)
{
    Serial.begin(9600);
    ledcAttachPin(pinR, 1); 
    ledcAttachPin(pinG, 2);
    ledcAttachPin(pinB, 3);
}

// NOTE: les couleurs sont présentes pour les tests.
LED RGBLedManager::getColor(int nbPM25)
>>>>>>> Stashed changes
{
    if (nbPM25 <= 11)
    {
        ledcWrite(1, 0);
        ledcWrite(2, 255);
<<<<<<< Updated upstream
        return Color::GREEN;
=======
        return LED::GREEN;
>>>>>>> Stashed changes
    }
    if (nbPM25 >= 12 && nbPM25 <= 34) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 255);
<<<<<<< Updated upstream
        return Color::YELLOW;
=======
        return LED::YELLOW;
>>>>>>> Stashed changes
    }
    if (nbPM25 >= 35 && nbPM25 <= 53) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 127);
<<<<<<< Updated upstream
        return Color::ORANGE;
=======
        return LED::ORANGE;
>>>>>>> Stashed changes
    }
    if (nbPM25 >= 55) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 0);
<<<<<<< Updated upstream
        return Color::RED;
    }
}
=======
        return LED::RED;
    }
}
>>>>>>> Stashed changes
>>>>>>> Stashed changes
