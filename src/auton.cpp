#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include "other_function.h"
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


void aaassdasd(int x){
    wait(x,msec);
    inta2.spin(reverse,100,pct);
}

bool doIWantItToGoToArm = false;

void reves() {
    while(1){
    while (doIWantItToGoToArm) { // Only run while the flag is true
        suk(100); // Run the intake motor

        // Check sensor distance and execute reverse logic
        if (aaasssddd.objectDistance(inches) < 1.3) {
            intas.spin(fwd, 30, pct); // Run intake forward at 30% power
            wait(60, msec);          // Wait for the action to complete
                intas.spin(reverse, 100, pct);
    wait(750, msec);
    intas.stop(brake);    
            doIWantItToGoToArm = false;     // Stop the motor with brake mode
        }

        wait(20, msec); // Small delay to prevent CPU overload
    }
    wait(20, msec); // Small delay to prevent CPU overload
    }
}


void armbluer(){
    armsmall.set(1);
    wait(500,msec);
    armsmall.set(0);
}
void asd(){
    wait(1000,msec);        
    inta2.stop();
}

void asddd(){
    wait(400,msec);
    suk(100);
}


void redl(){
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    inta2.spin(fwd,20,pct);
    armbig.set(1);
    driveAndTurn(0.853,90, 60, 20);
    armbig.set(0);
    driveAndTurn(-0.1,90, 60, 20,500);
    aaassdasd(300);
    sped = 0.07;
    driveAndTurn(-2,45, 40, 60);
    clamp.set(1);
    sped = 0.05;
    turnToAngle(230,100);
    suk(100);
    driveAndTurn(1.15,180, 80, 100);
    driveAndTurn(0.6,180, 100, 100);
    turnToAngle(90,65,400);
    driveAndTurn(0.6,70, 100, 100);
    inta2.spin(reverse,100,pct);
    turnToAngle(-5);
    driveAndTurn(2,30, 100, 100);

}

bool xxxxx = 1;
void redfffffilter() {
    while (xxxxx) {
        int hue = colorseancor.hue();  // Get current hue value
        if (hue < 30 && hue>0&&colorseancor.objectDetectThreshold()) {  // Check hue and object detection
            wait(200, msec);  // Debounce delay
            intas.stop(hold);  // Stop intake motor
            con.rumble("-");
            wait(100, msec);  // Hold for 1 second
            suk(100);
        }
        wait(10, msec);  // Reduce CPU usage
    }
}


void bluer(){
    vex::thread adaffedad(redfffffilter);
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    inta2.spin(fwd,20,pct);
    armbig.set(1);
    driveAndTurn(0.853,-90, 60, 20);
    armbig.set(0);
    driveAndTurn(-0.1,-90, 60, 20,500);
    aaassdasd(315);
    sped = 0.07;
    driveAndTurn(-2,-45, 40, 60);
    clamp.set(1);
    sped = 0.05;
    turnToAngle(-230,100);
    suk(100);
    driveAndTurn(1.15,-180, 80, 100);
    driveAndTurn(0.6,-180, 100, 100);
    turnToAngle(-90,-65);
    driveAndTurn(0.6,-80, 100, 100);
    turnToAngle(-5);
    driveAndTurn(2,-30, 100, 100);
}

void armbluel(){
    armsmall.set(1);
    wait(700,msec);
    armsmall.set(0);
}

void armredl(){
    wait(500,msec);
    inta2.stop();
}

void redr(){
    // vex::thread([]() {
    // colorFilterR();
    // });   / 
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    driveAndTurn(2, 16, 100,100);
    // vex::thread armThread(armredl);
    armsmall.set(1);
    wait(150,msec);
    driveAndTurn(-0.7, 100, 100,95,1000);
    armsmall.set(0);
    suk(100);
    clamp.set(1);
    wait(550,msec);
    clamp.set(0);
    turnToAngle(-90);
    driveAndTurn(-0.9, -10, 100,80);
    clamp.set(1);
    turnToAngle(-180);
    driveAndTurn(0.6, -170, 100,100);
    vex::thread armThread(armredl);
    turnToAngle(-237.5);
    armsmall.set(1);
    driveAndTurn(2.5, -270, 100,90);
    turnToAngle(-360);
    suk(100);
    armsmall.set(0);
    driveAndTurn(1.4, -350, 100,100);
}



