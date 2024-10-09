#include "vex.h"
#include "robot-config.h"

using namespace vex;

int autonoption = 0;

void drawGrid() {
    // Draw the initial grid lines
    Brain.Screen.clearScreen();
    Brain.Screen.setPenColor(white); // Set pen color to white for text
    Brain.Screen.setFillColor(black); // Set fill color to black for non-highlighted blocks
    Brain.Screen.drawLine(0, 135, 480, 135);
    Brain.Screen.drawLine(240, 30, 240, 240);
    Brain.Screen.drawLine(0, 30, 480, 30);
    Brain.Screen.drawLine(240, 30, 240, 0);

    // Display labels in each grid section with white text on a black background
    Brain.Screen.printAt(315, 95, "Close Elim");
    Brain.Screen.printAt(85, 95, "Far Elim");  
    Brain.Screen.printAt(80, 195, "Far Qua");  
    Brain.Screen.printAt(310, 195, "Close Qua");  
}

void highlightBlock(int x, int y, bool highlight) {
    // Set the fill color based on whether to highlight or not
    Brain.Screen.setFillColor(highlight ? green : black); // Green for highlight, black otherwise
    Brain.Screen.setPenColor(white); // Always set text color to white for visibility

    if (y <= 120 && x >= 240) {
        // Close Elim block
        Brain.Screen.drawRectangle(240, 30, 240, 105);
        Brain.Screen.printAt(315, 95, "Close Elim");
    } else if (y <= 120 && x <= 240) {
        // Far Elim block
        Brain.Screen.drawRectangle(0, 30, 240, 105);
        Brain.Screen.printAt(85, 95, "Far Elim");
    } else if (y >= 120 && x <= 240) {
        // Far Qua block
        Brain.Screen.drawRectangle(0, 135, 240, 105);
        Brain.Screen.printAt(80, 195, "Far Qua");
    } else if (y >= 120 && x >= 240) {
        // Close Qua block
        Brain.Screen.drawRectangle(240, 135, 240, 105);
        Brain.Screen.printAt(310, 195, "Close Qua");
    }
}

void board() {
    drawGrid(); // Draw initial grid

    while (1) {
        if (Brain.Screen.pressing()) {
            int X = Brain.Screen.xPosition();
            int Y = Brain.Screen.yPosition();

            drawGrid();  // Reset grid before updating

            // Check which block is selected and highlight it
            if ((Y <= 120) && (X >= 240)) {
                highlightBlock(X, Y, true);
                autonoption = 1;
            } else if ((Y <= 120) && (X <= 240)) {
                highlightBlock(X, Y, true);
                autonoption = 2;
            } else if ((Y >= 120) && (X <= 240)) {
                highlightBlock(X, Y, true);
                autonoption = 3;
            } else if ((Y >= 120) && (X >= 240)) {
                highlightBlock(X, Y, true);
                autonoption = 4;
            }
        }
        wait(20, msec);
    }
}

//       Brain.Screen.drawLine(100,100,100,200);
//       Brain.Screen.drawLine(150,100,150,200);
//       for (int angle = 0; angle <= 180; angle++) {
//         int x = 125 + 25 * cos(angle * M_PI / 180);
//         int y = 100 - 25 * sin(angle * M_PI / 180);
//         Brain.Screen.drawPixel(x, y);
//       }
//       for (int angle = 0; angle <= 180; angle++) {
//         int x = 175 + 25 * cos(angle * M_PI / 180);
//         int y = 200 - 25 * sin(angle * M_PI / 180);
//         Brain.Screen.drawPixel(x, y);
//       }
//       double angle_rad = -80 * M_PI / 180; // Convert the rotation angle to radians

//       for (int angle = 0; angle <= 180; angle++) {
//         double x = 25 * cos(angle* M_PI / 180);
//         double y = 25 * sin(angle* M_PI / 180);

//         // Rotate the point by the rotation angle
//         int x_rotated = 175 + x * cos(angle_rad) - y * sin(angle_rad);
//         int y_rotated = 200 + x * sin(angle_rad) + y * cos(angle_rad);

//         Brain.Screen.drawPixel(x_rotated, y_rotated);


//       for (int angle = 0; angle <= 180; angle++) {
//         int x = 75 + 25 * cos(angle * M_PI / 180);
//         int y = 200 - 25 * sin(angle * M_PI / 180);
//         Brain.Screen.drawPixel(x, y);
//       }
//       double angle_rad = 80 * M_PI / 180; // Convert the rotation angle to radians

//       for (int angle = 0; angle <= 180; angle++) {
//         double x = 25 * cos(angle* M_PI / 180);
//         double y = 25 * sin(angle* M_PI / 180);

//         // Rotate the point by the rotation angle
//         int x_rotated = 75 + x * cos(angle_rad) - y * sin(angle_rad);
//         int y_rotated = 200 + x * sin(angle_rad) + y * cos(angle_rad);

//         Brain.Screen.drawPixel(x_rotated, y_rotated);
// }
// }
