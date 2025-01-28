#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H

#include "vex.h"
extern int autonoption;

class TouchButton {
private:
    int x, y, width, height; // Button position and size
    const char* label;       // Button label
    bool pressed;            // Button pressed state

public:
    // Constructor
    TouchButton(int xPos, int yPos, int w, int h, const char* btnLabel);

    // Draw the button on the screen
    void draw();

    // Check if the button is pressed
    bool isPressed();
};

#endif // TOUCHBUTTON_H