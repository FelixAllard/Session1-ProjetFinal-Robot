//
// Created by xilef on 11/24/2025.
// Improved non-blocking, long-term stable HC-05 communication
//

#include "Communication.h"

#include <Arduino.h>
#include <HardwareSerial.h>

// HC-05 on Serial1 (pins 18 TX1 / 19 RX1)
#define PING_INTERVAL 200  // milliseconds between heartbeat pings

unsigned long lastPing = 0;

void InitializeCommunication() {
    Serial.begin(115200);      // Serial Monitor
    Serial1.begin(9600);       // HC-05 Bluetooth
    Serial.println("Initializing Communication");
    Serial.println("Finished Initialize Communication");
}

void LoopCommunication() {
    PrintCommunication();

    // Send heartbeat to HC-05 at controlled interval
    if (millis() - lastPing >= PING_INTERVAL) {
        Serial1.println("ping");
        lastPing = millis();
    }
}

void PrintCommunication() {
    // --- Read from HC-05 and print to Serial Monitor ---
    while (Serial1.available() > 0) {
        char c = Serial1.read();   // read one byte
        Serial.write(c);           // echo to Serial Monitor
    }

    // --- Read from Serial Monitor and send to HC-05 ---
    while (Serial.available() > 0) {
        char c = Serial.read();    // read one byte
        Serial1.write(c);          // send to HC-05
    }
}
