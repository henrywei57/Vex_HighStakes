#include "vex.h"
#include "robot-config.h"
#include <vector>
#include "other_function.h"
#include "utility/buttons.h"

using namespace vex;

int autonoption = 0;

#include "vex.h"

using namespace vex;


TouchButton::TouchButton(int xPos, int yPos, int w, int h, const char* btnLabel)
    : x(xPos), y(yPos), width(w), height(h), label(btnLabel), pressed(false) {}

// Draw the button on the screen
void TouchButton::draw() {
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(pressed ? green : black); // Change color when pressed
    Brain.Screen.drawRectangle(x, y, width, height);
    Brain.Screen.printAt(x + 10, y + height / 2 + 5, label); // Display label
}

// Check if the button is pressed
bool TouchButton::isPressed() {
    if (Brain.Screen.pressing()) {
        int touchX = Brain.Screen.xPosition();
        int touchY = Brain.Screen.yPosition();

        // Check if touch is within the button's bounds
        if (touchX >= x && touchX <= x + width && touchY >= y && touchY <= y + height) {
            pressed = true;
            return true;
        }
    } else {
        pressed = false;
    }
    return false;
}

