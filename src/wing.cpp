#include "vex.h"
#include "robot-config.h"
#include "utility/buttons.h"
#include "autons/auton_functions.h"

using namespace vex;

bool Inta = 1;
bool Clamp = 1;
bool ifrhf = 1;




void intake(){
    if(Inta){
        armbig.set(true);
        Inta = 0;
    }
    else if(!Inta){
        armbig.set(false);
        Inta = 1;
    }
}

void mogo_clamp(){
    if(Clamp){
        clamp.set(1);
        Clamp = 0;
    }
    else if(!Clamp){
        clamp.set(false);
        Clamp = 1;
    }
}
void asdr(){
    if(ifrhf){
        armsmall.set(1);
        ifrhf = 0;
    }
    else if(!ifrhf){
        armsmall.set(0);
        ifrhf = 1;
    }
}

void armup(){
    arm.spin(fwd,35,pct);
    wait(100,msec);
    arm.stop(hold);
}

void armdown(){
    arm.spin(reverse,35,pct);
    wait(100,msec);
    arm.stop(hold);
    // auton::armmovement(5,100,1000);
}
bool armmermer = false;
void armupup(){
    if(armmermer){
        armmermer = 0;
    }
    else if(!armmermer){
        armmermer = 1;
    }
}




