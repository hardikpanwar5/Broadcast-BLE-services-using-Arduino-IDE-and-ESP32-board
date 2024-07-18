# Broadcast-BLE-services-using-Arduino-IDE-and-ESP32-board

Here is a step by step guide 
First we need to set up the environment 
1.components required 
  1. ESP32 board because it has in built bluetooth
  2. Arduino IDE 
  3. ESP32 BLE Arduino library of ESP32
    
2. Service Details:

Service UUID: 00000002-0000-0000-FDFD-FDFDFDFDFDFD
Characteristics:
Temperature Measurement (UUID: 2A6E)
Humidity (UUID: 2A6F)
Supported operations: Read and Notify

3. Steps to Run the Code:

Set up the ESP32 development board and connect it to the computer.
Install the necessary libraries in the Arduino IDE (ESP32 BLE Arduino).
Upload the provided code to the ESP32 board.
Use the nRF-Connect app to read the broadcasted values.
