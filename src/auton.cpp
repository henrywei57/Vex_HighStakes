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
void test(){
    setHeading(0);
    sped = 0.048;
    driveAndTurn(1.2,0,100,100);
    mogoclp.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    // driveAndTurn(1,0);
}
