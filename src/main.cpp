#include <Arduino.h>
#include "WiFi.h"
int countNetworks;

void setup()
{
    Serial.begin(115200);
    Serial.println("WiFi scanner is started");
    delay(100);
}

void loop()
{
    countNetworks = WiFi.scanNetworks();
    if (countNetworks == 0) Serial.println("WiFi networks not founded");
    else {
        for (int i = 0; i < countNetworks; i++) {
            Serial.print("#");
            Serial.print(i);
            Serial.print(" #"); // SSID
            Serial.print(WiFi.SSID(i));
            Serial.print(" #"); // RSSI
            Serial.println(WiFi.RSSI(i));
        }
    }
    Serial.println("--- RESTART SCAN ---");
    delay(2500);
}