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
#include "odometry/odom.h"
#include "botcontrol.h"


using namespace vex;
using namespace auton;
competition Competition;

bool autonSelector = true;


Odometry odom(4.0);

void runUpdatePos(){
  while(true){  odom.updatePos();}
}

void updateButtonPos() {

}

void pre_auton(void) {

  vexcodeInit();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(100, msec);
  }
  // odom.resetSensors();
  // vex::thread updatePosForOdom(runUpdatePos);

  // Brain.Screen.clearScreen();



  // vex::thread updatePosForButton(updateButtonPos);



}

void autonomous(void) {
  // switch(1){
  //   case 1:
  //     redl();
  //     break;
  //   case 2:
  //     redr();
  //     break;
  //   case 3:
  //     bluel();
  //     break;
  //   case 4:
  //     bluer();
  //     break;
  //   default:
      // test();
    // initializeArmAuto();
    // nextState();
    // nextState();
    // wait(1,sec);

    test();
  // driverSkillStart();

      // skill();.


      // bluel();


      // test();
      // auton::turnToAngle(90);
    
  // }
}

void usercontrol(void) {
  driverSkillStart();
  initializeArm();
  Brain.Screen.clearScreen();
  autonSelector = false;

  con.ButtonRight.pressed(asdr);
  con.ButtonL1.pressed(mogo_clamp);
  con.ButtonDown.pressed(nextState);
  con.ButtonRight.pressed(intake);
  con.ButtonL2.pressed(idlePos);
  con.ButtonY.pressed(nextRing);

  driver(); 


}




int main() {
  clamp.set(1);
    colorseancor.setLightPower(100,pct);
    
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }

} 
