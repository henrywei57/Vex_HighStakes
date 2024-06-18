#include "vex.h"
#include "puncher.h"
#include "robot-config.h"

namespace {
    double cataRevDeg = 360.0;
    double cataSlipToothDeg = 360.0 / 36.0;
    void puncherStateChange();

    void resetPuncherFunction();
    void puncherOneRevolution();
    void spinPuncherToAngle(double degrees);

    bool x = 1;
    int spd = 85;

    int puncherRevolutionCount = 0;
    int punchedCount = 0;

    bool puncherSpinDebounce = false;
    bool isPuncherResetted = false;
    bool canPuncherRun = true;
}

void keybindPuncher()
{
    con.ButtonA.pressed(puncherOneRevolution);
    puncherRevolutionCount = 0;
}

void resetCatapult()
{
    if (isPuncherResetted) {
        return;
    }
    task resetPuncherTask([] () -> int {
        resetPuncherFunction();
        return 1;
    });
}

void puncherThread() {
    // Detect balls
    punchedCount = 0;
    while (true) {
        if(isPuncherResetted && canPuncherRun && dst.objectDistance(mm) < 40 ){
            puncherOneRevolution();
            punchedCount++;
        }
        task::sleep(10);
    }
}

int getPunchedCount() {
    return punchedCount;
}

void setPuncherCanRun(bool canRun) {
    canPuncherRun = canRun;
}

namespace {
    void resetPuncherFunction() {
        isPuncherResetted = false;

        // Spin to slip part
        puncher.resetPosition();
        /*
        timer timeout;
        timeout.reset();

        // Nonslip to slip
        puncher.spin(fwd, 40, pct);
        timeout.reset();
        task::sleep(100);
        while (puncher.torque() > 0.10 && timeout.value() <= 2)
        {
            // printf("Torque: %.3f\n", PuncherMotors.torque());
            task::sleep(10);
        }
        printf("At slip\n");*/
        /* Slip gear is at the start of the slip section */

        // Spin to the start of nonslip
        /*puncher.setMaxTorque(0.10, Nm);
        task::sleep(300);
        puncher.stop();
        printf("At nonslip\n");*/

        /* Slip gear is at the star of nonslip */
        // Spin catapult to bottom
        puncher.setMaxTorque(100, pct);
        puncher.resetPosition();
        spinPuncherToAngle(360.0 * (12.0 / 6.0) * (7 / 36.0));
        puncher.stop(hold);
        puncher.resetPosition();

        isPuncherResetted = true;
    }
    void puncherOneRevolution()
    {
        if (!puncherSpinDebounce)
        {
            puncherSpinDebounce = true;

            puncherRevolutionCount++;
            spinPuncherToAngle(puncherRevolutionCount * 180 * (12.0 / 6.0));
            // spinPuncherToAngle(puncherRevolutionCount * (360*5/3));
        
            puncherSpinDebounce = false;
        }
    }
    void spinPuncherToAngle(double degrees)
    {
        puncher.spin(fwd, 12, volt);
        printf("Spin puncher\n");
        timer runTimeout;
        while (puncher.position(deg) < degrees && runTimeout.value() < 0.5)
        {
            task::sleep(10);
        }
        printf("Target: %.3f, motor: %.3f\n", degrees, puncher.position(deg));
        puncher.stop(hold);
    }
}