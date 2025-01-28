#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "vex.h"
#include <cmath>

class Odometry {
private:
    double globalX, globalY;
    double prevXRotation, prevYRotation;
    double wheelDiameter;

    // Helper function to convert degrees to inches based on wheel diameter
    double degToInch(double degrees);

public:
    // Constructor to initialize the odometry system with the wheel diameter
    Odometry(double diameter);

    // Function to reset sensors and global position
    void resetSensors();

    // Function to update the robot's global position
    void updatePos();

    // Getter functions for global position
    double getGlobalX() const { return globalX; }
    double getGlobalY() const { return globalY; }
};

#endif // ODOMETRY_H
