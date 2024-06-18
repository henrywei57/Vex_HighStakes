#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller con;
//controller 

motor l1 = motor(PORT19, ratio6_1, 0);
motor l2 = motor(PORT18, ratio6_1, 1);
motor l3 = motor(PORT20, ratio6_1, 0);
motor_group leftmo = motor_group(l1, l2, l3);
motor r1 = motor(PORT11, ratio6_1, 1);
motor r2 = motor(PORT12, ratio6_1, 0);
motor r3 = motor(PORT13, ratio6_1, 1);
motor_group rightmo = motor_group(r1, r2, r3);
inertial bob = inertial(PORT15);
//chassis 


motor inta = motor(PORT16, ratio18_1, 0);
//intake


digital_out intawing1 = digital_out(Brain.ThreeWirePort.A);
digital_out intawing2 = digital_out(Brain.ThreeWirePort.H);
digital_out dropdown = digital_out(Brain.ThreeWirePort.D);
digital_out hangg = digital_out(Brain.ThreeWirePort.F);
//pneumatics

motor smlboi = motor(PORT10, ratio18_1, 0);
motor ptoboi = motor(PORT1, ratio36_1, 1);
//other motors

distance dst = distance(PORT2);
//distance sensor

// VEXcode generated  



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}