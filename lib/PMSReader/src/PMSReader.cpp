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
    Serial.println("Waking up, wait 30 seconds for stable readings...");
    pms.wakeUp();
    delay(30000);

    Serial.println("Send read request...");
    pms.requestRead();

    Serial.println("Wait max. 1 second for read...");

    if (pms.readUntil(data))
    {
        dataToTransfer = data.PM_AE_UG_2_5;
    }

    Serial.println("Going to sleep");
    pms.sleep();

    return dataToTransfer;
}