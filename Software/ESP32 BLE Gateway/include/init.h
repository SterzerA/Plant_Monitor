#ifndef INIT_H
#define INIT_H

#include <WiFi.h>
#include <NimBLEDevice.h>
#include "passwords.h"

// SERIAL Configuration
#define SERIAL_BAUD 115200

// Wifi credetials
#define WIFI_SSID MY_WIFI_SSID
#define WIFI_PASSWORD MY_WIFI_PASSWORD

/* UUID's of the service, characteristic that we want to read*/

#define ENVIRONMENTAL_SENSISING_SERVICE_UUID "181A"
#define HUMIDITY_CHARACTERISTIC_UUID "2A6F"

// Parameters for mail send algorithm
#define HUMIDITY_THRESHOLD 0U
#define HUMIDITY_RESET 20U

// Public function rototypes
void initLed(void);
void initSerial(void);
void initWifi(void);
void initBLE(void);

#endif /*INIT_H*/