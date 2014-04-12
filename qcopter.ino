// QCopter.ino
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
#include "MPU6050.h"

#include "Motors.h"
#include "Flight.h"
#include "SerialCommands.h"


void setup() {
    Serial.begin(115200);
    motorsSetup();
    gyroSetup();
}

void qLoop(){
    // Add Custom code here  
    readSerialCommands();
    flight();
}

// Wrapped loop for MPU
void loop() {
    mpuLoop(qLoop);
}

