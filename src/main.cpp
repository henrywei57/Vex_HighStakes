/*
Driver control: Joystick 3 controls the vertical acceleration of the chassis
                Joystick 1 controls the horizontal acceleration of the chassis
                Button R1 is to intake
                Button R2 is to outtake
                Button L1 is for the drop down arm
                Button L2 is for the mobile goal clamp

*/


#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "wing.h"
#include "utility/buttons.h"
#include "other_function.h"
#include "odom_stuff_idk_still_trying.h"

using namespace vex;
using namespace auton;
competition Competition;




int originX = 0;
int width = 240;

bool intawing = 0;

// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

bool taboption = 1;
    float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}
void pre_auton(void) {
  vexcodeInit();
  board();


  
calibob();



}

void autonomous(void) {
  vex::thread odom_thread(odom);

  con.rumble("- .-. ..--...-. .");
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
  }
  // bluer();
      // bluel();
  printf("(%f, %f)", x, y);
}

void usercontrol(void) {
  // auton::armmovement(180);
    con.ButtonL1.pressed(mogo_clamp);
    
    con.ButtonRight.pressed(intake);
    // con.ButtonUp.pressed();
    // vex::thread buttonThread(handleButtonPresses);
    // con.ButtonDown.pressed(armupup);
    driver(); 


}
int main() {
  mogoclp.set(0);
  intakee.set(1);

    // auton::armmovement(-35,100);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
  


} 