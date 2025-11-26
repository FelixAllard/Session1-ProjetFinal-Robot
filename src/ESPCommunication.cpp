//
// Created by xilef on 11/25/2025.
//

#include "ESPCommunication.h"

#include <Arduino.h>

#include "Triggers.h"

// Define a type for the callback function
typedef void (*MessageReceivedCallback)(String message);

MessageReceivedCallback onMessageReceived = nullptr; // Pointer to callback

String incomingBuffer = "";  // Buffer for incoming serial data




void SendMessageToESP(String msg) {
    if (Serial3) {                   // Check if Serial3 is initialized
        Serial3.println(msg);        // Send the message, terminated with \n
        Serial.println("Sent to ESP: " + msg); // Optional debug
    }
}


void setMessageReceivedCallback(MessageReceivedCallback callback) {
    onMessageReceived = callback;
}
// -------------------------------
// Example callback
// -------------------------------
void handleMessage(String message) {
    Serial.println("Received message: " + message);
    if (message.indexOf("Connected") >= 0 || message.indexOf("Heart") >= 0) {
        return;
    }

    ReceivedMessage(message);
}


void InitializeESPCommunication() {

    Serial3.begin(115200);

    // Set your callback function
    setMessageReceivedCallback(handleMessage);
}

void UpdateESPCommunication() {
    readIncomingMessages();
}

// -------------------------------
// Call this in loop to read Serial1
// -------------------------------
void readIncomingMessages() {
    while (Serial3.available()) {
        char c = Serial3.read();
        if (c == '\n') {
            incomingBuffer.trim();
            if (onMessageReceived != nullptr) onMessageReceived(incomingBuffer);
            incomingBuffer = "";
        }
        else {
            incomingBuffer += c;
        }
    }
}


