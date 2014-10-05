#ifndef _Flight_h
#define _Flight_h

#define INIT_SPEED 1000

int speed = INIT_SPEED;
int serialSpeed = 0;



void flight(){
    // Calculate general speed
    speed = INIT_SPEED + serialSpeed;

    // Update motor speed if needed
    motorsSetMicroseconds(0, speed + pOut);
}

#endif
