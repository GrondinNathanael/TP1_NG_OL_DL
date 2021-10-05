#include "RevolvairAirAPI.h"

RevolvairAirAPI::RevolvairAirAPI(String url, String token)
{
  API_URL = url;
  API_TOKEN = token;
}

void RevolvairAirAPI::postJSON(String& encodedJSON) {
 HTTPClient http;
 http.begin(API_URL);
 http.addHeader("Accept", "application/json");
 http.addHeader("Content-Type", "application/json");
 http.addHeader("Authorization", "Bearer " + String(API_TOKEN));
 int httpCode = http.POST(encodedJSON);
 String payload = http.getString();
 Serial.println(httpCode);
 Serial.println(payload);
 http.end();
}


void RevolvairAirAPI::sendPM25ValueToAPI(int pm25){
 DynamicJsonDocument doc(1024);
 doc["value"] = String(pm25);
 doc["unit"] = "μm/m³";
 String jsonPm25Package = "";
 serializeJson(doc, jsonPm25Package);
 postJSON(jsonPm25Package);
}
