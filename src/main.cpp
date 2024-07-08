/*
Driver control: Joystick 3 controls the vertical acceleration of the chassis
                Joystick 1 controls the horizontal acceleration of the chassis
                Button R1 is to intake
                Button R2 is to outtake

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
using namespace vex;
using namespace auton;
competition Competition;




int originX = 0;
int width = 240;

bool intawing = 0;

// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

int autonoption = 0;
bool taboption = 1;
    float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void pre_auton(void) {
  vexcodeInit();
  // board();


  
calibob();


  // heading_convert(bob.heading());


}

void autonomous(void) {
  con.rumble("- .-. ..--...-. .");
// close_qua();
// far_qua();
// close_elim();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  test();
}

void usercontrol(void) {

    // hangg.set(1);
    con.ButtonL2.pressed(Front_wings);
    con.ButtonL1.pressed(Back_wings);
    con.ButtonDown.pressed(hang);


    // resetPuncher();
  driver();


}
int main() {
  // calibob();
  // graphic();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }

}