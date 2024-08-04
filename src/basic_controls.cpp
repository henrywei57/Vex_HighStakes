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
    intas.spin(fwd, 100, pct);
}
void intain(){
    intas.spin(reverse, 100, pct);
}

void calibrate(){
    calibob();
}
