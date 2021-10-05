#include <Arduino.h>
#include <WebServer.h>
#include "AqiScale.h"
#include "Buzzer.h"
#include "PMSReader.h"
#include "RevolvairAirAPI.h"
#include "RevolvairWebServer.h"
#include "RGBLedManager.h"
#include "TempReader.h"
#include "DHT.h"
#include "config.h"

AqiScale * aqi;
Buzzer * buzzer;
PMSReader * pr;
RevolvairAirAPI * api;
RevolvairWebServer * rws;
RGBLedManager * led;
DHT dht(25, DHT22);
TempReader * temp;
int timeLapsed = 0;

void setup() 
{
   api = new RevolvairAirAPI(API_URL, API_TOKEN);
   rws = new RevolvairWebServer(80, ssid, password);
   led = new RGBLedManager(12,13,14);
   temp = new TempReader(dht);
}

void loop() {
  if (timeLapsed % 3 == 0)
  {
    rws->handleClient();
  }
  int pm25 = pr->getPM25Data();
  api->sendPM25ValueToAPI(pm25);
  led->getColor(pm25);
  timeLapsed++;
}