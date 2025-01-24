#include "vex.h"
#include "main.h"
#include "other_function.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller con;
//controller 

motor l1 = motor(PORT3, ratio6_1, 0);
motor l2 = motor(PORT2, ratio6_1, 1);
motor l3 = motor(PORT1, ratio6_1, 0);
motor_group leftmo = motor_group(l1, l2, l3);
motor r1 = motor(PORT10, ratio6_1, 1);
motor r2 = motor(PORT8, ratio6_1, 1);
motor r3 = motor(PORT7, ratio6_1, 0);
motor_group rightmo = motor_group(r1, r2, r3);
inertial bob = inertial(PORT5);
//chassis


motor inta1 = motor(PORT6, ratio18_1, 1);
motor inta2 = motor(PORT21, ratio18_1, 1);
motor_group intas = motor_group(inta1,inta2);
//intake

motor arm = motor(PORT20, ratio36_1, 0);  

digital_out clamp = digital_out(Brain.ThreeWirePort.A);
digital_out armbig = digital_out(Brain.ThreeWirePort.B);
digital_out armsmall = digital_out(Brain.ThreeWirePort.C);
//pneumatics


//other motors

distance aaasssddd = distance(PORT16);
//distance sensor


optical colorseancor = optical(PORT20);
//color sensor

encoder xEncoder = encoder(Brain.ThreeWirePort.D);
encoder yEncoder = encoder(Brain.ThreeWirePort.E);
//encoder


// VEXcode generated  



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}