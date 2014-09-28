// QCopter.ino
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <PID_v1.h>


#include "Utils.h"
#include "Motors.h"
#include "Stability.h"
#include "Flight.h"
#include "SerialCommands.h"


void setup() {
    Serial.begin(115200);
    stabilitySetup();
    motorsSetup();
}

void loop(){
    readSerialCommands();
    flight();
    stability();
}
