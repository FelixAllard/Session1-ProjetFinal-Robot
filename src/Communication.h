//
// Created by xilef on 11/24/2025.
//

#ifndef SESSION1_PROJETFINAL_ROBOT_COMMUNICATION_H
#define SESSION1_PROJETFINAL_ROBOT_COMMUNICATION_H
#include <Arduino.h>
void InitializeCommunication();
void LoopCommunication();
void ReceiveFromBluetooth();
void ReceiveFromSerialMonitor();

void SendHeartbeat();

void SendToUnity(String message);
#endif //SESSION1_PROJETFINAL_ROBOT_COMMUNICATION_H