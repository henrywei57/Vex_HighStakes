#include "vex.h"
#include "robot-config.h"
#include <vector>
#include "other_function.h"

using namespace vex;

int autonoption = 0;

#include "vex.h"

using namespace vex;

class TouchButton {
private:
    int x, y, width, height; // Button position and size
    const char* label;       // Button label
    bool pressed;            // Button pressed state

public:
    // Constructor
    TouchButton(int xPos, int yPos, int w, int h, const char* btnLabel)
        : x(xPos), y(yPos), width(w), height(h), label(btnLabel), pressed(false) {}

    // Draw the button on the screen
    void draw() {
        Brain.Screen.setPenColor(white);
        Brain.Screen.setFillColor(pressed ? green : black); // Change color when pressed
        Brain.Screen.drawRectangle(x, y, width, height);
        Brain.Screen.printAt(x + 10, y + height / 2 + 5, label); // Display label
    }

    // Check if the button is pressed
    bool isPressed() {
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
};

int main() {
    // Initialize the V5 Brain
    vex::brain Brain;

    // Create buttons
    TouchButton button1(50, 50, 100, 60, "Button 1");
    TouchButton button2(200, 50, 100, 60, "Button 2");

    while (true) {
        // Clear the screen
        Brain.Screen.clearScreen();

        // Draw buttons
        button1.draw();
        button2.draw();

        // Check if buttons are pressed
        if (button1.isPressed()) {
            Brain.Screen.setCursor(10, 1);
            Brain.Screen.print("Button 1 Pressed!");
        }
        if (button2.isPressed()) {
            Brain.Screen.setCursor(10, 1);
            Brain.Screen.print("Button 2 Pressed!");
        }

        // Small delay to avoid screen flickering
        wait(20, msec);
    }
}