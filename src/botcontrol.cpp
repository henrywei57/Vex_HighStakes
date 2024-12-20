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
bool isThreadRunning1 = false;

// Macro to check if both R1 and R2 buttons are pressed
#define BOTH_BUTTONS_PRESSED (con.ButtonDown.pressing())

// Macro to set the `isThreadRunning` flag
#define SET_THREAD_RUNNING(state) isThreadRunning = state
#define SET_THREAD_RUNNING1(state) isThreadRunning1 = state

// Function for `reve` behavior
void reve() {
    SET_THREAD_RUNNING(true);  // Set flag to indicate the thread is active
    intas.spin(fwd, 30, pct);
    // wait(35,msec);
    intas.spin(reverse, 100, pct);
    wait(750, msec);
    intas.stop(brake);  // Stop with brake after the reverse motion
    SET_THREAD_RUNNING(false);  // Reset flag after completion
}



void colorFilterDriverControl() {
    SET_THREAD_RUNNING1(true); // Indicate the thread is active

    while (isThreadRunning1) {
        // Check if the object is within the specified distance
        if (aaasssddd.objectDistance(inches) < 1.3) {
            wait(150, msec); // Wait for 100 milliseconds after detecting the object
            intas.stop(brake); // Stop the motor with braking
        } else {
            // Allow the intake motor to run if no object is detected
            intas.spin(fwd, 100, pct); // Adjust speed as needed
        }

        wait(50, msec); // Add a short delay to prevent excessive CPU usage
    }

    SET_THREAD_RUNNING1(false); // Reset the flag when exiting the thread
}

bool hehe = true;
bool xxxx = true;
void blueffffilter() {
    while (xxxx) {
        int hue = colorseancor.hue();  // Get current hue value
        if (hue > 80 && hue<300&&colorseancor.isNearObject()) {  // Check hue and object detection
            wait(200, msec);  // Debounce delay
            hehe = false;
            intas.stop(hold);  // Stop intake motor
            con.rumble("-");
            wait(100, msec);  // Hold for 1 second
            hehe = true;
        }
        wait(10, msec);  // Reduce CPU usage
    }
}

void redffffilter() {
    while (xxxx) {
        int hue = colorseancor.hue();  // Get current hue value
        if (hue < 30 && hue>0&&colorseancor.isNearObject()) {  // Check hue and object detection
            wait(200, msec);  // Debounce delay
            hehe = false;
            intas.stop(hold);  // Stop intake motor
            con.rumble("-");
            wait(100, msec);  // Hold for 1 second
            hehe = true;
        }
        wait(10, msec);  // Reduce CPU usage
    }
}



void driver() {
    int county = 0;
    // vex::thread asdddasdefeww(blueffffilter);  // Create the thread object for dddaaa
    vex::thread asdsdasdas(redffffilter);  // Create the thread object for dddaaa

    while (1) { 
        int detectedColor = colorseancor.hue();

        // Check if the reve thread is not already running and ensure dddaaa runs on L2
        if (!isThreadRunning && hehe) {
            if (BOTH_BUTTONS_PRESSED && aaasssddd.objectDistance(inches) < 1.3) {
                vex::thread reveThread(reve);  // Start the reve function in a new thread
            } else if (BOTH_BUTTONS_PRESSED) {
                intas.spin(fwd, 100, pct);
            } else if (con.ButtonR1.pressing() && !isThreadRunning) {
                intas.spin(fwd, 100, pct);
            } else if (con.ButtonR2.pressing() && !isThreadRunning) {
                intas.spin(reverse, 100, pct);
            } else if (!isThreadRunning) {
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

