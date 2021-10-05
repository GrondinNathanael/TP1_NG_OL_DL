#include <Adafruit_Sensor.h>
#include "DHT.h"

class TempReader
{
private:
    DHT* dht;
    int humidity;
    int tCelsius;
public:
    TempReader(DHT &dht);
    void setup();
    void loop();
    void readSensor();
    void printData();
};

