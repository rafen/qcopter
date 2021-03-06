// QCopter.ino
#include <Arduino.h>
#include <Servo.h>
#include "Motors.h"
#include "Flight.h"
#include "SerialCommands.h"

void setup() {
    Serial.begin(115200);
    motorsSetup();
}

void loop() {
    readSerialCommands();
    flight();
}

