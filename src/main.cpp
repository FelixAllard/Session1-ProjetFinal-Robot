#include <LibRobus.h>
#include <Arduino.h>

#include "ESPCommunication.h"
#include "Triggers.h"
#include "LineFollow.h"


bool sentTheMessage = false;
char message = 'A';
bool centre = true;

void setup() {

    BoardInit();
    delay(1000);
    Serial.begin(115200);
    InitializeESPCommunication();
}
/*
void Calibrer()
{
    while (!isLineDetected())
    {
        moveDistanceBoth(3);
        delay(10);
    }

    delay(10);



    while (!isThreeOn())
    {
        updateFollower();
        Serial.println(isThreeOn());
    }

    delay(10);
    TurnDegrees(-90);
    delay(10);

    moveDistanceBoth(5);

    while (!isOnlyCenter())
    {
        updateFollower();
    }

    TurnDegrees(180);


    delay(10);

    centre = false;
}
*/
float time = 0;
void loop() {

    if (millis() - time > 5000) {
        SendMessageToESP("HelloWorld");
        time = millis();
    }

    UpdateESPCommunication();
}

