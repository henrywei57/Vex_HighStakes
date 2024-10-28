#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>  // Include for sprintf
#include "botcontrol.h"
#include "autons/auton.h"
#include <math.h>
#include <cmath>


double gearRatio = (double)(60)/48;
double wheelRadius = 3.25;
double wheelCircumference = 2 * M_PI * wheelRadius;

double startHeading = 90;

double x = 0;
double y = 0;

void odom(){
    leftmo.resetPosition();
    rightmo.resetPosition();

    double previousDisTraveled = 0;

    while(1){
        double heading = fmod((360 - bob.heading(degrees)) + startHeading, 360);

        double avgPos = (leftmo.position(degrees) + rightmo.position(degrees)) / 2;
        double traveledDis = (avgPos/360) * wheelCircumference * gearRatio;

        double changeInDis = traveledDis - previousDisTraveled;

        x += changeInDis * std::cos(heading * (M_PI / 180));
        y += changeInDis * std::sin(heading * (M_PI / 180));

        previousDisTraveled = traveledDis;

        vex::this_thread::sleep_for(10);
    }
}