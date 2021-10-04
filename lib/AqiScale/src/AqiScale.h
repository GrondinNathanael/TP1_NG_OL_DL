#include <Arduino.h>

struct AqiInfo {        
    String description;  // Bon
    String impact;        // La qualité de l’air est considérée comme satisfaisante ....
    String warning;  // Aucune
    String bkgColor;  // #68E143
    String textColor; // #FFFFFF
};
struct AqiInfo bon, acceptable, mauvaisGroupeSensible, mauvaisPourSante, tresMauvais, Dangereux;

class AqiScale{
    public: 
        AqiScale();
        AqiInfo getAQILabelFromPM25(float pm25Value);
};