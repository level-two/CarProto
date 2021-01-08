#include "types.h"
#include "physical.h"

void setup() {
    setupMotors();
    
    Serial1.begin(115200);
    while (!Serial1);
}

void serialEvent1() {
    while (Serial1.available()) {
        char data = (char) Serial1.read();
        
        if (data < '0' && data > '4') {
            continue; 
        }
        
        Command cmd = (Command) (data - '0');
        execute(cmd);
    }
}

void execute(Command cmd) {
    switch (cmd) {
        case stop:
            enableMotors(0);
            leftMotorDir(0);
            rightMotorDir(0);
            break;
        case moveForward:
            enableMotors(1);
            leftMotorDir(1);
            rightMotorDir(1);
            break;
        case turnRight:
            enableMotors(1);
            leftMotorDir(1);
            rightMotorDir(0);
            break;
        case moveBackward:
            enableMotors(1);
            leftMotorDir(0);
            rightMotorDir(0);
            break;
        case turnLeft:
            enableMotors(1);
            leftMotorDir(0);
            rightMotorDir(1);
            break;
        default:
            break;
    }
}

void loop() {

}
