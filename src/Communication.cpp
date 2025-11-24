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
    Serial1.begin(9600);       // HC-05 Bluetooth
    Serial.println("Initializing Communication");
    Serial.println("Finished Initialize Communication");
}

void LoopCommunication() {
    ReceiveFromBluetooth();
    ReceiveFromSerialMonitor();

    SendHeartbeat();
}

// --- Function: Receive messages from HC-05 (Unity) ---
String btBuffer = "";

void ReceiveFromBluetooth() {
    while (Serial1.available() > 0) {
        char c = Serial1.read();
        if (c == '\n') {
            // full message received from Unity
            Serial.println("From Unity: " + btBuffer);

            // --- optional: parse commands from Unity ---
            if (btBuffer == "stop_ping") {
                // example: Unity can command Arduino
            }

            btBuffer = "";  // CLEAR BUFFER
        } else {
            btBuffer += c; // add char to buffer
        }
    }
}


// --- Function: Receive messages from Serial Monitor (for testing) ---
void ReceiveFromSerialMonitor() {
    while (Serial.available() > 0) {
        char c = Serial.read();
        Serial1.write(c); // send to Unity
    }
}

// --- Function: Send heartbeat ping to HC-05 ---
void SendHeartbeat() {
    if (millis() - lastPing >= PING_INTERVAL) {
        Serial1.println("ping");
        lastPing = millis();
    }
}

// --- Optional: Send a custom message to Unity ---
void SendToUnity(String message) {
    Serial1.println(message);
    Serial.println("Sent to Unity: " + message); // optional echo
}