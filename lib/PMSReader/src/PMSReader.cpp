#include "PMSReader.h"

PMS pms(Serial2);
PMS::DATA data;

PMSReader::PMSReader()
{
    Serial.begin(9600);
    Serial2.begin(9600);
    pms.passiveMode();
}

float PMSReader::getPM25Data()
{
    float dataToTransfer = 0;
    Serial.println("Mise à jour dans 3 minutes.");
    pms.wakeUp();
    delay(180000);
    pms.requestRead();
    if (pms.readUntil(data))
    {
        dataToTransfer = data.PM_AE_UG_2_5;
    }

    Serial.println(dataToTransfer);
    pms.sleep();

    return dataToTransfer;
}