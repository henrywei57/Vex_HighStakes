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
      intas.spin(fwd, 100, pct);
    } else if(con.ButtonR2.pressing()){
      intas.spin(reverse, 100, pct);
    } else{
      intas.stop(hold);
    }

/////////////////////////////////////////////////////////////////

    double Axis3 = con.Axis3.position(pct);
    double Axis1 = con.Axis1.position(pct);
    
    // Calculate left and right voltages based on joystick inputs
    double LeftVolt = Axis1 + Axis3;
    double RightVolt = Axis3 - Axis1;
    
    // Scale voltages to ensure they are within the valid range for motor control
    double Scale = 12.0 / fmax(12.0, fmax(fabs(LeftVolt), fabs(RightVolt)));
    LeftVolt *= Scale;
    RightVolt *= Scale;
    
    // Stop left motor if voltage is below a threshold, otherwise spin it forward
    if (fabs(LeftVolt) < 0.1) {
        leftmo.stop(brake);
    } else {
        leftmo.spin(forward, LeftVolt, volt);
    }
    
    // Stop right motor if voltage is below a threshold, otherwise spin it forward
    if (fabs(RightVolt) < 0.1) {
        rightmo.stop(brake);
    } else {
        rightmo.spin(forward, RightVolt, volt);
    }



//////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////

  // if(clrsr.color()==blue){
  //     wrgclr.set(1);
  //     wait(100,msec);
  //     wrgclr.set(0);
  // }


/////////////////////////////////////////////////////////////////////////////////////

    // angle();
    wait(10, msec);
    // Brain.Screen.clearLine();
  }




}

