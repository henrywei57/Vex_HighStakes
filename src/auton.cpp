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
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,20,100,100);  
    intakee.set(0);       
    suk(100);
    wait(350,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    turnToAngle(90);
    driveAndTurn(1.25,167,100,50);
    turnToAngle(150,50);
    driveAndTurn(0.3,270,100,10);   
    driveAndTurn(0.2,237.7775,75,75);   
    // driveAndTurn(-0.3,-150,100,27.5);
    // wait(350,msec);
    driveAndTurn(0.6,257.5,70,100);
    wait(250,msec);
    intas.stop();          
    // mogoclp.set(1);
    // driveAndTurn(0.7,-257.5,70,100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}


void bluer(){
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,-20,100,100);  
    intakee.set(0);       
    suk(100);
    wait(350,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    turnToAngle(-90);
    driveAndTurn(1.25,-167,100,50);
    turnToAngle(-150,50);
    driveAndTurn(0.3,-270,100,10);   
    driveAndTurn(0.2,-235,75,75);   
    // driveAndTurn(-0.3,-150,100,27.5);
    // wait(350,msec);        
    driveAndTurn(0.3,-257.5,70,100);
    wait(250,msec);
    intas.stop();          
    mogoclp.set(1);
    // driveAndTurn(0.7,-257.5,70,100);
}

void redr(){
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,-20,100,100);  
    intakee.set(0);       
    suk(100);
    wait(350,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    turnToAngle(-90);
    driveAndTurn(1,-90,100,50);
    turnToAngle(-25);
    driveAndTurn(2.3,-0,100,100);
    mogoclp.set(1);
    wait(300,msec);
    inta1.stop();
    turnToAngle(-236);
    driveAndTurn(3,-250,100,100);
    mogoclp.set(0);
}
void bluel(){
    intakee.set(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.05;
    driveAndTurn(-1.1,20,100,100);  
    intakee.set(0);       
    suk(100);
    wait(350,msec);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    turnToAngle(90);
    driveAndTurn(1,90,100,50);
    turnToAngle(25);
    driveAndTurn(2.3,0,100,100);
    mogoclp.set(1);
    wait(300,msec);
    inta1.stop();
    turnToAngle(-125);
    driveAndTurn(3,-115,100,100);
    mogoclp.set(0);
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