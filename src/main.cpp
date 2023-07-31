#include <Arduino.h>
#include "WiFi.h"

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    Serial.println("Start scan");
    delay(2500);
}

void loop()
{
    int n = WiFi.scanNetworks();
    if (n == 0) Serial.println("WiFi networks not founded");
    else {
        for (int i = 0; i < n; i++) {
            Serial.print("Name: ");
            Serial.print(WiFi.SSID(i));
            Serial.print(", RSSI: ");
            Serial.print(WiFi.RSSI(i));
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?"| OPEN NETWORK":" | NEED AUTH");
        }
    }
    Serial.println("--- Restart scanning ---");
    delay(10000);
}