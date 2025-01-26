#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
#include "botcontrol.h"
#include "odom_functions.h"


    double currX;
    double currY;

    double turn_Kp;
    double move_Kp;
    bool front_rear;

    void moveTo(double x,double y, double turn_Kp, double move_Kp, bool fonrt_rear){
        
    }