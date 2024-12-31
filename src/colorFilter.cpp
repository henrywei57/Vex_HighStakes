#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include <cmath>
#include <iostream>


using namespace vex;

void getHue(){
    while(1){
        std::cout<<colorseancor.hue()<<std::endl;
        wait(10,msec);
    }
}


void filterRed() {
    while (true) {
        int hue = colorseancor.hue();  
        if (hue > 80 && colorseancor.isNearObject()) {  
            wait(200, msec);  
            intas.stop(hold);  
            wait(100, msec);  
        }
        wait(10, msec);  
    }
}