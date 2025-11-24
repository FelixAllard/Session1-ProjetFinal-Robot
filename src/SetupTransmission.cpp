//
// Created by xilef on 11/24/2025.
//

#include "SetupTransmission.h"

#include <HardwareSerial.h>

void InitializeSetupTransmission() {
    Serial.begin(9600);
}

void LoopSetupTransmission() {
    if (Serial.available()) Serial.write(Serial.read());
}
