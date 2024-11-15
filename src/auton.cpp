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
void redl(){
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
}


void bluer(){

}

void redr(){

}
void bluel(){
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.047;
    driveAndTurn(-1.21,30,100,100);  
    intakee.set(1); 
    // turnToAngle();        
    suk(100);
    turnToAngle(85);
    driveAndTurn(0.9,95,50,100); 
    turnToAngle(-90,80);
    driveAndTurn(1.3,0,50,100); 
}

void test(){

}