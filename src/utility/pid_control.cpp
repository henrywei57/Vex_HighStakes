#include "utility/pid_control.h"
#include "main.h"

PIDControl::PIDControl() {
    kP = kI = kD = 0;
    newError = sumError = deltaError = 0;
    prevError = 1e9;
    marginOfError = 5;
    minReachedCall = 10;
    reachedCallCount = 0;
}
PIDControl::PIDControl(double kp, double ki, double kd, double MOE, int minReachedCall) {
    kP = kp;
    kI = ki;
    kD = kd;
    newError = sumError = deltaError = 0;
    prevError = 1e9;
    marginOfError = MOE;
    this -> minReachedCall = minReachedCall;
    reachedCallCount = 0;
}

void PIDControl::computeFromError(double error) {
    // newError = lowPassFilter(error, prevError, 0.8); // Apply low-pass filter to error
    newError = error;

    if (fabs(newError) > marginOfError) {
        sumError += newError;
        sumError = fmax(-1000, fmin(1000, sumError));  // Clamp integral term
    }

    deltaError = (prevError > 5e8) ? 0 : newError - prevError;
    prevError = newError;
}

double PIDControl::getValue() {
    return kP*newError + kI*sumError + kD*deltaError;
}
bool PIDControl::reachedGoal() {
    if(fabs(newError) < marginOfError){
        reachedCallCount++;
        if(reachedCallCount >= minReachedCall) {
            reachedCallCount = minReachedCall;
            return 1;
        } else {
            return 0;
        }
    } else {
        /* Not close to goal */
        reachedCallCount = 0;
        return 0;
    }
}