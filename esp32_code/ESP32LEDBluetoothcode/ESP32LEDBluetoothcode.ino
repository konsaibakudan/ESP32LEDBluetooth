#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLEServer *pServer = nullptr;
BLECharacteristic *pCharacteristic = nullptr;
bool deviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void setup() {
  Serial.begin(115200);

  pinMode(25, OUTPUT);

  // BLEデバイスの初期化
  BLEDevice::init("ESP32_BLE");

  // BLEサービスの作成
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService("YOUR_SERVICE_UUID");

  // BLEキャラクタリスティックの作成
  pCharacteristic = pService->createCharacteristic(
                      "YOUR_CHARACTERISTIC_UUID",
                      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

  pService->start();

  // BLE広告の開始
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(pService->getUUID());
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

void loop() {
  // デバイスが接続されている場合にコマンドを処理する
  if (deviceConnected && pCharacteristic->getValue().length() > 0) {
    String value = pCharacteristic->getValue().c_str();

    if (value == "on") {
      digitalWrite(25, HIGH); // 25番ピンをHIGHに設定
    }else if(value == "off"){
      digitalWrite(25, LOW);
    }
    }
  }
