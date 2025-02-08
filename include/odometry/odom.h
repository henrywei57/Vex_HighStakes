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

    double inchToTile(double inch);

    void driveWithVoltage(double leftPct, double rightPct);

public:
    // Constructor to initialize the odometry system with the wheel diameter
    Odometry(double diameter);

    // Function to reset sensors and global position
    void resetSensors();

    // Function to update the robot's global position
    void updatePos();

    void moveToPos(double X_position, double Y_position, double angle, 
                          double drive_min_voltage, double drive_max_voltage, double heading_max_voltage, 
                          double drive_settle_error, int drive_settle_time, double drive_timeout, 
                          double drive_kp, double drive_ki, double drive_kd, 
                          double heading_kp, double heading_ki, double heading_kd);

    // Getter functions for global position
    double getGlobalX() const { return globalX; }
    double getGlobalY() const { return globalY; }
};

#endif // ODOMETRY_H
