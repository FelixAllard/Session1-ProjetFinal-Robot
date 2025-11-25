//
// Created by xilef on 11/25/2025.
//

#ifndef SESSION1_PROJETFINAL_ROBOT_ESPCOMMUNICATION_H
#define SESSION1_PROJETFINAL_ROBOT_ESPCOMMUNICATION_H
#include <WString.h>

void InitializeESPCommunication();
void UpdateESPCommunication();

String getLastMessage();
void readIncomingMessages();

void SendMessageToESP(String msg);
#endif //SESSION1_PROJETFINAL_ROBOT_ESPCOMMUNICATION_H