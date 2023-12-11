# ESP32 BLE Server for LED Control
This Arduino code is designed to set up an ESP32 as a Bluetooth Low Energy (BLE) server. It's intended to communicate with a client device, such as a smartphone, via BLE and control a LED based on received commands.

## Features

- **BLE Initialization**: Sets up the ESP32 as a BLE device named "ESP32_BLE".
- **BLE Server Creation**: Establishes a BLE server to handle incoming client connections.
- **Service and Characteristic Setup**: Creates a BLE service with a custom UUID and a characteristic that can read and write data.
- **Connection Handling**: Implements callbacks to manage device connections and disconnections.
- **Command Processing**: Reads the characteristic's value to receive commands. For example, if the command "up" is received, it sets GPIO 25 to HIGH.

## Usage

When a client device sends a command via BLE, this ESP32 server reads the command and controls the motor accordingly. The GPIO 25 pin is used here as an example for motor control.

Please replace `YOUR_SERVICE_UUID` and `YOUR_CHARACTERISTIC_UUID` with your actual UUIDs used in your BLE service and characteristic.
