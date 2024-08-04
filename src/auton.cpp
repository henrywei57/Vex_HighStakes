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
    sped = 0.05;
    driveAndTurn(1.42,33,40,100);
    mogoclp.set(0);
    wait(300,msec);
    suk(100);
    driveAndTurn(-0.62,112,25,100);
    // intas.stop();
    turnToAngle(170);
    driveAndTurn(-0.6,170,100,100);
    driveAndTurn(-1,90,40,100);
    wait(500,msec);
    turnToAngle(315);
    driveAndTurn(-2.3,230,80,100);
    


    // driveAndTurn(-0.9,270,100,50);
}
