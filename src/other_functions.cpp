#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>  
#include "botcontrol.h"
#include "autons/auton.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace vex;

void calibob(){
    bob.startCalibration();
    while(bob.isCalibrating()){
    wait(100, msec);
    printf("calibrating"); 
  }
}

// Convert radians to degrees
double to_deg(double radians) {
    return radians * (180.0 / M_PI);
}

// Keep angle within [-180, 180] degrees
double reduce_negative_180_to_180(double angle) {
    while (angle > 180.0) angle -= 360.0;
    while (angle < -180.0) angle += 360.0;
    return angle;
}

// Clamp value between min and max limits
double Clamp(double value, double min_value, double max_value) {
    return fmax(min_value, fmin(max_value, value));
}

// Ensure a minimum voltage for movement
double clamp_min_voltage(double value, double min_voltage) {
    if (fabs(value) < min_voltage && value != 0) {
        return (value > 0) ? min_voltage : -min_voltage;
    }
    return value;
}

// Scale voltage for left motor considering heading correction
double left_voltage_scaling(double drive_voltage, double heading_voltage) {
    return drive_voltage + heading_voltage;
}

// Scale voltage for right motor considering heading correction
double right_voltage_scaling(double drive_voltage, double heading_voltage) {
    return drive_voltage - heading_voltage;
}
