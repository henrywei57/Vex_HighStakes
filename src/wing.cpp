#include "vex.h"
#include "robot-config.h"
#include "utility/buttons.h"

using namespace vex;

bool Front = 1;
bool Back = 1;
bool hanggg = 1;


void Front_wings(){
    if(Front){
        dropdown.set(true);
        Front = 0;
    }
    else if(!Front){
        dropdown.set(false);
        Front = 1;
    }
}

void Back_wings(){
    if(Back){
        intawing1.set(1);
        intawing2.set(1);
        Back = 0;
    }
    else if(!Back){
        intawing1.set(false);
        intawing2.set(false);
        Back = 1;
    }
}
void hang(){
    if(hanggg){
        hangg.set(1);
        hanggg = 0;
    }
    else if(!hanggg){
        hangg.set(0);
        hanggg = 1;
    }
}

