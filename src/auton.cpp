#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;
/*
setHeading(angle): It sets the initial position of the robot
driveAndTurn(distance, angle, max linear velosity, max turning velosity)
sped(speed): Sets the linear max velosity for the driveAndTurn function, the Default is 0.05
turnToAngle(angle, max turning velosity)
suk(speed): Use the intake
unsuk(speed): Use the outtake
*/
void close_qua(){
    sped = 0.05;
    setHeading(0);
    suk(100);
    sped = 0.055;
    driveAndTurn(-1.72, 23, 100, 100);
    turnToAngle(0);
    driveAndTurn(0.05, 15, 100, 100);
    turnToAngle(89);
    inta.stop(hold);
    intawing2.set(1);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-1.15, 100, 100, 100);
    sped = 0.05;
    intawing2.set(0);
    driveAndTurn(0.2, 90, 100, 100);
    driveAndTurn(0.36, 45, 30, 100);
    // turnToAngle(45);
    driveAndTurn(2.02, 50, 100, 100);
    turnToAngle(-30);
    dropdown.set(1);
    driveAndTurn(0.6, -85, 97, 100);
    dropdown.set(0);
    sped = 0.1;
    driveAndTurn(1.33, -90, 100, 100);

}
