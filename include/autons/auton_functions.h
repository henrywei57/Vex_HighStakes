#pragma once
namespace auton {
    extern double sped;
    extern double turnSped;
    extern double marginOfErrorForTurning;
    double heading_convert(double heading);
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity = 100, double turnMaxVelocity = 100, double timeoutMs = 1500, double MOE = 3);
    void turnToAngle(double angle, double MaxVelocity = 100, double timeoutMs = 1500, double MOE = 3);
    void driveVelocity(double leftPct, double rightPct);
    void turn(float turn_degree);
    void setHeading(int degree);
    void suk(int speed);
    void unsuk(int speed);
    extern double fwdspd;
    void armmovement(double angle, double MaxVelocity = 100, double timeoutMs = 1500);
}