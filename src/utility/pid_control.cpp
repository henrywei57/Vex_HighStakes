#include "utility/pid_control.h"
#include "main.h"

PIDControl::PIDControl() {
    kP = kI = kD = 0;
    newError = sumError = deltaError = 0;
    prevError = 1e9;
    marginOfError = 5;
    minReachedCall = 10;
    reachedCallCount = 0;
    starti = 10;  // Prevent integrating until error is below this threshold
    timeout = 5000;  // Example timeout in milliseconds
    timeSinceStart = 0;
    timeSettled = 0;
}

PIDControl::PIDControl(double kp, double ki, double kd, double MOE, int minReachedCall, double starti, int timeout) {
    kP = kp;
    kI = ki;
    kD = kd;
    newError = sumError = deltaError = 0;
    prevError = 1e9;
    marginOfError = MOE;
    this->minReachedCall = minReachedCall;
    reachedCallCount = 0;
    this->starti = starti;
    this->timeout = timeout;
    timeSinceStart = 0;
    timeSettled = 0;
}

void PIDControl::computeFromError(double error, int deltaTime) {
    newError = error;
    
    if (fabs(newError) < starti) {
        sumError += newError;
        sumError = fmax(-1000, fmin(1000, sumError)); // Clamp integral term
    }
    
    // Reset integral if error crosses zero
    if ((newError > 0 && prevError < 0) || (newError < 0 && prevError > 0)) {
        sumError = 0;
    }
    
    // Apply low-pass filter to derivative term
    double alpha = 0.8;
    deltaError = alpha * (newError - prevError) + (1 - alpha) * deltaError;
    prevError = newError;
    
    // Update timing variables
    timeSinceStart += deltaTime;
    if (fabs(newError) < marginOfError) {
        timeSettled += deltaTime;
    } else {
        timeSettled = 0;
    }
}

bool PIDControl::reachedGoal() {
    if (timeSinceStart > timeout && timeout != 0) {
        return true; // Timeout condition met
    }
    
    if (timeSettled >= minReachedCall * 10) { // Example: 10ms per loop iteration
        return true;
    }
    
    return false;
}

double PIDControl::getValue() {
    return kP * newError + kI * sumError + kD * deltaError;
}
