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

motor l1 = motor(PORT11, ratio6_1, 1);
motor l2 = motor(PORT12, ratio6_1, 1);
motor l3 = motor(PORT13, ratio6_1, 0);
motor_group leftmo = motor_group(l1, l2, l3);
motor r1 = motor(PORT19, ratio6_1, 0);
motor r2 = motor(PORT17, ratio6_1, 0);
motor r3 = motor(PORT18, ratio6_1, 1);
motor_group rightmo = motor_group(r1, r2, r3);
inertial bob = inertial(PORT15);
//chassis


motor inta1 = motor(PORT1, ratio18_1, 01);
motor inta2 = motor(PORT21, ratio18_1, 0);
motor_group intas = motor_group(inta1,inta2);
//intake

motor arm = motor(PORT10, ratio36_1, 0);  

digital_out intakee = digital_out(Brain.ThreeWirePort.B);
digital_out mogoclp = digital_out(Brain.ThreeWirePort.A);
//pneumatics


//other motors

// distance dst = distance(PORT2);
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