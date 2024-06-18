#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void close_qua(){
    sped = 0.05;
    setHeading(0);
    suk(100);
    sped = 0.055;
    driveAndTurn(-1.72, 23, 100, 100);
    turnToAngle(0);
    driveAndTurn(0.05, 15, 100, 100);
    turnToAngle(89);
    inta.stop(hold);
    intawing2.set(1);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-1.15, 100, 100, 100);
    sped = 0.05;
    intawing2.set(0);
    driveAndTurn(0.2, 90, 100, 100);
    driveAndTurn(0.36, 45, 30, 100);
    // turnToAngle(45);
    driveAndTurn(2.02, 50, 100, 100);
    turnToAngle(-30);
    dropdown.set(1);
    driveAndTurn(0.6, -85, 97, 100);
    dropdown.set(0);
    sped = 0.1;
    driveAndTurn(1.33, -90, 100, 100);

}
void far_elim_2(){
    timer tmer;
    sped = 0.065;
    setHeading(0);
    suk(70);
    driveAndTurn(-2.345, 3);
    turnToAngle(133);
    intawing1.set(1);
    intawing2.set(1);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-1.5, 123);
    sped = 0.06;
    intawing1.set(0);
    intawing2.set(0);
    turnToAngle(-90);
    suk(30);
    driveAndTurn(-1.24, -63, 100, 60);
    // driveAndTurn(0.1, -60, 100, 80);
    turnToAngle(-15);
    driveAndTurn(1.78, -10, 100, 90);
    turnToAngle(-80);
    dropdown.set(1);
    driveAndTurn(0.6, -150, 80, 30);
    dropdown.set(0);
    turnToAngle(50);
    intawing1.set(1);
    wait(200, msec);
    unsuk(100);
    wait(400, msec);
    sped = 0.3;
    driveAndTurn(-0.7, 70, 100, 100);
    driveAndTurn(100, 68.34, 100, 100);
    // driveAndTurn(0.5, -45, 100, 100);

}

void close_elim(){
    setHeading(0);

    sped = 0.07;
    suk(50);
    driveAndTurn(-1.93, 0);
    turnToAngle(80);
    intawing2.set(1);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-0.98, 45);
    driveAndTurn(0.4, 45);
    sped = 0.07;
    intawing2.set(0);
    turnToAngle(13.5);
    driveAndTurn(2, 16);    
    intawing2.set(1);
    wait(300, msec);
    intawing2.set(0);
    turnToAngle(100);
    intawing1.set(1);
    driveAndTurn(0.5, 100);

}

void far_qua(){
    setHeading(0);
    sped = 0.07;
    suk(80);
    driveAndTurn(-2, 0);
    wait(0.1, sec);
    inta.stop(hold);
    driveAndTurn(1.87, 0);
    unsuk(100);
    turnToAngle(60);
    wait(50, msec);
    turnToAngle(-80);
    suk(70);
    driveAndTurn(-1.32, -70, 100, 90);
    driveAndTurn(1.2, -70);
    dropdown.set(1);
    driveAndTurn(0.6, -170, 50, 20);
    dropdown.set(0);
    turnToAngle(50);
    sped = 0.10;
    unsuk(100);
    wait(450, msec);
    intawing2.set(1);
    intawing1.set(1);
    driveAndTurn(-1.1, 53, 100, 100);
    intawing2.set(0);
    intawing1.set(0);
    sped = 0.07;
    driveAndTurn(2.9, 110, 100, 99);
    turnToAngle(110);
    leftmo.stop(coast);
    rightmo.stop(coast);
    // driveAndTurn(0.45, 110, 100, 100);
}

void far_elim(){
    setHeading(0);
    sped = 0.07;
    intawing1.set(1);
    wait(150, msec);
    intawing1.set(0);
    driveAndTurn(-1.65, -45, 100, 100);
    intawing2.set(1);
    suk(10);
    turnToAngle(310, 20);
    suk(100);
    intawing2.set(0);
    driveAndTurn(-0.735, 270, 100, 100, 600);
    turnToAngle(90);
    unsuk(100);
    intawing2.set(1);
    intawing1.set(1);
    driveAndTurn(-1.3, 90, 100, 100);
    intawing2.set(0);
    intawing1.set(0);
    // dropdown.set(1);
    driveAndTurn(1.7, 0, 37, 100, 1500);
    driveAndTurn(1.55, -150, 100, 90);
    // dropdown.set(0);
    suk(100);
    driveAndTurn(-2.38, -90, 100, 100);
    turnToAngle(90);
    unsuk(30);
    driveAndTurn(-3, 0, 100, 30);
    driveAndTurn(2.5, 90, 100, 35);
    // driveAndTurn(-3,-90, 100, 70);
}