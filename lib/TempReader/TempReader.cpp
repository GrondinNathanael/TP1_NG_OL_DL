#include <TempReader.h>

static const unsigned long REFRESH_INTERVAL = 5000;
static unsigned long lastRefreshtTime = 0;

TempReader::TempReader(DHT &dht) {

    this->dht = &dht;
}

void TempReader::setup(){
    Serial.println("DHT22 test started");
}

void TempReader::loop(){
    if(millis() - lastRefreshtTime >= REFRESH_INTERVAL){
        lastRefreshtTime += REFRESH_INTERVAL;

        readSensor();
        printData();
    }
}

void TempReader::readSensor(){
    this->humidity = dht->readHumidity();
    this->tCelsius = dht->readTemperature();

    if(isnan(humidity) || isnan(tCelsius)){
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
};

void TempReader::printData(){
    Serial.print("Temperature: ");
    Serial.print(tCelsius);
    Serial.print("*C");
    Serial.print("humidity: ");
    Serial.print(humidity);
    Serial.println("%\t");
};