<<<<<<< Updated upstream
#include <Arduino.h>
#include "Color.h"
class RGBLedManager{
    public:
        RGBLedManager();
        Color getColor(int nbPM25);
    private:
        uint8_t ledR = 12;  
        uint8_t ledG = 13;
};
=======
<<<<<<< Updated upstream
=======
#include <Arduino.h>
#include "LED.h"
class RGBLedManager{
    public:
        RGBLedManager(int pinR, int pinG, int pinB);
        LED getColor(int nbPM25);
    private:
        uint8_t ledR = 12;  
        uint8_t ledG = 13;
};
>>>>>>> Stashed changes
>>>>>>> Stashed changes
