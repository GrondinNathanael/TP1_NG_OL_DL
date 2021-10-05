#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> 

class RevolvairAirAPI{
    public:
        RevolvairAirAPI(String url, String token);
        void postJSON(String& encodedJSON);
        void sendPM25ValueToAPI(int pm25);
    private:
        String API_URL;
        String API_TOKEN;
};