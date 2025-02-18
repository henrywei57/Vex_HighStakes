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


void Odometry::moveToPos() {
        
}

void Odometry::driveWithVoltage(double leftPct, double rightPct){
    double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
    leftPct *= scale;
    rightPct *= scale;
    leftmo.spin(fwd, leftPct, volt);
    rightmo.spin(fwd, rightPct, volt);
}



