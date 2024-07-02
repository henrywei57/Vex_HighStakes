#include "botcontrol.h"
#include "utility/buttons.h"
#include "main.h"
#include "robot-config.h"
#include "wing.h"
using namespace vex;

  // if (fabs(input)<width){
  //   return(0);
  // }
  // return(input);
int pxpos = 480/2;
int pypos = 240/2;
int turningCurve = 5;
bool turningRed = false;

int forwardCurve = 10;
bool forwardRed = false;

bool x;
bool y;

void driver(){
  //  resetPuncher();
   

  while(1){
   
    // double turnVal = curveJoystick(false, con.Axis1.position(percent), turningCurve); //Get curvature according to settings [-100,100]
    // double forwardVal = curveJoystick(false, con.Axis3.position(percent), forwardCurve); //Get curvature according to settings [-100,100]

    // double turnVolts = -turnVal * 0.12; //Converts to voltage
    // double forwardVolts = forwardVal * 0.12; //Converts to voltage

    // leftmo.spin(forward, forwardVolts + turnVolts, voltageUnits::volt); //Apply Via Voltage
    // rightmo.spin(forward, forwardVolts - turnVolts, voltageUnits::volt);

    // vex::task::sleep(20);
    if(con.ButtonR1.pressing()){
      inta.spin(reverse, 100, pct);
    } else if(con.ButtonR2.pressing()){
      inta.spin(fwd, 100, pct);
    } else{
      inta.stop(hold);
    }
    // if(con.ButtonRight.pressing()){
    //   smlboi.spin(reverse, 100, pct);
    //   ptoboi.spin(reverse, 100, pct);
    // } else if(con.ButtonLeft.pressing()){
    //   smlboi.spin(fwd, 100, pct);
    //   ptoboi.spin(fwd, 100, pct);
    // } else{
    //   smlboi.stop(hold);
    //   ptoboi.stop(hold);
    // }
/////////////////////////////////////////////////////////////////

    double axis3 = con.Axis3.position(pct);
    double axis1 = con.Axis1.position(pct);
    double leftVolt = axis3 - axis1;
    double rightVolt = axis3 + axis1;
    double scale = 12.0 / fmax(12.0, fmax(fabs(leftVolt), fabs(rightVolt)));
    leftVolt *= scale;
    rightVolt *= scale;
    if (fabs(leftVolt) < 0.1){
        leftmo.stop(brake);
    } 
    else{
        leftmo.spin(forward, leftVolt, volt);
    }
    if(fabs(rightVolt) < 0.1){
        rightmo.stop(brake);
    }
    else{
        rightmo.spin(forward, rightVolt, volt);
    }



//////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
    double xxxx = (leftmo.temperature(celsius)+rightmo.temperature(celsius))/2;
    Brain.Screen.print(xxxx);
    wait(10, msec);
    Brain.Screen.clearLine();
  }




}

