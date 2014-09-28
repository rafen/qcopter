#ifndef _Motors_h
#define _Motors_h

#define CNT_MOTORS 4

#define MOTOR_LOW 0
#define MOTOR_HIGH 120
#define MOTOR_LOW_MICROSECONDS 0
#define MOTOR_HIGH_MICROSECONDS 2000
#define MOTOR_INIT_SPEED 30
#define MOTOR_INIT_DELAY 1000

#define MOTOR_LOCK
#define MOTOR_DEBUG_LEVEL 1

// Create Servo objects for the four motors
Servo motors[CNT_MOTORS];


void motorsSetup(){
    /**
    Configure Servo varible to manage motors and enable
    ESC (Electronic Speed Control).
    */

    #ifdef MOTOR_LOCK
        // wait for ready
        Serial.println(F("\nSend any character to arm motors: "));
        while (Serial.available() && Serial.read()); // empty buffer
        while (!Serial.available());                 // wait for data
        while (Serial.available() && Serial.read()); // empty buffer again
    #endif

    // Connect motors to pins
    motors[0].attach(8);
    motors[1].attach(9);
    motors[2].attach(10);
    motors[3].attach(11);

    // Enable ESC
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

void setMotor(int motor, int value){
    /**
    Set speed of the given motor. The speed will be limited to the range of
    MOTOR_LOW, MOTOR_HIGH

    @param motor Index of the motor to set the speed
    @param value Speed to be set to motor
    @return Void
    */
    value = constrain(value, MOTOR_LOW, MOTOR_HIGH),
    motors[motor].write(value);

    #if MOTOR_DEBUG_LEVEL >= 1
        Serial.print("Write motor ");
        Serial.print(motor);
        Serial.print(" to ");
        Serial.println(value);
    #endif
}

void setMotorMicroseconds(int motor, int value){
    /**
    Set speed in microseconds of the given motor. The speed will be limited to the range of
    MOTOR_LOW_MICROSECONDS, MOTOR_HIGH_MICROSECONDS

    @param motor Index of the motor to set the speed
    @param value Speed to be set to motor
    @return Void
    */
    value = constrain(value, MOTOR_LOW_MICROSECONDS, MOTOR_HIGH_MICROSECONDS);
    
    if(value != motors[0].readMicroseconds()){
        motors[motor].writeMicroseconds(value);
    
        #if MOTOR_DEBUG_LEVEL >= 1
            Serial.print("Set microseconds motor ");
            Serial.print(motor);
            Serial.print(" to ");
            Serial.println(value);
        #endif
    }  
}

#endif
