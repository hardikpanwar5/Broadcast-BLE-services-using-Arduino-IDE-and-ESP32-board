#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID "00000002-0000-0000-FDFD-FDFDFDFDFDFD"
#define CHARACTERISTIC_TEMPERATURE_UUID "2A6E" // Standard Temperature Measurement UUID
#define CHARACTERISTIC_HUMIDITY_UUID "2A6F"    // Standard Humidity UUID

BLECharacteristic *temperatureCharacteristic;
BLECharacteristic *humidityCharacteristic;

void setup() {
  Serial.begin(115200);

  BLEDevice::init("ESP32_BLE");

  // below i am creating a BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // and this will be BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // and this is BLE Characteristics
  temperatureCharacteristic = pService->createCharacteristic(
                              CHARACTERISTIC_TEMPERATURE_UUID,
                              BLECharacteristic::PROPERTY_READ |
                              BLECharacteristic::PROPERTY_NOTIFY);
                              
  humidityCharacteristic = pService->createCharacteristic(
                           CHARACTERISTIC_HUMIDITY_UUID,
                           BLECharacteristic::PROPERTY_READ |
                           BLECharacteristic::PROPERTY_NOTIFY);
  
  // Starting the service
  pService->start();

  // Start 
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // here is a functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  Serial.println("Waiting a client connection to notify...");
}

void loop() {
  // Simulate Temperature and Humidity values
  float temperature = random(20, 30) + random(0, 100) / 100.0;
  float humidity = random(30, 70) + random(0, 100) / 100.0;

  // Notifing temperature and humidity values
  temperatureCharacteristic->setValue(temperature);
  temperatureCharacteristic->notify();
  
  humidityCharacteristic->setValue(humidity);
  humidityCharacteristic->notify();

  delay(2000); // Delay between notifications
}
