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
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    driveAndTurn(0.76,80,100,22);
    driveAndTurn(-0.1,80,100,100);  
    mogoclp.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    wait(400,msec);
    turnToAngle(45);
    driveAndTurn(-1.8,75,55,100);   
    intakee.set(1);  
    turnToAngle(180);
    suk(100);
    driveAndTurn(1.4,180,100,100);
    turnToAngle(270);
    driveAndTurn(0.55,290,100,100);
    turnToAngle(360);
    driveAndTurn(1,365,100,100);

}


void bluer(){

}

void redr(){
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.047;
    turnToAngle(-5);
    driveAndTurn(-1.26,-32,100,100);  
    intakee.set(1); 
    // turnToAngle();        
    suk(100);
    turnToAngle(-90);
    driveAndTurn(1,-100,50,100); 
    turnToAngle(70,60);
    intas.stop();
    intakee.set(0);  
    unsuk(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    driveAndTurn(2.4, 70, 100,100);
    suk(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    turnToAngle(-0);
    // turnToAngle(0);
    mogoclp.set(1);
    wait(250,msec);
    driveAndTurn(1.2,-5,30,100);
    mogoclp.set(0); 
    wait(200,msec);
    driveAndTurn(-2,-0,100,100);
}
void bluel(){
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.047;
    driveAndTurn(-1.26,32,100,100);  
    intakee.set(1); 
    // turnToAngle();        
    suk(100);
    turnToAngle(90);
    driveAndTurn(1,100,50,100); 
    inta2.stop();
    turnToAngle(-70,100);
    intakee.set(0);  
    suk(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    driveAndTurn(2.3, -72.5, 100,100);
    turnToAngle(0);
    // turnToAngle(0);
    mogoclp.set(1);
    wait(250,msec);
    driveAndTurn(0.845,-2.45,30,100);
    mogoclp.set(0); 
    wait(400,msec);
    driveAndTurn(-1.5,0,100,100);
}

void test(){

}