#include "init.h"

// BLE service and characteristic to apss data to main loop
NimBLERemoteCharacteristic *pCharacteristic;
NimBLERemoteService *pService;

void initSerial(void)
{
    // Start serial communication
    Serial.begin(SERIAL_BAUD);
}

void initLed(void)
{
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);
}

void initWifi(void)
{
    // Connect to WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(200);
    }

    // Wenn die Verbindung erfolgreich aufgebaut wurde,
    // dann soll die IP-Adresse auf der seriellen Schnittstelle
    // ausgegeben werden.
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void initBLE(void)
{
    // Connect to  BLE
    Serial.println("Starting Arduino BLE Client application...");
    NimBLEDevice::init("");

    NimBLEScan *pScan = NimBLEDevice::getScan();
    Serial.println("Scanning for devices...");
    NimBLEScanResults results = pScan->start(10);
    Serial.print("Found ");
    Serial.print(results.getCount());
    Serial.println(" Devices");
    NimBLEUUID serviceUuid(ENVIRONMENTAL_SENSISING_SERVICE_UUID);

    for (int i = 0; i < results.getCount(); i++)
    {
        NimBLEAdvertisedDevice device = results.getDevice(i);

        if (device.isAdvertisingService(serviceUuid))
        {
            Serial.println("Found Environmental Sensing device.");
            NimBLEClient *pClient = NimBLEDevice::createClient();

            if (pClient->connect(&device))
            {
                pService = pClient->getService(serviceUuid);
                Serial.println("Device connected");

                if (pService != nullptr)
                {
                    pCharacteristic = pService->getCharacteristic(HUMIDITY_CHARACTERISTIC_UUID);
                    Serial.println("Service found");
                    if (pCharacteristic != nullptr)
                    {
                        uint8_t value = pCharacteristic->readUInt8();
                        // print or do whatever you need with the value
                        Serial.println("Value found");
                        Serial.println(value);
                    }
                }
            }
            else
            {
                Serial.println("No device found");
            }

            // NimBLEDevice::deleteClient(pClient);
        }
    }
}
