#include "vex.h"
#include "robot-config.h"
using namespace vex;

void board(){
        ////////////////////////////////////////
  Brain.Screen.drawRectangle(0, 30, 240, 105);
  Brain.Screen.setFillColor(black);
  Brain.Screen.printAt(80, 95, "Far Elim");  
        ////////////////////////////////////////
  Brain.Screen.drawRectangle(240, 30, 240, 105);
  Brain.Screen.printAt(310, 95, "Close Elim");   
        ////////////////////////////////////////
  Brain.Screen.drawRectangle(0, 135, 240, 105);
  Brain.Screen.printAt(85, 195, "Far Qua");  
        ////////////////////////////////////////
  Brain.Screen.drawRectangle(240, 135, 240, 105);
  Brain.Screen.printAt(315, 195, "Close Qua");

}

