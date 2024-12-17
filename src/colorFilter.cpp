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
        int hue = colorseancor.hue();  // Get current hue value
        if (hue > 80 && colorseancor.isNearObject()) {  // Check hue and object detection
            wait(200, msec);  // Debounce delay
            intas.stop(hold);  // Stop intake motor
            wait(100, msec);  // Hold for 1 second
        }
        wait(10, msec);  // Reduce CPU usage
    }
}