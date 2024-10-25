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
    mogoclp.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(1.42,40,40,100);
    mogoclp.set(0);
    wait(300,msec);
    inta1.spin(fwd,100,pct);
    inta2.spin(fwd,100,pct);
    driveAndTurn(-0.65,110,30,100);
    // driveAndTurn(-0.5,90,10,100);
    // intas.stop();
    turnToAngle(160);
    driveAndTurn(-0.7,170,100,100);
    driveAndTurn(-0.5,90,36,100);

    wait(300,msec);
    driveAndTurn(-0.5,0,10,100);
    turnToAngle(270);
    driveAndTurn(-3,250,80,100);
    mogoclp.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}


void bluer(){
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,-20,100,100);  
    intakee.set(0);       
    wait(300,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    suk(100);
    turnToAngle(-90);
    driveAndTurn(1.25,-167,100,50);
    turnToAngle(-150);
    driveAndTurn(0.5,-270,100,27.5);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    driveAndTurn(1.3,-250,100,100);
}

void redr(){

}
void bluel(){
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,20,100,100);  
    intakee.set(0);       
    wait(250,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    suk(100);
    intakee.set(0);    
    turnToAngle(90);
    driveAndTurn(1.2,90,100,100);  
    wait(100,msec);
    intas.stop();
    turnToAngle(0);
    driveAndTurn(-1,0,100,100);  
    intakee.set(0);       
    suk(100);
    driveAndTurn(3,-90,100,95);  

}

void test(){
    intakee.set(1);
    sped = 0.05;
    driveAndTurn(-1.5,0);
    intakee.set(0);
    suk(100);
    driveAndTurn(2,-90,50,100);
    wait(10,vex::timeUnits::sec);
    intakee.set(1);
}