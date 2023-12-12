# IoT Wireless Sensor Network Project

## Overview

This project is part of the school IoT module, focusing on collecting data from different sensors and sending them to a database for further treatment. The primary objective is to implement the `CO2_sender.ino` and `TH_sender.ino` codes on an STM32 board. These codes are responsible for collecting data from CO2 sensor and temperature and humidity sensor then transmitting them to a Raspberry Pi board using a LoRa module.

The receiver functionality is implemented in the `receiver.cpp` code, which runs on the Raspberry Pi and utilizes a LoRa shield. It is designed to receive signals from multiple STM32 boards. Each time a new packet is received, its content is displayed in the terminal. Additionally, this code performs modifications on the message format and sends it to Python for further processing.

On the Python side, the `mqtt.py` code serves as a listener waiting for data sent from the C code (`receiver.cpp`). Once data is received, it is sent to the corresponding database using the MQTT protocol. 

## Hardware Requirements

- STM32 boards
- Raspberry Pi board
- LoRa module (for communication between STM32 and Raspberry Pi)
- Sensors for data collection (CO2 sensor, temperature and humidity sensor, etc.)

## Implementation

1. Use a LoRa module to transmit data from STM32 to the Raspberry Pi.
2. Implement the `CO2_sender.ino` and `TH_sender.ino` codes on the STM32 boards.
3. Connect sensors to the STM32 board for data collection.
4. Run the `receiver.cpp` code on the Raspberry Pi to collect, display and modify the format of the sensor data.
5. Implement the `mqtt.py` code to listen for data from `receiver.cpp` and send it to the database.

## Future Work

- Database setup for storing collected sensor data.
- Data treatment and analysis processes to extract meaningful insights.

Feel free to contribute, report issues, or suggest improvements!
