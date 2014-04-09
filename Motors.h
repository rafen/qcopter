#ifndef _Motors_h
#define _Motors_h

#define CNT_MOTORS 4

#define MOTOR_LOW 0
#define MOTOR_HIGH 120
#define MOTOR_INIT_SPEED 30
#define MOTOR_INIT_DELAY 1000

// Create Servo objects for the four motors
Servo motors[CNT_MOTORS];

void motorsSetup(){
    // Connect motors to pins
    motors[0].attach(8);
    motors[1].attach(9);
    motors[2].attach(10);
    motors[3].attach(11);

    // Enable motors
    for(int i=0; i<CNT_MOTORS; i++){
        motors[i].write(MOTOR_LOW);
    }
    Serial.println("Arming Motors...");
    delay(MOTOR_INIT_DELAY);
    for(int i=0; i<CNT_MOTORS; i++){
        motors[i].write(MOTOR_HIGH);
    }
    delay(MOTOR_INIT_DELAY);
    for(int i=0; i<CNT_MOTORS; i++){
        motors[i].write(MOTOR_INIT_SPEED);
    }
    Serial.println("Motors Armed!");
}

#endif
