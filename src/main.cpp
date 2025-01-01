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
#include "v5lvgl.h"


using namespace vex;
using namespace auton;
competition Competition;

bool autonSelector = true;

lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style

static void btn_click_action(lv_obj_t * btn, lv_event_t event)
{
    uint8_t id = (int)lv_obj_get_user_data(btn); //id usefull when there are multiple buttons

//      char buffer[100];
//      sprintf(buffer,"event %3d", event);
//      printf("%s\n", buffer);

    if(id == 0 && event == LV_EVENT_CLICKED)
    {
  		lv_label_set_text(myLabel, "clicked");
    }

    return ;
}



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





int demo() {
    lv_style_copy(&myButtonStyleREL, &lv_style_plain);
    myButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0, 0);
    myButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0, 150);
    myButtonStyleREL.body.radius = 0;
    myButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&myButtonStylePR, &lv_style_plain);
    myButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
    myButtonStylePR.body.radius = 0;
    myButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

   myButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
   lv_obj_set_user_data(myButton, (lv_font_user_data_t)0); //set button is to 0
   lv_obj_set_event_cb(myButton, btn_click_action); //set function to be called on button click
   lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
   lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
   lv_obj_set_size(myButton, 200, 50); //set the button size
   lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

    myButtonLabel = lv_label_create(myButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(myButtonLabel, "Click the Button"); //sets label text

    myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
    lv_label_set_text(myLabel, "Button has not been clicked yet"); //sets label text
    lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0); //set the position to center

    return(0);
}





int main() {
  // autonSelectorImg();
  //   colorseancor.setLightPower(100,pct);
    
  // Competition.autonomous(autonomous);
  // Competition.drivercontrol(usercontrol);
  // pre_auton();
  // while (true) {
  //   wait(100, msec);
  // }
  
    v5_lv_init();
    demo();

    while(1) {
        //Brain.Screen.printAt( 10, 50, "Hello V5 %d", count++ );
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }

} 
