#include "botcontrol.h"
#include "utility/buttons.h"
#include "main.h"
#include "robot-config.h"
#include "pneumatics.h"
#include "other_function.h"
#include "autons/auton_functions.h"
#include <iostream>
#include "vex.h"  
#include "utility/pid_control.h"

using namespace vex;
using namespace auton;


bool isThreadRunning = false;
bool isThreadRunning1 = false;


// #define BOTH_BUTTONS_PRESSED (con.ButtonDown.pressing())


#define SET_THREAD_RUNNING(state) isThreadRunning = state
#define SET_THREAD_RUNNING1(state) isThreadRunning1 = state


// void reve() {
//     SET_THREAD_RUNNING(true);  
//     intas.spin(fwd, 30, pct);
    
//     inta2.spin(fwd, 100, pct);
//     inta1.spin(reverse, 100, pct);
//     wait(750, msec);
//     intas.stop(brake);  
//     SET_THREAD_RUNNING(false);  
// }



// void colorFilterDriverControl() {
//     SET_THREAD_RUNNING1(true); 

//     while (isThreadRunning1) {
        
//         if (aaasssddd.objectDistance(inches) < 1.3) {
//             wait(150, msec); 
//             intas.stop(brake); 
//         } else {
            
//             intas.spin(fwd, 100, pct); 
//         }

//         wait(50, msec); 
//     }

//     SET_THREAD_RUNNING1(false); 
// }

// bool hehe = true;
// bool xxxx = true;
// void blueffffilter() {
//     while (xxxx) {
//         int hue = colorseancor.hue();  
//         if (hue > 80 && hue<300&&colorseancor.isNearObject()) {  
//             wait(170, msec);  
//             hehe = false;
//             intas.stop(hold);  
//             con.rumble("-");
//             wait(100, msec);  
//             hehe = true;
//         }
//         wait(10, msec);  
//     }
// }

// void redffffilter() {
//     while (xxxx) {
//         int hue = colorseancor.hue();  
//         if (hue < 30 && hue>0&&colorseancor.isNearObject()) {  
//             wait(200, msec);  
//             hehe = false;
//             intas.stop(hold);  
//             con.rumble("-");
//             wait(100, msec);  
//             hehe = true;
//         }
//         wait(10, msec);  
//     }
// }

float deadband(float input, float width){
  if (std::fabs(input)<width){
    return(0);
  }
  return(input);
}

float to_volt(float percent){
  return(percent*12.0/100.0);
}

void arcadeDrive(){
  float throttle = deadband(con.Axis3.value(), 5);
  float turn = deadband(con.Axis1.value(), 5);
  leftmo.spin(fwd, throttle-turn, pct);
  rightmo.spin(fwd, throttle+turn, pct);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////Scoring Arm//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int currState = 0;
int states[4] = {20, -25, -160};  // Removed unnecessary '-0'
int target = states[currState];

double error;
bool manualControl = false;

void spinToPlace() {
    double kp = 0.8;
    error = target - lb.position(deg);

    if (abs(error) < 10) {
        if(!con.ButtonY.pressing()){
            arm.stop(hold);
        }
        return;
    }

    double velo = kp * error;
    arm.spin(fwd, -velo, pct);
}


void nextState(){
    currState += 1;
    if(currState == 3){
        currState = 1;
    }
    target = states[currState];
}

void nextRing(){
    target = -60;
}


void boom(){
    arm.spin(fwd,100,pct);
    wait(400,msec);
    arm.stop();
}



void idlePos(){
    currState = 0;
    target = states[currState];
}


void initializeArm(){
    vex::thread armMoveThread([]{
        while(true){
            spinToPlace();
            wait(20, msec);  // Slightly increased wait time for stability
        }
    });
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////MAIN FUNCTION///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



void driver() {
    lb.resetPosition();
    int county = 0;
    // if(autonoption == 3||autonoption == 4){
    //     vex::thread asdddasdefeww(redffffilter);  
    // }else{
    //     vex::thread asdsdasdas(blueffffilter);  
    // }
    
    rightmo.setStopping(brake);
    leftmo.setStopping(brake);
    while (1) { 




        int detectedColor = colorseancor.hue();

        
        // if (!isThreadRunning && hehe) {
        //     if (BOTH_BUTTONS_PRESSED && aaasssddd.objectDistance(inches) < 1.3) {
        //         vex::thread reveThread(reve);  
        //     } else if (BOTH_BUTTONS_PRESSED) {
        //         intas.spin(fwd, 100, pct);
        //     } else if (con.ButtonR1.pressing() && !isThreadRunning) {
        //         intas.spin(fwd, 100, pct);
        //     } else if (con.ButtonR2.pressing() && !isThreadRunning) {
        //         intas.spin(reverse, 100, pct);
        //     } else if (!isThreadRunning) {
        //         intas.stop(coast);
        //     }
        // }
            if (con.ButtonR1.pressing() && !isThreadRunning) {
                intas.spin(fwd, -100, pct);
            } else if (con.ButtonR2.pressing() && !isThreadRunning) {
                intas.spin(reverse, -100, pct);
            } else if (!isThreadRunning) {
                intas.stop(coast);
            }

            


        
        // if (con.ButtonUp.pressing()) {
        //     arm.spin(fwd, 75, pct);
        // } else if (con.ButtonDown.pressing()) {
        //     arm.spin(reverse, 75, pct);
        // } else {
        //     arm.stop(hold);
        // }

        
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.printAt(10,10,"Arm: %.2f temp", inta2.temperature(celsius));

        Brain.Screen.printAt(100,20,"%.2f l1", l1.temperature(celsius));
        Brain.Screen.printAt(100,40,"%.2f l2", l2.temperature(celsius));
        Brain.Screen.printAt(100,60,"%.2f l3", l3.temperature(celsius));
        
        Brain.Screen.printAt(300,20,"%.2f r1", r1.temperature(celsius));
        Brain.Screen.printAt(300,40,"%.2f r2", r2.temperature(celsius));
        Brain.Screen.printAt(300,60,"%.2f r3", r3.temperature(celsius));



        arcadeDrive();

        wait(10, msec);
    }
}

