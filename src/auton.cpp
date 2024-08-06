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
    driveAndTurn(1.42,40,40,100);
    mogoclp.set(0);
    wait(300,msec);
    suk(100);
    driveAndTurn(-0.62,110,30,100);
    // intas.stop();
    turnToAngle(170);
    driveAndTurn(-0.6,170,100,100);
    driveAndTurn(-1.5,90,36,100);

    wait(300,msec);
    driveAndTurn(-0.5,0,10,100);
    turnToAngle(270);
    driveAndTurn(-3,250,80,100);
    mogoclp.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

    // driveAndTurn(-8,-90,10,100,1000000);
    // intakee.set(1);

    // driveAndTurn(-0.9,270,100,50);
}
void test1(){
    mogoclp.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(1.42,-40,40,100);
    mogoclp.set(0);
    wait(300,msec);
    suk(100);
    driveAndTurn(-0.62,-110,30,100);
    // intas.stop();
    turnToAngle(-170);
    driveAndTurn(-0.6,-170,100,100);
    driveAndTurn(-1.5,-90,38,100);

    wait(300,msec);
    driveAndTurn(-0.5,0,10,100);
    turnToAngle(-270);
    driveAndTurn(-3,-250,80,100);
    // driveAndTurn(-8,-90,10,100,1000000);
    // intakee.set(1);

    // driveAndTurn(-0.9,270,100,50);
}
