#include "vex.h"
#include "robot-config.h"
#include "utility/buttons.h"
#include "autons/auton_functions.h"

using namespace vex;

bool Inta = 1;
bool Clamp = 1;




void intake(){
    if(Inta){
        mogoclp.set(true);
        Inta = 0;
    }
    else if(!Inta){
        mogoclp.set(false);
        Inta = 1;
    }
}

void mogo_clamp(){
    if(Clamp){
        intakee.set(1);
        Clamp = 0;
    }
    else if(!Clamp){
        intakee.set(false);
        Clamp = 1;
    }
}

void armup(){
    arm.spin(fwd,35,pct);
    // wait(1,msec);
    // arm.stop(hold);
}

void armdown(){
    arm.spin(reverse,35,pct);
    // wait(1,msec);
    // arm.stop(hold);
    // auton::armmovement(5,100,1000);
}
void armupup(){
    auton::armmovement(35);
}




