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
#include "odometry/odom.h"


using namespace vex;
using namespace auton;
competition Competition;

bool autonSelector = true;

const int screenWidth = 480;
const int screenHeight = 272;

const int buttonWidth = 100;
const int buttonHeight = 60;

const int horizontalSpacing = (screenWidth - 4 * buttonWidth) / 5; //4 buttons, 5 gaps
const int verticalSpacing = (screenHeight - buttonHeight) / 2;

TouchButton button1(horizontalSpacing, verticalSpacing, buttonWidth, buttonHeight, "Button 1");
TouchButton button2(horizontalSpacing * 2 + buttonWidth, verticalSpacing, buttonWidth, buttonHeight, "Button 2");
TouchButton button3(horizontalSpacing * 3 + buttonWidth * 2, verticalSpacing, buttonWidth, buttonHeight, "Button 3");
TouchButton button4(horizontalSpacing * 4 + buttonWidth * 3, verticalSpacing, buttonWidth, buttonHeight, "Button 4");


Odometry odom(4.0);

void runUpdatePos(){
  while(true){  odom.updatePos();}
}

void updateButtonPos() {
  while(true){
    button1.updateTouchingPos();
    button2.updateTouchingPos();
    button3.updateTouchingPos();
    button4.updateTouchingPos();
    wait(10,msec);
  }
}

void pre_auton(void) {
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(100, msec);
  }
  vexcodeInit();

  odom.resetSensors();
  vex::thread updatePosForOdom(runUpdatePos);

  Brain.Screen.clearScreen();

  button1.draw();
  button2.draw();
  button3.draw();
  button4.draw();

  vex::thread updatePosForButton(updateButtonPos);

  while(true){
    if(button1.isPressed()){
      autonoption = 1;
    }else if(button2.isPressed()){
      autonoption = 2;
    }else if(button3.isPressed()){
      autonoption = 3;
    }else if(button4.isPressed()){
      autonoption = 4;
    }
    wait(10,msec);
  }

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
      test();
    
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
    colorseancor.setLightPower(100,pct);
    
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }

} 
