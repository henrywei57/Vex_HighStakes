#pragma once

class PIDControl {
    public:
        PIDControl();
        PIDControl(double kp, double ki = 0, double kd = 0, double MOE = 5, int minReachedCall = 10);
        void computeFromError(double error);
        double getValue();
        bool reachedGoal();
    private:
        double kP, kI, kD;
        double newError, sumError, deltaError;
        double prevError;
        double marginOfError;
        int minReachedCall, reachedCallCount;
};