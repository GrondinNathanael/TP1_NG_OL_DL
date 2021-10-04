#include "RGBLedManager.h"
#include "LED.h"

RGBLedManager::RGBLedManager(int pinR, int pinG, int pinB)
{
    Serial.begin(9600);
    ledcAttachPin(ledR, 1); 
    ledcAttachPin(ledG, 2);
    ledcAttachPin(ledB, 3);
}

// NOTE: les couleurs sont présentes pour les tests.
LED RGBLedManager::getColor(int nbPM25)
{
    if (nbPM25 <= 11)
    {
        ledcWrite(1, 0);
        ledcWrite(2, 255);
        return LED::GREEN;
    }
    if (nbPM25 >= 12 && nbPM25 <= 34) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 255);
        return LED::YELLOW;
    }
    if (nbPM25 >= 35 && nbPM25 <= 53) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 127);
        return LED::ORANGE;
    }
    if (nbPM25 >= 55) 
    {
        ledcWrite(1, 255);
        ledcWrite(2, 0);
        return LED::RED;
    }
}