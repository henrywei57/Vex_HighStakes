#include "vex.h"
#include "odom.h"
#include "robot-config.h"
#include "cmath"
#include "other_function.h"

using namespace vex;

namespace odom{

  double xPos;
  double yPos;
  
  double angle = 0;

  double currHor = 0;
  double prevHor = 0;
  double deltaHor = 0;

  double DegToInch(double wheelDiameter, double deg){
    double wheelCir = M_PI * wheelDiameter;
    return wheelCir*(deg/360);
  }

  int configSensor(){
    hor.setRotation(0,degrees);
    ver.setRotation(0,degrees);
    calibob();
    angle = bob.rotation(deg);
    xPos = 0;
    yPos = 0;
    return 1;
  }


  void updatePos(){
    prevHor = hor.rotation(deg);

    while (1) {
        currHor = hor.rotation(deg);
        deltaHor = currHor - prevHor;
        prevHor = currHor;

        double lengthTraveled = DegToInch(3.25, deltaHor);
        double angleRad = angle * (M_PI / 180.0);

        xPos += lengthTraveled * cos(angleRad);
        yPos += lengthTraveled * sin(angleRad);

        angle = bob.rotation(deg);
        wait(10, msec);
    }

  }



}