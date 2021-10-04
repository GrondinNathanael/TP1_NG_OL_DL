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
{
    if (nbPM25 <= 11)
    {
        ledcWrite(1, 0);
        ledcWrite(2, 255);
        return Color::GREEN;
    }
    if (nbPM25 >= 12 && nbPM25 <= 34) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 255);
        return Color::YELLOW;
    }
    if (nbPM25 >= 35 && nbPM25 <= 53) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 127);
        return Color::ORANGE;
    }
    if (nbPM25 >= 55) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 0);
        return Color::RED;
    }
}