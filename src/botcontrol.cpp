#include "botcontrol.h"
#include "utility/buttons.h"
#include "main.h"
#include "robot-config.h"
#include "wing.h"
#include "other_function.h"
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
  while(1){
    if(con.ButtonR1.pressing()){
      intas.spin(reverse, 100, pct);
    } else if(con.ButtonR2.pressing()){
      intas.spin(fwd, 100, pct);
    } else{
      intas.stop(hold);
    }

/////////////////////////////////////////////////////////////////

    double axis1 = -con.Axis3.position(pct);
    double axis3 = -con.Axis1.position(pct);    
    double leftVolt = axis1 - axis3;
    double rightVolt = axis1 + axis3;
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

  // if(clrsr.color()==blue){
  //     wrgclr.set(1);
  //     wait(100,msec);
  //     wrgclr.set(0);
  // }


/////////////////////////////////////////////////////////////////////////////////////

    angle();
    wait(10, msec);
    // Brain.Screen.clearLine();
  }




}

