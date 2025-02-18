#pragma once

class PIDControl {
    public:
        PIDControl();
        PIDControl(double kp, double ki = 0, double kd = 0, double MOE = 5, int minReachedCall = 10, double starti = 10, int timeout = 5000);
        void computeFromError(double error, int deltaTime);
        double getValue();
        bool reachedGoal();
    private:
        double kP, kI, kD;
        double newError, sumError, deltaError;
        double prevError;
        double marginOfError;
        int minReachedCall, reachedCallCount;
        double starti;
        int timeout;
        int timeSinceStart, timeSettled;
        double lowPassFilter(double current, double previous, double alpha);
};
