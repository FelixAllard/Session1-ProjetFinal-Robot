#ifndef LINEFOLLOW_H
#define LINEFOLLOW_H


void LineFollowSetup();
void updateFollower();
void testCapteursDetail();
bool isLineDetected();
bool isCenterDetected();
bool isRightDetected();
bool isLeftDetected();
bool isThreeOn();
bool isOnlyCenter();

extern int leftVal;
extern int centerVal;
extern int rightVal;

#endif
