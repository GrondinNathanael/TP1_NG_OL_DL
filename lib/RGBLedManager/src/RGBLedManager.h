#include <Arduino.h>
#include "LED.h"
class RGBLedManager{
    public:
        RGBLedManager();
        LED getColor(int nbPM25);
    private:
        uint8_t ledR = 12;  
        uint8_t ledG = 13;
};