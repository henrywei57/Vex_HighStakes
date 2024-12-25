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



bool xxxxxx = 1;
void bluefffffilter() {
    while (xxxxxx) {
        int hue = colorseancor.hue();  // Get current hue value
        if (hue < 300 && hue>80&&colorseancor.objectDetectThreshold()) {  // Check hue and object detection
            wait(200, msec);  // Debounce delay
            intas.stop(hold);  // Stop intake motor
            con.rumble("-");
            wait(100, msec);  // Hold for 1 second
            suk(100);
        }
        wait(10, msec);  // Reduce CPU usage
    }
}


void aaassdasd(int x){
    wait(x,msec);
    inta2.spin(reverse,100,pct);
}

bool doIWantItToGoToArm = false;

void reves() {
    while(1){
    while (doIWantItToGoToArm) { // Only run while the flag is true
        suk(90); // Run the intake motor

        // Check sensor distance and execute reverse logic
        if (aaasssddd.objectDistance(inches) < 1.3) {
            inta1.setPosition(0,degrees);
            inta1.spinToPosition(95,degrees);
            inta2.spin(fwd,80,pct);
            inta1.spin(reverse, 100, pct);
            wait(775, msec);
            inta1.stop(brake);    
            doIWantItToGoToArm = false;     // Stop the motor with brake mode
        }

        wait(10, msec); // Small delay to prevent CPU overload
    }
    wait(10, msec); // Small delay to prevent CPU overload
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
    vex::thread iglhlggerhjfgwkuyg(bluefffffilter);
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
    turnToAngle(90,65);
    driveAndTurn(0.6,70, 100, 100);
    turnToAngle(45);
    inta2.spin(reverse,100,pct);
    driveAndTurn(4,0, 70, 100);

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
    turnToAngle(-45);
    inta2.spin(reverse,100,pct);
    driveAndTurn(4,0, 70, 100);
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
    vex::thread iglhlggerhjfgwkuyg(bluefffffilter);
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
    driveAndTurn(2.5, -275, 100,90);
    turnToAngle(-305);
    suk(100);
    armsmall.set(0);
}



void bluel(){
    vex::thread asdfefiubhfrvcu(redfffffilter);
    // vex::thread([]() {
    // colorFilterR();
    // });   / 
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    driveAndTurn(1.8, -42, 100,100,1350);
    vex::thread armThread(armbluel);
    driveAndTurn(-0.7, -100, 100,90,1000);
    armsmall.set(0);
    clamp.set(1);
    suk(100);
    wait(550,msec);
    clamp.set(0);
    turnToAngle(105,700);
    driveAndTurn(-1.13, 100, 80,100,950);
    clamp.set(1);
    suk(100);
    turnToAngle(250,500);
    driveAndTurn(0.45, 250, 100,100,500);
    turnToAngle(190);
    armsmall.set(1);
    driveAndTurn(2.4, 170, 100,100);
    turnToAngle(90,800);  
    sped = 1;
    driveAndTurn(0.2, 90, 100,100,350);
    driveAndTurn(-0.2, 90, 100,100,200);  
    sped = 0.05;
    armsmall.set(0);
    turnToAngle(190,800);
    
    suk(100);
    driveAndTurn(1, 90, 50,100);
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




void bluele(){ //remember to change for redr
    vex::thread asdfefiubhfrvcu(redfffffilter);
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
    vex::thread iglhlggerhjfgwkuyg(bluefffffilter);
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


void soloawpb(){
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    inta2.spin(fwd,20,pct);
    armbig.set(1);
    driveAndTurn(0.853,-90, 60, 20);
    armbig.set(0);
    driveAndTurn(-0.1,-90, 60, 20,500);
    aaassdasd(300);
    sped = 0.07;
    driveAndTurn(-2,-45, 40, 60);
    clamp.set(1);
    sped = 0.05;
    turnToAngle(-240,100,800);
    suk(100);
    driveAndTurn(1.15,-180, 75, 100);
    driveAndTurn(0.6,-180, 100, 100);
    turnToAngle(-90,65,400);
    clamp.set(0);
    inta1.stop();
    driveAndTurn(0.6,-90, 100, 100,500);
    turnToAngle(-170,100);
    driveAndTurn(-2.3,-170, 100, 80,1200);
    driveAndTurn(-1.5,-235, 100, 100,1000);
    suk(100);
    clamp.set(1);
    turnToAngle(-270);
    armbig.set(1);
    // armsmall.set(1);
    // turnToAngle(180);
    
}




void soloawpr(){
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
    turnToAngle(235,100,800);
    suk(100);
    driveAndTurn(1.15,180, 75, 100);
    driveAndTurn(0.6,180, 100, 100);
    turnToAngle(90,65,400);
    clamp.set(0);
    inta1.stop();
    driveAndTurn(0.6,90, 100, 100,500);
    turnToAngle(165,100);
    driveAndTurn(-2.3,165, 100, 80,1200);
    driveAndTurn(-1.5,235, 100, 100,1000);
    suk(100);
    clamp.set(1);
    turnToAngle(270);
    armbig.set(1);
    // armsmall.set(1);
    // turnToAngle(180);
    
}



// void skill(){
//     vex::thread asdasdouuh(reves);
//     sped = 0.05;
//     clamp.set(0);
//     setHeading(0);
//     inta1.spin(fwd,100,pct);
//     vex::wait(200,msec);
//     driveAndTurn(0.4,100,75,100);
//     driveAndTurn(-1.2,100,100,100);
//     clamp.set(1);
//     suk(100);
//     turnToAngle(-5);
//     driveAndTurn(1,0,100,100);
//     turnToAngle(45);
//     inta1.stop();
//     driveAndTurn(1.6,45,100,100);
//     suk(100);
//     turnToAngle(-45);
//     inta1.stop();
//     driveAndTurn(1.65,-45,100,100);
//     suk(100);
//     turnToAngle(-90);
//     intas.stop();
//     doIWantItToGoToArm = true;
//     driveAndTurn(0.9,-90,100,100);
//     turnToAngle(-180);
//     driveAndTurn(1,-180,100,100);
//     armbig.set(1);
//     turnToAngle(-90);
//     driveAndTurn(1.19,-90,100,100);
//     doIWantItToGoToArm = false;
//     armbig.set(0);
//     wait(150,msec);
//     driveAndTurn(-0.9,-90,100,100);
//     intas.stop();
//     doIWantItToGoToArm = true;
//     wait(1000,msec);
//     armbig.set(1);
//     driveAndTurn(0.95,-87.5,100,100);
//     doIWantItToGoToArm = false;
//     armbig.set(0);
//     wait(100,msec);
//     driveAndTurn(-0.5,-90,10,100);
//     turnToAngle(-15);
//     suk(100);
//     driveAndTurn(2,0,100,100);
// }
void skill(){
    vex::thread asdasdouuh(reves);
    sped = 0.05;
    clamp.set(0);
    setHeading(0);
    inta1.spin(fwd,100,pct);
    vex::wait(200,msec);
    driveAndTurn(0.4,100,75,100,650);
    driveAndTurn(-1.2,100,100,100);
    clamp.set(1);
    suk(100);
    turnToAngle(-5,400);
    driveAndTurn(1,0,100,100);
    turnToAngle(-30,100,800);
    intas.stop(brake);
    doIWantItToGoToArm = true;
    driveAndTurn(2.5,0,100,100);
    turnToAngle(-190);
    armbig.set(1);
    driveAndTurn(0.8725,-190,100,100);
    turnToAngle(-90);
    doIWantItToGoToArm = false;
    driveAndTurn(1,-90,100,100);
    armbig.set(0);
    wait(200,msec);
    driveAndTurn(-0.5,-90,100,100);
    turnToAngle(-180,100,800);
    suk(100);
    driveAndTurn(2.7,-180,80,100);
    turnToAngle(-45,70,800);
    driveAndTurn(0.8,-45,100,100);
    driveAndTurn(-0.7,45,50,100);
    clamp.set(0);
    driveAndTurn(0.5,25,100,100);
    marginOfErrorForTurning = 0.5;
    turnToAngle(-90);
    turnToAngle(-90);
    marginOfErrorForTurning = 3;
    driveAndTurn(-3.4,-90,100,100,3000);
    clamp.set(1);


    turnToAngle(5,400);
    driveAndTurn(1,-0,100,100);
    turnToAngle(30,100,800);
    intas.stop(brake);
    doIWantItToGoToArm = true;
    driveAndTurn(2.5,-0,100,100);
    turnToAngle(190);
    armbig.set(1);
    driveAndTurn(0.8,190,100,100);
    turnToAngle(90);
    doIWantItToGoToArm = false;
    driveAndTurn(1,90,100,100);
    armbig.set(0);
    wait(200,msec);
    driveAndTurn(-0.5,90,100,100);
    turnToAngle(180,100,800);
    suk(100);
    driveAndTurn(2.7,180,80,100);
    turnToAngle(45,75,800);
    // driveAndTurn(0.7,45,100,100);
    // turnToAngle(60);
    // driveAndTurn(-0.7,-45,50,100);
    // clamp.set(0);

}
void test(){
    vex::thread asdasdouuh(reves);
    doIWantItToGoToArm = true;
}