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
    mogoclp.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.08;
    driveAndTurn(1.25,30,30,100);
    mogoclp.set(0);
    wait(300,msec);
    intas.spin(fwd,100,pct);
    driveAndTurn(-0.9,115,25,100);
    driveAndTurn(-0.9,180,25,100);
    turnToAngle(270);
    // wait(300,msec);
    // driveAndTurn(1,0);
}
