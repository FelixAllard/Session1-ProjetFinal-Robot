#include <Arduino.h>

#include "Communication.h"
#include <LibRobus.h>

void setup() {

    BoardInit();
    delay(1000);
    Serial.begin(115200);
    InitializeCommunication();
}

void loop() {

    LoopCommunication();
// write your code here
}