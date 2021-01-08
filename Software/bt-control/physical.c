#include <Arduino.h>
#include "physical.h"

#define EN_PIN 51
#define DIR0_PIN 52
#define DIR1_PIN 53

void setupMotors() {
    pinMode(EN_PIN, OUTPUT);
    pinMode(DIR0_PIN, OUTPUT);
    pinMode(DIR1_PIN, OUTPUT);
    
    digitalWrite(EN_PIN, LOW);
    digitalWrite(DIR0_PIN, LOW);
    digitalWrite(DIR1_PIN, LOW);
}

void enableMotors(int en) {
    digitalWrite(EN_PIN, en ? HIGH : LOW);
}

void leftMotorDir(int dir) {
    digitalWrite(DIR0_PIN, dir ? HIGH : LOW);
}

void rightMotorDir(int dir) {
    digitalWrite(DIR1_PIN, dir ? HIGH : LOW);
}
