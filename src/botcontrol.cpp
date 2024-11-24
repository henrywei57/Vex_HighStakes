#include "botcontrol.h"
#include "utility/buttons.h"
#include "main.h"
#include "robot-config.h"
#include "wing.h"
#include "other_function.h"
#include "autons/auton_functions.h"
#include <iostream>
#include "vex.h"  // Include the vex.h file

using namespace vex;
using namespace auton;

// Define a flag to indicate if the `reve` thread is running
bool isThreadRunning = false;

// Macro to check if both R1 and R2 buttons are pressed
#define BOTH_BUTTONS_PRESSED (con.ButtonDown.pressing())

// Macro to set the `isThreadRunning` flag
#define SET_THREAD_RUNNING(state) isThreadRunning = state

// Function for `reve` behavior
void reve() {
    SET_THREAD_RUNNING(true);  // Set flag to indicate the thread is active
    intas.spin(fwd, 30, pct);
    wait(35,msec);
    intas.spin(reverse, 100, pct);
    wait(750, msec);
    intas.stop(brake);  // Stop with brake after the reverse motion
    SET_THREAD_RUNNING(false);  // Reset flag after completion
}

void driver() {
    int county = 0;
    while (1) {
        // Check if the reve thread is not already running
if (!isThreadRunning) {
    if (BOTH_BUTTONS_PRESSED && aaasssddd.objectDistance(inches) < 1.3) {
        vex::thread reveThread(reve);    // Start the reve function in a new thread
    } else if (BOTH_BUTTONS_PRESSED && !isThreadRunning) {
        intas.spin(fwd, 100, pct);
    }
    else if (con.ButtonR1.pressing() && !isThreadRunning) {
        intas.spin(fwd, 100, pct);
    } 
    else if (con.ButtonR2.pressing() && !isThreadRunning) {
        intas.spin(reverse, 100, pct);
    } 
    else if (!isThreadRunning) {
        intas.stop(coast);
    }
}


        // Arm movement control
        if (con.ButtonRight.pressing()) {
            arm.spin(fwd, 35, pct);
        } else if (con.ButtonY.pressing()) {
            arm.spin(reverse, 35, pct);
        } else {
            arm.stop(hold);
        }

        // Driving control based on joystick positions
        double Axis3 = -con.Axis3.position(pct);
        double Axis1 = con.Axis1.position(pct);

        double LeftVolt = Axis1 + Axis3;
        double RightVolt = Axis3 - Axis1;

        double Scale = 12.0 / fmax(12.0, fmax(fabs(LeftVolt), fabs(RightVolt)));
        LeftVolt *= Scale;
        RightVolt *= Scale;

        if (fabs(LeftVolt) < 0.1) {
            leftmo.stop(brake);
        } else {
            leftmo.spin(forward, LeftVolt, volt);
        }

        if (fabs(RightVolt) < 0.1) {
            rightmo.stop(brake);
        } else {
            rightmo.spin(forward, RightVolt, volt);
        }

        wait(10, msec);
    }
}
