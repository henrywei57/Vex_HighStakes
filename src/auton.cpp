#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include "other_function.h"
using namespace vex;
using namespace auton;


void redfffffilter() {
    while (true) {
        int hue = colorseancor.hue();  
        if (hue < 30 && hue>0&&colorseancor.objectDetectThreshold()) {  
            wait(200, msec);  
            intas.stop(hold);  
            con.rumble("-");
            wait(100, msec);  
            suk(100);
        }
        wait(10, msec);  
    }
}



void bluefffffilter() {
    while (true) {
        int hue = colorseancor.hue();  
        if (hue < 300 && hue>80&&colorseancor.objectDetectThreshold()) {  
            wait(200, msec);  
            intas.stop(hold);  
            con.rumble("-");
            wait(100, msec);  
            suk(100);
        }
        wait(10, msec);  
    }
}



bool doIWantItToGoToArm = false;

void reves() {
    while(1){
    while (doIWantItToGoToArm) { 
        suk(90); 

        
        if (aaasssddd.objectDistance(inches) < 1.3) {
            inta1.setPosition(0,degrees);
            inta1.spinToPosition(95,degrees);
            inta2.spin(fwd,80,pct);
            inta1.spin(reverse, 100, pct);
            wait(775, msec);
            inta1.stop(brake);    
            doIWantItToGoToArm = false;     
        }

        wait(10, msec); 
    }
    wait(10, msec); 
    }
}



/*
driveAndTurn(distance, angle, max linear velocity, max turning velocity, stop time, margine of error)
turnToAngle(angle, max turning velocity, stop time, margine of error)
suk(speed)
unsuk(speed)
doIWantItToGoToArm = 1 / turn on redirect
*/


int currStateAuto = 0;
int statesAuto[3] = {35, 180, 0};  // Removed unnecessary '-0'
int targetAuto = 0;

double errorAuto;

void spinToPlaceAuto() {
    double kpAuto = 0.8;
    errorAuto = targetAuto - lb.position(deg);

    if (abs(errorAuto) < 10) { 
        arm.stop(hold);  // Use hold mode to prevent falling
        return;
    }

    double velo = kpAuto * errorAuto;
    arm.spin(fwd, -velo, pct);
}



void nextStateForAuto(){
    currStateAuto += 1;
    if(currStateAuto == 3){
        currStateAuto = 0;
    }
    targetAuto = statesAuto[currStateAuto];
}

void score(){
    currStateAuto = 2;
    targetAuto = statesAuto[currStateAuto];
}


void heyheyhey(){
    currStateAuto = 2;
    targetAuto = 180;
}

void setTarget(double target){
    targetAuto = target;
}


void initializeArmAuto(){
    vex::thread armMoveThread([]{
        while(true){
            spinToPlaceAuto();
            wait(20, msec);  // Slightly increased wait time for stability
        }
    });
}

void downUp(){
    setTarget(360);
    wait(1000,msec);
}

void redl(){}

void bluer(){}

void redr(){

}

void bluel(){
    // 直走(1,0);
    // 卧槽();
}

void 手臂回去(){
    vex::thread peepeepoopoo([]{
        while(true){
            double kpAuto = 0.8;
            errorAuto = -lb.position(deg);
        
            if (abs(errorAuto) < 10) { 
                arm.stop(hold);  // Use hold mode to prevent falling
                break;
            }
        
            double velo = kpAuto * errorAuto;
            arm.spin(fwd, -velo, pct);
        }
    });
}

void 直走(double dist, double ang, double maxLinearSpeed=100, double maxTurnSpeed=100, int stopTime = 1500){
    driveAndTurn(dist,ang,maxLinearSpeed,maxTurnSpeed,stopTime);
}

void 只有直走没有转(double tiles, double linearMaxVelocity=100, double turnMaxVelocity=100, double timeoutMs = 1500){
    drive(tiles, linearMaxVelocity,  turnMaxVelocity,  timeoutMs);
}

void 转到角度(double ang, double maxTurnSpeed=100,int stopTime=1500){
    turnToAngle(ang,maxTurnSpeed,stopTime);
}

void 吸(int x){
    suk(-x);
}

void 不要吸(){
    intas.stop(coast);
}

void 卧槽(){
    leftmo.spin(fwd,100,pct);
    rightmo.spin(fwd,-100,pct);
}

void 等一下(int x, vex::timeUnits y = msec){
    wait(x,y);
}



void skill(){
    calibob();
    timer time;
    lb.resetPosition();
    // initializeArmAuto();
    clamp.set(1);
    while(true){
        double kpAuto = 0.8;
        errorAuto =180 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent falling
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }
    手臂回去();
    driveAndTurn(0.55,5,100,100,800); //done
    clamp.set(0);
    turnToAngle(-135,100,450); // done
    吸(100);
    直走(-1.2,-135,850); //done
    转到角度(-190);
    直走(-2.3,-130); //done
    转到角度(57.5,50,450); //done
    while(true){
        double kpAuto = 0.8;
        errorAuto =15 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent falling
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }
    直走(-1.1,55,100,100); //done
    转到角度(135); // done
    直走(-0.65,135,100,100); //done
    吸(-20);
    while(true){
        double kpAuto = 0.8;
        errorAuto =180 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent falling
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }
    直走(0.65,135,100,100,800); 
    手臂回去();
    吸(100);
    转到角度(55,500);
    直走(-3,50,75,100,2000);
    转到角度(140);
    直走(-1,230,100,70);
    直走(0.8,230,100,100);
    clamp.set(1);
    等一下(100,msec);
    吸(-20);
    直走(-0.3,230,100,100,500);
    转到角度(139);
    直走(3.8,139,70,100,3000);
    clamp.set(0);
    转到角度(225);
    吸(100);
    直走(-1,225);
    转到角度(270,100);
    while(true){
        double kpAuto = 0.8;
        errorAuto =15 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent falling
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }

    直走(-1.7,280,100,20);
    turnToAngle(330);
    直走(-1,330,100,100);
    不要吸();
    while(true){
        double kpAuto = 0.8;
        errorAuto =180 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent fallingz
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }
    吸(100);
    手臂回去();
    直走(0.7,330,100,100);
    转到角度(55);
    直走(-3.2,55,75,100,2000);
    转到角度(-35);
    直走(-1.5,-125,70,100);
    直走(1.3,-170,100,100);
    转到角度(-170);

    // 等一下(100,msec);
    // 吸(-20);
    // printf("%.3f", time.time(seconds));
}

void test(){
    driveAndTurn(1,0);
    driveAndTurn(-1,0);
}

void driverSkillStart(){
    lb.resetPosition();
    // initializeArmAuto();
    clamp.set(1);
    while(true){
        double kpAuto = 0.8;
        errorAuto =180 + lb.position(deg);
    
        if (abs(errorAuto) < 10) { 
            arm.stop(hold);  // Use hold mode to prevent falling
            break;
        }
    
        double velo = kpAuto * errorAuto;
        arm.spin(fwd, velo, pct);
    }
    手臂回去();
    driveAndTurn(0.55,5);
    clamp.set(0);
}