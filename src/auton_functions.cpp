#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
#include  "botcontrol.h"
double newTurnVelocity;
namespace auton {


    double sped = 0.055;
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs, double MOE){
        double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.5 )) * (60.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
        double initLeftMoterDegree = leftmo.position(degrees);
        double initRightMoterDegree = rightmo.position(degrees);
        
        PIDControl drivePID(sped, 0, 0, MOE);
        PIDControl rotateToPID(0.4, 0, 0, 2);
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
            
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMoterDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMoterDegree;
            double averageTraveledDegree = (leftTraveledDegree+rightTraveledDegree)/2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));
            
                double rotateError = angle - bob.rotation(deg);
                rotateToPID.computeFromError(rotateError);
                newTurnVelocity = rotateToPID.getValue();
                newTurnVelocity = (fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity)));
            
            
            
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

    double turnSped = 0.4;
    double marginOfErrorForTurning = 3;
    void turnToAngle(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(turnSped, 0, 0, 3);
        
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
        leftmo.spin(fwd, to_volt(leftPct), volt);
        rightmo.spin(fwd, to_volt(rightPct), volt);
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