#include "vex.h"
#include "odom.h"
#include "robot-config.h"
#include "cmath"
#include "other_function.h"

using namespace vex;

double localX = 0;
double localY = 0;

double botAngle = 0;

double globalX = 0;
double globalY = 0;

double wheelDiameter = 4.0; //inch

double prevXEncoderPos = degToInch(xEncoder.rotation(deg));//now it caculates the degree of the motor to the distance traveled fix it i need it to get the different in angle 
double prevYEncoderPos = degToInch(yEncoder.rotation(deg) );

double currentXEncoderPos = 0;
double currentYEncoderPos = 0;

double r = 0;
double theta = 0;

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
    prevXEncoderPos = 0;
    prevYEncoderPos = 0;

}

void updatePos(){

    currentXEncoderPos = degToInch(xEncoder.rotation(deg));
    currentYEncoderPos = degToInch(yEncoder.rotation(deg));

    localX = prevXEncoderPos - currentXEncoderPos;
    localY = prevYEncoderPos - currentYEncoderPos;

    r = std::sqrt(localX * localX + localY * localY);
    theta = std::atan2(localX, localY);

    theta += bob.rotation(deg) * (M_PI / 180.0);

    globalX = r * std::cos(theta);
    globalY = r * std::sin(theta);

    prevXEncoderPos = currentXEncoderPos;
    prevYEncoderPos = currentYEncoderPos;

    wait(5,msec);
}