#include "RevolvairWebServer.h"
#include <WiFi.h>
#include <WiFiClient.h>

RevolvairWebServer::RevolvairWebServer(int port, const char* ssid, const char* password)
{
    server = new WebServer(port);
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connection to WiFi : ");
    int time = 0;
    const int TIME_OUT = 10;
    while (time < TIME_OUT && WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
        time++;
    }
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("");
        Serial.print("WiFi connected to : ");
        Serial.println(ssid);
        Serial.print("IP : ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        WiFi.disconnect();
        Serial.println("");
        Serial.print("Connection timed out.");
    }
}

void RevolvairWebServer::handleClient()
{
    server->handleClient();
}