#include <NimBLEDevice.h>
#include <WiFi.h>
#include <ESP_Mail_Client.h>
#include "passwords.h"

// BLE Server name (the other ESP32 name running the server sketch)
#define bleServerName "MY_HUMI"
// Wifi credetials
#define WIFI_SSID MY_WIFI_SSID
#define WIFI_PASSWORD MY_WIFI_PASSWORD

// define mail configuration
#define SMTP_HOST MY_SMTP_HOST
#define SMTP_PORT MY_SMTP_PORT
#define AUTHOR_EMAIL MY_AUTHOR_EMAIL
#define AUTHOR_PASSWORD MY_AUTHOR_PASSWORD

/* UUID's of the service, characteristic that we want to read*/

#define ENVIRONMENTAL_SENSISING_SERVICE_UUID "181A"

#define HUMIDITY_CHARACTERISTIC_UUID "2A6F"
#define HUMIDITY_THRESHOLD 0U
#define HUMIDITY_RESET 20U

static NimBLEUUID humidityCharacteristicUUID;
static NimBLERemoteCharacteristic *pCharacteristic;
static NimBLERemoteService *pService;

SMTPSession smtp;
static bool bMailStatus = false;

void smtpCallback(SMTP_Status status);

void sendMail(void);

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  // Start serial communication
  Serial.begin(115200);

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
  // NimBLEUUID humidityCharacteristicUUID("00002a6f-0000-1000-8000–00805f9b34fb");

  for (int i = 0; i < results.getCount(); i++)
  {
    NimBLEAdvertisedDevice device = results.getDevice(i);

    if (device.isAdvertisingService(serviceUuid))
    {
      Serial.println("Found Environmenta Sensing device.");
      NimBLEClient *pClient = NimBLEDevice::createClient();

      if (pClient->connect(&device))
      {
        NimBLERemoteService *pService = pClient->getService(serviceUuid);
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

void loop()
{
  uint8_t intHumidity = 0;

  intHumidity = pCharacteristic->readUInt8();
  // pCharacteristic = pService->getCharacteristic("2a6f");
  Serial.println(intHumidity);

  if (intHumidity <= HUMIDITY_THRESHOLD && bMailStatus == false)
  {
    sendMail();
    bMailStatus = true;
  }
  else if (intHumidity > HUMIDITY_RESET && bMailStatus == true)
  {
    bMailStatus = false;
  }
  else
  {
    // do nothing
  }

  // toggle LED to show BAord is alive
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}

void sendMail(void)
{

  // Debug Meldungen anzeigen
  smtp.debug(1);
  // Ein Callback definieren welcher nach dem Senden der Mail ausgeführt werden soll.
  smtp.callback(smtpCallback);
  // Mail Session
  ESP_Mail_Session session;
  // Serverdaten setzen
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = SMTP_HOST;
  // Wenn keine Verbindung aufgebaut werden konnte soll die Funktion verlassen werden.
  if (!smtp.connect(&session))
  {
    return;
  }
  // Aufbau der E-Mail
  SMTP_Message message;
  // Im Header kann man recht einfach dem Absender Faken
  message.sender.name = "Mail from Humidity Sensor";     // steht bei "gesendet von"
  message.sender.email = MY_AUTHOR_EMAIL;                // der Absender (oder eine Fake E-Mail)
  message.subject = "Soil Humidity Low!";                // der Betreff der E-Mail
  message.addRecipient(MY_RECIPIENT, MY_RECIPIENT_MAIL); // der Empfänger
  // Aufbau des Contents der E-Mail
  String textMsg = "Please water me!";
  message.text.content = textMsg.c_str();
  message.text.charSet = "utf-8";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  // Eine eindeutige ID welche die Mail kennzeichnet
  // zwischen den spitzen Klammern kann ein Wert xyz@domain.com eingetragen werden
  message.addHeader(MY_MESSAGE_ID);
  // Absenden der E-Mail
  if (!MailClient.sendMail(&smtp, &message))
  {
    // Im Fehlerfall wird der Grund auf der seriellen Schnittstelle ausgegeben.
    Serial.println("Error sending Email, " + smtp.errorReason());
  }
  ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
  return;
}

// Der Callback welcher ausgeführt werden soll wenn das versenden der E-Mail erfolgte.
void smtpCallback(SMTP_Status status)
{
  Serial.println(status.info());
  if (status.success())
  {
    Serial.println("----------------");
    ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
    ESP_MAIL_PRINTF("Message sent failled: %d\n", status.failedCount());
    Serial.println("----------------\n");
    struct tm dt;
    for (size_t i = 0; i < smtp.sendingResult.size(); i++)
    {
      /* Get the result item */
      SMTP_Result result = smtp.sendingResult.getItem(i);
      time_t ts = (time_t)result.timestamp;
      localtime_r(&ts, &dt);
      ESP_MAIL_PRINTF("Message No: %d\n", i + 1);
      ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
      ESP_MAIL_PRINTF("Date/Time: %d/%d/%d %d:%d:%d\n", dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
      ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients);
      ESP_MAIL_PRINTF("Subject: %s\n", result.subject);
    }
    Serial.println("----------------\n");
    // smtp.sendingResult.clear();
  }
}