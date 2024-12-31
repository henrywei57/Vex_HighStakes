#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include "other_function.h"
using namespace vex;
using namespace auton;


void redfffffilter() {
    while (true) {
        int hue = colorseancor.hue();  
        if (hue < 30 && hue>0&&colorseancor.objectDetectThreshold()) {  
            wait(200, msec);  
            intas.stop(hold);  
            con.rumble("-");
            wait(100, msec);  
            suk(100);
        }
        wait(10, msec);  
    }
}



void bluefffffilter() {
    while (true) {
        int hue = colorseancor.hue();  
        if (hue < 300 && hue>80&&colorseancor.objectDetectThreshold()) {  
            wait(200, msec);  
            intas.stop(hold);  
            con.rumble("-");
            wait(100, msec);  
            suk(100);
        }
        wait(10, msec);  
    }
}



bool doIWantItToGoToArm = false;

void reves() {
    while(1){
    while (doIWantItToGoToArm) { 
        suk(90); 

        
        if (aaasssddd.objectDistance(inches) < 1.3) {
            inta1.setPosition(0,degrees);
            inta1.spinToPosition(95,degrees);
            inta2.spin(fwd,80,pct);
            inta1.spin(reverse, 100, pct);
            wait(775, msec);
            inta1.stop(brake);    
            doIWantItToGoToArm = false;     
        }

        wait(10, msec); 
    }
    wait(10, msec); 
    }
}



/*
driveAndTurn(distance, angle, max linear velocity, max turning velocity, stop time, margine of error)
turnToAngle(angle, max turning velocity, stop time, margine of error)
suk(speed)
unsuk(speed)
doIWantItToGoToArm = 1 / turn on redirect
*/

void redl(){}

void bluer(){}

void redr(){}

void bluel(){}

void skill(){}

void test(){
    driveAndTurn(1,0,100,100);
    wait(1,sec);
    driveAndTurn(-1,0,100,100);
    wait(1,sec);
    turnToAngle(90);
    wait(1,sec);
    turnToAngle(270);
    wait(1,sec);
    turnToAngle(180);
    wait(1,sec);
    turnToAngle(360);
    wait(1,sec);
    driveAndTurn(-1,90,100,100);
    wait(1,sec);
    driveAndTurn(1,0,100,100);
}