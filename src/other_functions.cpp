#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>  // Include for sprintf
#include "botcontrol.h"
#include "autons/auton.h"
#include "graphics.h"
using namespace vex;

void calibob(){
    bob.startCalibration();
    while(bob.isCalibrating()){
    wait(10, msec);
  }
}

struct Point {
    double x;
    double y;
};
void drawRotatedRectangle(int x, int y, int width, int height, double angle) {
    double angle_rad = angle * (M_PI / 180.0); // Convert angle to radians

    // Calculate half dimensions
    double half_width = width / 2.0;
    double half_height = height / 2.0;

    // Calculate corner points relative to the top-left corner
    Point corners[4] = {
        {static_cast<double>(-half_width), static_cast<double>(-half_height)},
        {static_cast<double>(half_width), static_cast<double>(-half_height)},
        {static_cast<double>(half_width), static_cast<double>(half_height)},
        {static_cast<double>(-half_width), static_cast<double>(half_height)}
    };

    // Rotate the points and draw lines between them
    Point rotated_corners[4];
    for (int i = 0; i < 4; i++) {
        double x_rel = corners[i].x;
        double y_rel = corners[i].y;
        rotated_corners[i].x = x + (x_rel * cos(angle_rad) - y_rel * sin(angle_rad));
        rotated_corners[i].y = y + (x_rel * sin(angle_rad) + y_rel * cos(angle_rad));
    }

    // Draw lines between rotated corners
    for (int i = 0; i < 4; i++) {
        int x1 = static_cast<int>(rotated_corners[i].x);
        int y1 = static_cast<int>(rotated_corners[i].y);
        int x2 = static_cast<int>(rotated_corners[(i + 1) % 4].x);
        int y2 = static_cast<int>(rotated_corners[(i + 1) % 4].y);
        Brain.Screen.drawLine(x1, y1, x2, y2);
    }
}

std::string intToString(int x) {
    // Buffer large enough to hold any 32-bit integer, assuming base 10
    char buffer[12];  // Enough for -2147483648 and terminating null

    // Convert integer to string
    std::sprintf(buffer, "%d", x);

    return std::string(buffer);
}

void qweqweqwe(){
    Brain.Screen.drawLine(420,30,420,80);
    Brain.Screen.drawLine(420,30,415,55);
    Brain.Screen.drawLine(420,30,425,55);
    Brain.Screen.drawLine(415,55,420,80);
    Brain.Screen.drawLine(425,55,420,80);

    Brain.Screen.drawLine(395,55,445,55);
    Brain.Screen.drawLine(395,55,420,50);
    Brain.Screen.drawLine(395,55,420,60);
    Brain.Screen.drawLine(420,50,445,55);
    Brain.Screen.drawLine(420,60,445,55);

    Brain.Screen.printAt(416, 25, "0");
    Brain.Screen.printAt(450, 63, "90");
    Brain.Screen.printAt(405, 100, "180");
    Brain.Screen.printAt(362, 63, "270");


}

void graphic(){



    int x = 200;
    int y = 70;
    int w = 80;
    int h = 100;


    while(1){

        int angle = bob.angle();  // Assuming bob.angle() gives the angle
        int angle_mod = angle % 360;  // Ensure angle is within 0-359 range

        std::string angle_str = intToString(angle_mod);

        // Clear previous drawing (if necessary) and draw rotated rectangle
        Brain.Screen.clearScreen();  // Clear previous content (adjust as needed)
        qweqweqwe();

        drawRotatedRectangle(240, 120, w, h, angle_mod);

        // Print angle_str at a specific position on the screen
        Brain.Screen.printAt(225, 125, angle_str.c_str());
        Brain.Screen.render();
        wait(20, msec);
    }
}



