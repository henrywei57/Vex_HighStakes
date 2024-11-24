#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
double newTurnVelocity;
namespace auton {

double heading_convert(double heading){
  return(heading > 180) ? heading - 360 : heading;
  /*twenRY Operator A = (condition) ? (true data) : (false data)*/
}
double sped = 0.05;
double previousLinearVelocity = 0;
double previousTurnVelocity = 0;
double maxAccelRate = 12; // Adjust as needed

void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs) {
    double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.25 )) * (60.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
    double initLeftMotorDegree = leftmo.position(degrees);
    double initRightMotorDegree = rightmo.position(degrees);

    PIDControl drivePID(0.08, 0, 0, 1);
    PIDControl rotateToPID(0.46, 0, 0, 1);
    timer timeout;

    while (timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
        // Get linear velocity
        double currentLeftMotorDegree = leftmo.position(degrees);
        double currentRightMotorDegree = rightmo.position(degrees);
        double leftTraveledDegree = currentLeftMotorDegree - initLeftMotorDegree;
        double rightTraveledDegree = currentRightMotorDegree - initRightMotorDegree;
        double averageTraveledDegree = (leftTraveledDegree + rightTraveledDegree) / 2;
        double error = distanceDegree - averageTraveledDegree;

        drivePID.computeFromError(error);
        double targetLinearVelocity = drivePID.getValue();
        targetLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, targetLinearVelocity));

        // Apply slew rate limiting for linear velocity
        double newLinearVelocity = previousLinearVelocity + 
                                   fmax(-maxAccelRate, fmin(maxAccelRate, targetLinearVelocity - previousLinearVelocity));
        previousLinearVelocity = newLinearVelocity;

        // Get turning velocity
        double rotateError = angle - bob.rotation(deg);
        rotateToPID.computeFromError(rotateError);
        double targetTurnVelocity = rotateToPID.getValue();
        targetTurnVelocity = fmax(-turnMaxVelocity, fmin(turnMaxVelocity, targetTurnVelocity));

        // Apply slew rate limiting for turn velocity
        double newTurnVelocity = previousTurnVelocity + 
                                 fmax(-maxAccelRate, fmin(maxAccelRate, targetTurnVelocity - previousTurnVelocity));
        previousTurnVelocity = newTurnVelocity;

        // Get final velocity
        double finalLeftVelocity = newLinearVelocity + newTurnVelocity;
        double finalRightVelocity = newLinearVelocity - newTurnVelocity;

        driveVelocity(finalLeftVelocity, finalRightVelocity);

        // Debugging display
        con.Screen.print("Error: %.2f", error);
        task::sleep(20);
        con.Screen.clearScreen();
    }

    leftmo.stop();
    rightmo.stop();
}
    void turnToAngle(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(0.435, 0, 0, 2);
        // PIDControl rotateToPID();
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal()){
            double error = angle - bob.rotation(degrees);
            rotateToPID.computeFromError(error);
            double newTurnVelocity = rotateToPID.getValue(); 
            driveVelocity(newTurnVelocity, -newTurnVelocity); 
            printf("error%3f\n",error); 
            task::sleep(20); 

        }
        leftmo.stop();
        rightmo.stop();
    }
    void driveVelocity(double leftPct, double rightPct){
        double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
        leftPct *= scale;
        rightPct *= scale;
        leftmo.spin(fwd, leftPct, pct);
        rightmo.spin(fwd, rightPct, pct);
    }
    void setHeading(int degree){
        bob.setHeading(degree, degrees);
    }
    void suk(int speed){
        intas.spin(fwd, speed, pct);
    }
    void unsuk(int speed){
        intas.spin(reverse, speed, pct);
    }
        void armmovement(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(0.775, 0, 0.25, 1);
        double initArmMoterDegree = arm.position(degrees);
        // PIDControl rotateToPID();
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal() && !(con.ButtonRight.pressing()||con.ButtonY.pressing())){
            double currentArmMotorDegree = arm.position(degrees);
            double armTraveledDegree = currentArmMotorDegree - initArmMoterDegree;
            double error = angle - armTraveledDegree;
            rotateToPID.computeFromError(error);
            double newTurnVelocity = rotateToPID.getValue(); 
            arm.spin(fwd,newTurnVelocity,pct); 
            Brain.Screen.print(timeout.value());
            task::sleep(20); 
            Brain.Screen.clearLine();
        }
    }
}