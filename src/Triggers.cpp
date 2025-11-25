//
// Created by xilef on 11/24/2025.
//


#include "Triggers.h"
#include <Arduino.h>
#include <HardwareSerial.h>

#include "Communication.h"

//format de message: AV, AF
void ReceivedMessage(String message)
{
    char messageReceived;
    if (message.length() > 1)
    {
        Serial.println("Wrong Message " + message);
        return;
    }

    messageReceived = message.charAt(0);



    switch (messageReceived)
    {
        //america del norte
        case 'A':

        TurnDegrees(15);
        moveDistanceBoth(50);

        delay(500);

        TurnDegrees(165);

        moveDistanceBoth(45);

        TurnDegrees(60);

        SendToUnity("Success");
        //Calibrer()


        //america del sur
        case 'B':

        TurnDegrees(70);
        moveDistanceBoth(35);
        delay(2000);
        TurnDegrees(170);
        moveDistanceBoth(20);

        //Calibrer();

        delay(2000);

        //europa
        case 'C':

        TurnDegrees(60);
        delay(10);
        moveDistanceBoth(85);
        delay(500);
        TurnDegrees(167);
        moveDistanceBoth(67);
        delay(10);

        //Calibrer();


        //asia
        case 'D':

        TurnDegrees(70);
        delay(10);
        moveDistanceBoth(105);
        delay(200);
        TurnDegrees(175);
        moveDistanceBoth(90);

        //Calibrer();

        //africa
        case 'E':

        TurnDegrees(75);
        moveDistanceBoth(75);
        delay(200);
        TurnDegrees(180);
        delay(10);
        moveDistanceBoth(55);

        //oceania
        case 'F':
        TurnDegrees(85);
        delay(10);
        moveDistanceBoth(120);
        delay(200);
        TurnDegrees(175);
        delay(10);
        moveDistanceBoth(100);
    }
}