#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "wing.h"
#include "utility/buttons.h"
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
  board();


  
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }


  // heading_convert(bob.heading());
  while(1){
  if (Brain.Screen.pressing()){
    int X = Brain.Screen.xPosition();
    int Y = Brain.Screen.yPosition();
    if ((Y <= 120) && (X >= 240)){
    Brain.Screen.drawRectangle(240, 30, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(315, 95, "Close Elim");
      autonoption = 1;

    } else if((Y <= 120) && (X <= 240)){
    Brain.Screen.drawRectangle(0, 30, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(85, 95, "Far Elim");  
      autonoption = 2;

    } else if((Y >= 120) && (X <= 240)){
    Brain.Screen.drawRectangle(0, 135, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(80, 195, "Far Qua");  
      autonoption = 3;

    } else if((Y >= 120) && (X >= 240)){
    Brain.Screen.drawRectangle(240, 135, 240, 105);
        Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(310, 195, "Close Qua");  
      autonoption = 4;

    } else if(Y <= 30){
      Brain.Screen.clearScreen();

    

    }
  }
  wait(20, msec);
}


}

void autonomous(void) {
  con.rumble("- .-. ..--...-. .");
// close_qua();
// far_qua();
// close_elim();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  if(autonoption == 1){
    close_elim();
  } else if(autonoption == 2){
    far_elim();
  } else if(autonoption == 3){
    far_qua();
  } else if(autonoption == 4){
    close_qua();
  }
    close_elim();

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
 
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}