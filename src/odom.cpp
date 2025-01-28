#include "vex.h"
#include "odometry\odom.h"
#include "robot-config.h"
#include "cmath"
#include "other_function.h"
#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
#include  "botcontrol.h"

using namespace vex;

class Odometry{

private:
    double globalX, globalY;
    double prevXRotation, prevYRotation;
    double wheelDiameter;

public:

    Odometry(double diameter) : wheelDiameter(diameter), globalX(0), globalY(0), prevXRotation(0), prevYRotation(0) {}

    double degToInch(double degrees){

        double wheelCircumference = M_PI * wheelDiameter;
        double distancePerDegree = wheelCircumference / 360.0;

        return  degrees * distancePerDegree;

    }

    void resetSensors(){

        xEncoder.setRotation(0,deg);
        yEncoder.setRotation(0,deg);

        calibob();

        globalX = 0;
        globalY = 0;
        prevXRotation = 0;
        prevYRotation = 0;

    }

    void updatePos() {
        double currentXRotation = xEncoder.rotation(deg);
        double currentYRotation = yEncoder.rotation(deg);

        double deltaXRotation = fmod(currentXRotation - prevXRotation + 360.0, 360.0);
        if (deltaXRotation > 180.0) deltaXRotation -= 360.0;

        double deltaYRotation = fmod(currentYRotation - prevYRotation + 360.0, 360.0);
        if (deltaYRotation > 180.0) deltaYRotation -= 360.0;

        double localX = degToInch(deltaXRotation);
        double localY = degToInch(deltaYRotation);

        double botAngle = bob.rotation(deg) * (M_PI / 180.0);

        double displacementMagnitude = std::sqrt(localX * localX + localY * localY);
        double displacementAngle = std::atan2(localY, localX) + botAngle;

        globalX += displacementMagnitude * std::cos(displacementAngle);
        globalY += displacementMagnitude * std::sin(displacementAngle);

        prevXRotation = currentXRotation;
        prevYRotation = currentYRotation;

        wait(5, msec);
    }

};