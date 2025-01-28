#ifndef ODOMETRY_H // Include guard to prevent multiple inclusions
#define ODOMETRY_H

#include "vex.h" 
#include <cmath>
#include <iostream>

class Odometry {
private:
    double globalX;          // Global X position
    double globalY;          // Global Y position
    double prevXRotation;    // Previous X encoder rotation
    double prevYRotation;    // Previous Y encoder rotation
    double wheelDiameter;    // Diameter of the wheels
    const double PI = M_PI;  // Constant for PI
    const double FULL_CIRCLE_DEG = 360.0; // Constant for full circle in degrees

public:
    // Constructor
    Odometry(double diameter);

    // Convert encoder degrees to inches
    double degToInch(double degrees);

    // Reset sensors and odometry
    void resetSensors();

    // Handle encoder wrapping
    double handleEncoderWrapping(double currentRotation, double prevRotation);

    // Update robot position and orientation
    void updatePos();

    // Getter functions
    double getGlobalX();
    double getGlobalY();
};

#endif // ODOMETRY_H