void bluel(){
    // vex::thread([]() {
    // colorFilterR();
    // });   / 
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    driveAndTurn(1.8, -42, 100,100);
    vex::thread armThread(armbluel);
    driveAndTurn(-0.7, -100, 100,90,1000);
    armsmall.set(0);
    clamp.set(1);
    suk(100);
    wait(550,msec);
    clamp.set(0);
    turnToAngle(105);
    driveAndTurn(-1.13, 100, 80,100,950);
    clamp.set(1);
    suk(100);
    turnToAngle(250);
    driveAndTurn(0.45, 250, 100,100,700);
    turnToAngle(190);
    armsmall.set(1);
    driveAndTurn(2.4, 170, 100,100);
    turnToAngle(90);    
    armsmall.set(0);
    turnToAngle(185,800);
    suk(100);
    driveAndTurn(0.55, 200, 100,100,900);
    driveAndTurn(-4, 270, 100,75);
}


bool testCheck = false;


void colorFilterTest(){
    while(1){
    while (doIWantItToGoToArm) { // Only run while the flag is true
        suk(100); // Run the intake motor
        int detectedColor = colorseancor.hue();

        // Check sensor distance and execute reverse logic
        if ((aaasssddd.objectDistance(inches) < 1.3)&&(detectedColor >= 138 && detectedColor<=208)) {
            intas.spin(fwd, 30, pct); // Run intake forward at 30% power
            wait(60, msec);          // Wait for the action to complete
                intas.spin(reverse, 100, pct);
    wait(750, msec);
    intas.stop(brake);    
            doIWantItToGoToArm = false;     // Stop the motor with brake mode
        }

        wait(20, msec); // Small delay to prevent CPU overload
    }
    wait(20, msec); // Small delay to prevent CPU overload
    }
}

void test(){
    colorseancor.setLightPower(100,pct);
clamp.set(1);
suk(100);
// Start the reves thread
doIWantItToGoToArm = true;   
vex::thread revesThread(colorFilterTest);

// Wait for the reves task to complete based on your autonomous logic
wait(150, msec);  // Allow time for the function to execute

// Reset the flag externally after a delay or condition
revesThread.join();  // Ensure the thread finishes cleanly

}


void bluele(){ //remember to change for redr
    // vex::thread([]() {
    // colorFilterR();
    // });   / 
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    driveAndTurn(1.8, -42, 100,100);
    vex::thread armThread(armbluel);
    driveAndTurn(-0.85, -100, 100,90,1000);
    armsmall.set(0);
    clamp.set(1);
    suk(100);
    turnToAngle(-45);
    clamp.set(0);
    turnToAngle(-100);
    turnToAngle(105);
    driveAndTurn(-1.13, 100, 80,100,950);
    clamp.set(1);
    suk(100);
    turnToAngle(250);
    driveAndTurn(0.45, 250, 100,100,700);
    turnToAngle(190);
    armsmall.set(1);
    driveAndTurn(2.4, 170, 100,100);
    turnToAngle(90);    
    armsmall.set(0);
    turnToAngle(185,800);
    suk(100);
    driveAndTurn(0.55, 200, 100,100,900);
    turnToAngle(45);
    driveAndTurn(-0.3, 45, 100,100,900);
}

void redle(){ //can copy paste into bluer, change degree 
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    suk(60);
    armbig.set(1);
    driveAndTurn(0.853,90, 60, 20);
    armbig.set(0);
    driveAndTurn(-0.1,90, 60, 20,500);
    driveAndTurn(-2,45, 40, 60);
    clamp.set(1);
    turnToAngle(225);
    suk(100);
    driveAndTurn(1,180, 70, 100);
    driveAndTurn(0.6,180, 30, 100);
    turnToAngle(90,60);
    vex::thread asdd(asd);
    driveAndTurn(3,-45, 70, 100);
}



void asdasdasd(){
    bool x = true;
    while(x){
    if(aaasssddd.objectDistance(inches) <= 1.3){
        intas.stop();
        x = false;
    }
    }
}

void soloawp(){
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    inta2.spin(fwd,20,pct);
    armbig.set(1);
    driveAndTurn(0.853,90, 60, 20);
    armbig.set(0);
    driveAndTurn(-0.1,90, 60, 20,500);
    aaassdasd(300);
    sped = 0.07;
    driveAndTurn(-2,45, 40, 60);
    clamp.set(1);
    sped = 0.05;
    turnToAngle(225,100,800);
    suk(100);
    driveAndTurn(1.15,180, 75, 100);
    driveAndTurn(0.6,180, 100, 100);
    turnToAngle(90,65,400);
    clamp.set(0);
    inta1.stop();
    driveAndTurn(0.6,90, 100, 100,500);
    turnToAngle(175,100,500);
    driveAndTurn(-2.3,180, 100, 80,1200);
    driveAndTurn(-1.5,235, 100, 100,1000);
    suk(100);
    clamp.set(1);
    turnToAngle(270);
    // armsmall.set(1);
    // turnToAngle(180);
    
}