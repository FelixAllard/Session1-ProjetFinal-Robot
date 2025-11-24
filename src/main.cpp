#include <LibRobus.h>
#include <Arduino.h>
#include "Communication.h"
#include "SetupTransmission.h"


bool sentTheMessage = false;
void setup() {

    BoardInit();
    delay(1000);
    Serial.begin(115200);
    InitializeCommunication();
    //InitializeSetupTransmission();
}


void loop() {
    LoopCommunication();
    //LoopSetupTransmission();
}