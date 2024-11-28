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
    mogoclp.set(1); 
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    driveAndTurn(0.76,-80,100,22);
    driveAndTurn(-0.1,-80,100,100);  
    mogoclp.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    wait(400,msec);
    turnToAngle(45);
    driveAndTurn(-1.8,-75,55,100);   
    intakee.set(1);  
    turnToAngle(-180);
    suk(100);
    driveAndTurn(1.4,-180,100,100);
    turnToAngle(-270);
    driveAndTurn(0.55,-290,100,100);
    turnToAngle(-360);
    driveAndTurn(1,-365,100,100);
}

void redr(){
    intakee.set(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    setHeading(0);
    sped = 0.047;
    driveAndTurn(-1.26,-32,100,100);  
    intakee.set(1); 
    // turnToAngle();        
    suk(100);
    turnToAngle(-90);
    driveAndTurn(1,-100,50,100); 
    inta2.stop();
    turnToAngle(70,100);
    intakee.set(0);  
    suk(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    driveAndTurn(2.3, 72.5, 100,100);
    turnToAngle(-0);
    // turnToAngle(0);
    mogoclp.set(1);
    wait(250,msec);
    driveAndTurn(0.845,2.45,30,100);
    mogoclp.set(0); 
    wait(400,msec);
    driveAndTurn(-1.5,-0,100,100);
}
void bluel(){
    suk(100); // Start the intake immediately
    doIWantItToGoToArm = true;
    vex::thread reves;
    // suk(100);
    // intakee.set(0);
    // setHeading(0);
    // driveAndTurn(1.9, -45, 100,100);
    // shgrjn.set(1);
    // driveAndTurn(-1.05, -100, 40,100,1000);
    // shgrjn.set(0);
    // intakee.set(1);
    // suk(100);
    // wait(450,msec);
    // intakee.set(0);
    // turnToAngle(90);
    // driveAndTurn(-1.2, 100, 100,100,1000);
    // intakee.set(1);
    // suk(100);
    // turnToAngle(-90);
    // driveAndTurn(0.5, -80, 100,100,1000);
    // turnToAngle(130);
    // doIWantItToGoToArm = true;
    // driveAndTurn(3.4, 90, 90,100);
    // driveAndTurn(-0.5, 180, 90,100);
}

void test(){
// Start the reves thread
doIWantItToGoToArm = true;   
vex::thread revesThread(reves);

// Wait for the reves task to complete based on your autonomous logic
wait(15000, msec);  // Allow time for the function to execute

// Reset the flag externally after a delay or condition
doIWantItToGoToArm = false; 
revesThread.join();  // Ensure the thread finishes cleanly
}