#include "odometry/odom.h"
#include "robot-config.h"
#include "vex.h"
#include "other_function.h"
#include "cmath"
#include <vex_task.h>
#include "utility/pid_control.h"

using namespace vex;
using namespace std;



Odometry::Odometry(double diameter) 
    : wheelDiameter(diameter), globalX(0), globalY(0), prevXRotation(0), prevYRotation(0) {}

double Odometry::degToInch(double degrees) {
    double wheelCircumference = M_PI * wheelDiameter;
    double distancePerDegree = wheelCircumference / 360.0;
    return degrees * distancePerDegree;
}

double Odometry::inchToTile(double inch){return inch/24.0;}

void Odometry::resetSensors() {
    xEncoder.setRotation(0, deg);
    yEncoder.setRotation(0, deg);

    calibob();

    globalX = 0;
    globalY = 0;
    prevXRotation = 0;
    prevYRotation = 0;
}

void Odometry::updatePos() {
    double currentXRotation = xEncoder.rotation(deg);
    double currentYRotation = yEncoder.rotation(deg);

    double deltaXRotation = currentXRotation - prevXRotation;
    if (deltaXRotation > 180.0) deltaXRotation -= 360.0;

    double deltaYRotation = currentYRotation - prevYRotation;
    if (deltaYRotation > 180.0) deltaYRotation -= 360.0;

    double localX = inchToTile(degToInch(deltaXRotation));
    double localY = inchToTile(degToInch(deltaYRotation));

    double botAngle = bob.rotation(deg) * (M_PI / 180.0);

    double displacementMagnitude = std::sqrt(localX * localX + localY * localY);
    double displacementAngle = std::atan2(localY, localX) + botAngle;

    globalX += displacementMagnitude * cos(displacementAngle);
    globalY += displacementMagnitude * sin(displacementAngle);

    prevXRotation = currentXRotation;
    prevYRotation = currentYRotation;

    wait(5,msec);
}


void Odometry::moveToPos(double X_position, double Y_position, double angle, 
                          double drive_min_voltage, double drive_max_voltage, double heading_max_voltage, 
                          double drive_settle_error, int drive_settle_time, double drive_timeout, 
                          double drive_kp, double drive_ki, double drive_kd, 
                          double heading_kp, double heading_ki, double heading_kd) {
    
    // Compute initial target distance
    double target_distance = hypot(X_position - globalX, Y_position - globalY);

    // Initialize PID Controllers with correct parameters
    PIDControl drivePID(drive_kp, drive_ki, drive_kd, drive_settle_error, drive_settle_time);  // Margin = drive_settle_error
    PIDControl headingPID(heading_kp, heading_ki, heading_kd, 5, 10);  // Margin = 5 degrees, MinReachedCall = 10

    while (!drivePID.reachedGoal()) {
        // Update odometry position
        updatePos();

        // Recalculate distance to target
        target_distance = hypot(X_position - globalX, Y_position - globalY);

        // Compute heading error based on odometry
        double heading_error = reduce_negative_180_to_180(to_deg(atan2(Y_position - globalY, 
                                                                       X_position - globalX)) 
                                                                       - (bob.rotation(deg)));

        // If close to the target, switch to final orientation correction
        if (target_distance < drive_settle_error) {
            heading_error = reduce_negative_180_to_180(angle - (bob.rotation(deg)));
        }

        // Update PID controllers with new errors
        drivePID.computeFromError(target_distance);
        headingPID.computeFromError(heading_error);

        // Get PID outputs
        double drive_output = drivePID.getValue();
        double heading_output = headingPID.getValue();

        // Clamp values to safe voltage ranges
        drive_output = Clamp(drive_output, -drive_max_voltage, drive_max_voltage);
        heading_output = Clamp(heading_output, -heading_max_voltage, heading_max_voltage);

        // Ensure minimum drive voltage for movement
        drive_output = clamp_min_voltage(drive_output, drive_min_voltage);

        // Compute motor voltages
        double left_voltage = left_voltage_scaling(drive_output, heading_output);
        double right_voltage = right_voltage_scaling(drive_output, heading_output);

        // Apply voltages to motors
        driveWithVoltage(left_voltage, right_voltage);

        // Wait before next loop
        task::sleep(10);
    }
}

void Odometry::driveWithVoltage(double leftPct, double rightPct){
    double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
    leftPct *= scale;
    rightPct *= scale;
    leftmo.spin(fwd, leftPct, volt);
    rightmo.spin(fwd, rightPct, volt);
}



