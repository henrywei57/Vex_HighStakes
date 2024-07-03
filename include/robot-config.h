#include "vex.h"
#include "main.h"
using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial bob;
extern controller con;
extern motor l1;
extern motor l2;
extern motor l3;
extern motor_group leftmo;
extern motor_group puncher;
extern motor r1;
extern motor r2;
extern motor r3;
extern motor_group rightmo;
extern motor inta;
extern motor smlboi;
extern motor ptoboi;
extern digital_out intawing1;
extern digital_out intawing2;
extern digital_out dropdown;
extern digital_out hangg;
extern distance dst;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );