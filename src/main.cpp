#include <Arduino.h>
#include <WebServer.h>
#include "AqiScale.h"
#include "Buzzer.h"
#include "PMSReader.h"
#include "RevolvairAirAPI.h"
#include "RevolvairWebServer.h"
#include "RGBLedManager.h"
#include "SPIFFSFileReader.h"
#include "TempReader.h"

AqiScale aqi;
Buzzer buzzer;
PMSReader pms;
// RevolvairAirAPI api;
RevolvairWebServer rws;
RGBLedManager led;
SPIFFSFileReader spiffs;
TempReader temp;

void setup() 
{
  aqi = AqiScale();
  pms = PMSReader();
  rws = RevolvairWebServer(80);
  led = RGBLedManager(12,13,14);
}

void loop() {
  rws.handleClient();
  delay(2);
}