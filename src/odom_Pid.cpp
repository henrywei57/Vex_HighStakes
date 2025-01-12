#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
#include "botcontrol.h"

double currentX = 0, currentY = 0, currentTheta = 0; 

void updatePosition(double hor, double ver, double thetaInDegrees) {
    currentX += hor * cos(currentTheta * M_PI / 180);
    currentY += ver * sin(currentTheta * M_PI / 180);
    currentTheta = thetaInDegrees;
}

void driveVelocity(double leftPct, double rightPct){
    double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
    leftPct *= scale;
    rightPct *= scale;
    leftmo.spin(fwd, to_volt(leftPct), volt);
    rightmo.spin(fwd, to_volt(rightPct), volt);
}

double computeDistance(double targetX, double targetY) {
    return sqrt(pow(targetX - currentX, 2) + pow(targetY - currentY, 2));
}

double computeTargetHeading(double targetX, double targetY) {
    return atan2(targetY - currentY, targetX - currentX) * 180 / M_PI;
}

double normalizeHeadingError(double headingError) {
    if (headingError > 180) headingError -= 360;
    if (headingError < -180) headingError += 360;
    return headingError;
}

void moveToPosition(double targetX, double targetY, double targetTheta, double linearMaxVelocity, double turnMaxVelocity) {
    PIDControl drivePID, rotateToPID;

    while (true) {

        double horPos = hor.position(degrees);
        double verPos = ver.position(degrees);
        double theta = bob.rotation(degrees);
        updatePosition(hor, ver, theta);


        double distance = computeDistance(targetX, targetY);
        double targetHeading = computeTargetHeading(targetX, targetY);
        double headingError = normalizeHeadingError(targetHeading - currentTheta);
        double thetaError = normalizeHeadingError(targetTheta - currentTheta);

        if (distance < 0.1 && fabs(thetaError) < 2) break;

        drivePID.computeFromError(distance);
        double newLinearVelocity = drivePID.getValue();
        newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));

        rotateToPID.computeFromError(headingError);
        double newTurnVelocity = rotateToPID.getValue();
        newTurnVelocity = fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity));

        double finalLeftVelocity = newLinearVelocity + newTurnVelocity;
        double finalRightVelocity = newLinearVelocity - newTurnVelocity;

        driveVelocity(finalLeftVelocity, finalRightVelocity);

        con.Screen.print("Dist: %.2f, HeadErr: %.2f", distance, headingError);
        task::sleep(20);
        con.Screen.clearScreen();
    }

    // Stop motors
    leftmo.stop();
    rightmo.stop();
}

