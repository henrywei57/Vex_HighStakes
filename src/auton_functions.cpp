#pragma once

#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
#include "botcontrol.h"

double newTurnVelocity;

namespace auton {

    void driveVelocity(double leftPct, double rightPct) {
        double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
        leftPct *= scale;
        rightPct *= scale;
        leftmo.spin(fwd, to_volt(leftPct), volt);
        rightmo.spin(fwd, to_volt(rightPct), volt);
    }
    

    double sped = 0.09;

    void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs, double MOE){
        double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.5 )) * (60.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
        double initLeftMotorDegree = leftmo.position(degrees);
        double initRightMotorDegree = rightmo.position(degrees);
        
        PIDControl drivePID(sped, 0, 0, 3, 10, 5000);
        PIDControl rotateToPID(0.8, 0, 0, 3, 10, 5000);
        
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMotorDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMotorDegree;
            double averageTraveledDegree = (leftTraveledDegree + rightTraveledDegree) / 2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error, 5);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));
            
            double rotateError = angle - bob.rotation(deg);
            rotateToPID.computeFromError(rotateError, 5);
            newTurnVelocity = rotateToPID.getValue();
            newTurnVelocity = fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity));
            
            double finalLeftVelocity = newLinearVelocity - newTurnVelocity;
            double finalRightVelocity = newLinearVelocity + newTurnVelocity;
            driveVelocity(finalLeftVelocity, finalRightVelocity);
            
            task::sleep(5);
        }
        leftmo.stop();
        rightmo.stop();
    }

    void turnToAngle(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(1.0, 0, 0, 3, 10, 5000);
        
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal()){
            double error = angle - bob.rotation(degrees);
            rotateToPID.computeFromError(error, 5);
            double newTurnVelocity = rotateToPID.getValue(); 
            driveVelocity(-newTurnVelocity, newTurnVelocity);
            
            task::sleep(5);
        }
        leftmo.stop();
        rightmo.stop();
    }

    // void driveVelocity(double leftPct, double rightPct){
    //     double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
    //     leftPct *= scale;
    //     rightPct *= scale;
    //     leftmo.spin(fwd, to_volt(leftPct), volt);
    //     rightmo.spin(fwd, to_volt(rightPct), volt);
    // }

    void setHeading(int degree){
        bob.setHeading(degree, degrees);
    }

    void suk(int speed){
        intas.spin(fwd, speed, pct);
    }

    void unsuk(int speed){
        intas.spin(reverse, speed, pct);
    }

    void drive(double tiles, double linearMaxVelocity, double timeoutMs){
        double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.5 )) * (60.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
        double initLeftMotorDegree = leftmo.position(degrees);
        double initRightMotorDegree = rightmo.position(degrees);
        
        PIDControl drivePID(0.09, 0, 0, 3, 10, 5000);
        
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !drivePID.reachedGoal()) {
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMotorDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMotorDegree;
            double averageTraveledDegree = (leftTraveledDegree + rightTraveledDegree) / 2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error, 5);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));
            
            driveVelocity(newLinearVelocity, newLinearVelocity);
            
            task::sleep(5);
        }
        leftmo.stop();
        rightmo.stop();
    }
}
