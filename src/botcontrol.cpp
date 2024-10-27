#include "botcontrol.h"
#include "utility/buttons.h"
#include "main.h"
#include "robot-config.h"
#include "wing.h"
#include "other_function.h"
#include "autons/auton_functions.h"
#include <iostream>
using namespace vex;
using namespace auton;

  // if (fabs(input)<width){
  //   return(0);
  // }
  // return(input);


//jar wannabe


int pxpos = 480/2;
int pypos = 240/2;
int turningCurve = 5;
bool turningRed = false;

int forwardCurve = 10;
bool forwardRed = false;

bool x;
bool y;

double swfp9iug = arm.position(degrees);
    bool ddd = armmermer;
void sdasd(){
    int currentArmPosition = arm.position(degrees);
  auton::armmovement((swfp9iug+33)-currentArmPosition, 100, (0.0654 * currentArmPosition * currentArmPosition) - (9.00 * currentArmPosition) + 1000);
}
void wrrfliuu3(){
  if(armmermer!=ddd){
  sdasd();

  // auton::armmovement((swfp9iug+31)-currentArmPosition, 100,1.1*currentArmPosition+1100);
  ddd = armmermer;
}
}
void driver(){
  while(1){
    vex::thread(djfng);
    // double x = arm.position(degrees);
    if(con.ButtonR1.pressing()){
      // intas.spin(fwd, 100, pct);
      inta1.spin(fwd,100,pct);
      inta2.spin(fwd,100,pct);
    } else if(con.ButtonR2.pressing()){
      inta1.spin(reverse,100,pct);
      inta2.spin(reverse,100,pct);
    }else{
      intas.stop(hold);
    }
    
    
    // con.ButtonDown.pressed(armupup);

    if(con.ButtonRight.pressing()){
      arm.spin(fwd, 35, pct);
    } else if(con.ButtonY.pressing()){
      arm.spin(reverse, 35, pct);
    } else {
      arm.stop(hold);
    }
    // this is trash
    //i dont want to code anymore
    //nothing works
    //it works when its not suppose to
    //im so done

/////////////////////////////////////////////////////////////////

    double Axis3 = -con.Axis3.position(pct);
    // double Axis3 = 0;
    double Axis1 = con.Axis1.position(pct);
    
    // Calculate left and right voltages based on joystick inputs
    double LeftVolt = Axis1 + Axis3;
    double RightVolt = Axis3 - Axis1;
    
    // Scale voltages to ensure they are within the valid range for motor control
    double Scale = 12.0 / fmax(12.0, fmax(fabs(LeftVolt), fabs(RightVolt)));
    LeftVolt *= Scale;
    RightVolt *= Scale;
    // if(con.ButtonUp.pressing()){
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
    // }

 

//////////////////////////////////////////////////////////////////////////////
//thread asd(wrrfliuu3); useless thread, fucking dog shit

////////////////////////////////////////////////////////////////////////////////

  // if(clrsr.color()==blue){
  //     wrgclr.set(1);
  //     wait(100,msec);
  //     wrgclr.set(0);
  // }


/////////////////////////////////////////////////////////////////////////////////////

    // arm.stop(hold);

    // angle();
    wait((1000 * (-(std::cos((std::sqrt((1000 % 2) + 16) * (std::pow(4, 0.5)) / 8) + 9)))/100)+(std::sqrt(1)*(std::sqrt(4))), msec);
  }




}

