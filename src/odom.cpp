#include "odometry/odom.h"
#include "robot-config.h" // Assuming xEncoder, yEncoder, and bob are declared here
#include "vex.h"
#include "other_function.h"
#include "cmath"
#include <vex_task.h>

using namespace vex;
using namespace std;



// Constructor: Initialize the Odometry object
Odometry::Odometry(double diameter) 
    : wheelDiameter(diameter), globalX(0), globalY(0), prevXRotation(0), prevYRotation(0) {}

// Convert degrees of encoder rotation to inches
double Odometry::degToInch(double degrees) {
    double wheelCircumference = M_PI * wheelDiameter;
    double distancePerDegree = wheelCircumference / 360.0;
    return degrees * distancePerDegree;
}

// Reset sensors and position
void Odometry::resetSensors() {
    xEncoder.setRotation(0, deg);
    yEncoder.setRotation(0, deg);

    // Assuming calibob() resets the bot's rotation
    calibob();

    globalX = 0;
    globalY = 0;
    prevXRotation = 0;
    prevYRotation = 0;
}

// Update the robot's global position
void Odometry::updatePos() {
    // Get current encoder rotations
    double currentXRotation = xEncoder.rotation(deg);
    double currentYRotation = yEncoder.rotation(deg);

    // Calculate change in encoder rotations
    double deltaXRotation = std::fmod(currentXRotation - prevXRotation + 360.0, 360.0);
    if (deltaXRotation > 180.0) deltaXRotation -= 360.0;

    double deltaYRotation = std::fmod(currentYRotation - prevYRotation + 360.0, 360.0);
    if (deltaYRotation > 180.0) deltaYRotation -= 360.0;

    // Convert changes to local distances
    double localX = degToInch(deltaXRotation);
    double localY = degToInch(deltaYRotation);

    // Get the robot's current angle in radians
    double botAngle = bob.rotation(deg) * (M_PI / 180.0);

    // Calculate displacement in global coordinates
    double displacementMagnitude = std::sqrt(localX * localX + localY * localY);
    double displacementAngle = std::atan2(localY, localX) + botAngle;

    globalX += displacementMagnitude * cos(displacementAngle);
    globalY += displacementMagnitude * sin(displacementAngle);

    // Update previous encoder values
    prevXRotation = currentXRotation;
    prevYRotation = currentYRotation;

    // Small delay to allow sensors to update
    wait(5,msec);
}
