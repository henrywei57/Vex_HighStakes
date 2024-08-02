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
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs){
        double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.5 )) * (84.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
        double initLeftMoterDegree = leftmo.position(degrees);
        double initRightMoterDegree = rightmo.position(degrees);
        // PIDControl drivePID(sped, 0, 0, 2);
        PIDControl drivePID(sped, 0, 0, 2);
        PIDControl rotateToPID(0.46, 0, 0, 2);
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
            // Get linear velocity
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMoterDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMoterDegree;
            double averageTraveledDegree = (leftTraveledDegree+rightTraveledDegree)/2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));

            // Get turning velocity
                double rotateError = angle - bob.rotation(deg);
                rotateToPID.computeFromError(rotateError);
                newTurnVelocity = rotateToPID.getValue();
                newTurnVelocity = -(fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity)));
            // Get final velocity
            // double finalLeftVelocity = newLinearVelocity - newTurnVelocity;
            // double finalRightVelocity = newLinearVelocity + newTurnVelocity;
            double finalLeftVelocity = newLinearVelocity + newTurnVelocity;
            double finalRightVelocity = newLinearVelocity - newTurnVelocity;
            driveVelocity(finalLeftVelocity,finalRightVelocity);
            con.Screen.print(error);
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
}