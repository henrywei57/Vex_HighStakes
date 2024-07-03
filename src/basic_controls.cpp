#include "basic_control.h"
#include "main.h"
#include "robot-config.h"
#include "other_function.h"


void keybind(){
    intaout();
    intain();
    calibrate();
}

void intaout(){
    inta.spin(fwd, 100, pct);
}
void intain(){
    inta.spin(reverse, 100, pct);
}

void calibrate(){
    calibob();
}