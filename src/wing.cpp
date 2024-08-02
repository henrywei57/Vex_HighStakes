#include "vex.h"
#include "robot-config.h"
#include "utility/buttons.h"

using namespace vex;

bool Inta = 1;
bool Clamp = 1;


void intake(){
    if(Inta){
        intakee.set(true);
        Inta = 0;
    }
    else if(!Inta){
        intakee.set(false);
        Inta = 1;
    }
}

void mogo_clamp(){
    if(Clamp){
        mogoclp.set(1);
        Clamp = 0;
    }
    else if(!Clamp){
        mogoclp.set(false);
        Clamp = 1;
    }
}

