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
    // vex::thread t([] { loading(15, vex::color::green); });
  // t.detach();
  redr();
  // test1();
}

void usercontrol(void) {
  // draw();
    // loading(65,green);
    // loading(30,red);
    // hangg.set(1);
    con.ButtonL2.pressed(mogo_clamp);
    con.ButtonL1.pressed(intake);
    // con.ButtonUp.pressed(hangg);

  // Brain.Screen.setCursor(1,0);
  // Brain.Screen.print("                          _ooOoo");
  // Brain.Screen.setCursor(2,0);
  // Brain.Screen.print("                         o8888888o");
  // Brain.Screen.setCursor(3,0);
  // Brain.Screen.print("                         88\" . \"88");
  // Brain.Screen.setCursor(4,0);
  // Brain.Screen.print("                         (| -_- |)");
  // Brain.Screen.setCursor(5,0);
  // Brain.Screen.print("                         O\\  =  /O");
  // Brain.Screen.setCursor(6,0);
  // Brain.Screen.print("                       ___/`---'\\____");
  // Brain.Screen.setCursor(7,0);
  // Brain.Screen.print("                    .'  \\\\|     |//  `.");
  // Brain.Screen.setCursor(8,0);
  // Brain.Screen.print("                   /  \\\\|||  :  |||//  \\");
  // Brain.Screen.setCursor(9,0);
  // Brain.Screen.print("                  /  _||||| -:- |||||_  \\");
  // Brain.Screen.setCursor(10,0);
  // Brain.Screen.print("                  |   | \\\\\\  -  /// |   |");
  // Brain.Screen.setCursor(11,0);
  // Brain.Screen.print("                  | \\_|  ''\\---/''  |   |");
  // Brain.Screen.setCursor(12,0);
  // Brain.Screen.print("                  \\  .-\\__       __/-.  /");
  // Brain.Screen.setCursor(13,0);
  // Brain.Screen.print("                ___`. .'  /--.--\\ `. . __");
  // Brain.Screen.setCursor(14,0);
  // Brain.Screen.print("             ."" '<  `.___\\_<|>_/__.'  >'"".");
  // Brain.Screen.setCursor(15,0);
  // Brain.Screen.print("           | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |");
  // Brain.Screen.setCursor(16,0);
  // Brain.Screen.print("            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /");
  // Brain.Screen.setCursor(17,0);
  // Brain.Screen.print("       ======`-.____`-.___\\_____/___.-`____.-'======");
  // Brain.Screen.setCursor(18,0);
  // Brain.Screen.print("                          `=---='");

    // resetPuncher();
  driver();


}
int main() {
  mogoclp.set(1);
  intakee.set(0);
  vex::thread a([] { racistmech(vex::color::blue); });
  a.detach();
    drawing();
  // calibob();
  // graphic();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }

} 