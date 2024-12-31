#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "pneumatics.h"
#include "utility/buttons.h"
#include "other_function.h"
#include <vector>
#include <iostream>
#include "colorFilter.h"


using namespace vex;
using namespace auton;
competition Competition;

bool autonSelector = true;

void pre_auton(void) {
  board();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(100, msec);
  }
  vexcodeInit();
}

void autonomous(void) {
  switch(autonoption){
    case 1:
      redl();
      break;
    case 2:
      redr();
      break;
    case 3:
      bluel();
      break;
    case 4:
      bluer();
      break;
    default:
      skill();
  }
}

void usercontrol(void) {
  Brain.Screen.clearScreen();
  autonSelector = false;

  con.ButtonRight.pressed(asdr);
  con.ButtonL1.pressed(mogo_clamp);
  
  con.ButtonY.pressed(intake);

  driver(); 


}
int main() {
  autonSelectorImg();
    colorseancor.setLightPower(100,pct);
    
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
  


} 