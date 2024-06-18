#include "basic_control.h"
#include "main.h"
#include "robot-config.h"



void keybind(){
    intaout();
    intain();
}

void intaout(){
    inta.spin(fwd, 100, pct);
}
void intain(){
    inta.spin(reverse, 100, pct);
}