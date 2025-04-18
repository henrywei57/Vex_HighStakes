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
extern motor inta1;
extern motor inta2;
extern motor inta3;
extern motor_group intas;
extern digital_out armbig;
extern digital_out clamp;
extern digital_out racistpiston;
extern digital_out wrgclr;
extern digital_out armsmall;
extern distance dst;
extern distance aaasssddd;
extern motor arm;
extern optical colorseancor;
extern encoder xEncoder;
extern encoder yEncoder;
extern rotation lb;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );