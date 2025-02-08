#pragma once

void calibob();

#include <cmath>  // For M_PI, fmax, fmin, fabs

// Converts radians to degrees
double to_deg(double radians);

// Keeps angle within [-180, 180] degrees
double reduce_negative_180_to_180(double angle);

// Clamps a value between a specified min and max
double Clamp(double value, double min_value, double max_value);

// Ensures a minimum voltage for movement
double clamp_min_voltage(double value, double min_voltage);

// Scales voltage for left motor considering heading correction
double left_voltage_scaling(double drive_voltage, double heading_voltage);

// Scales voltage for right motor considering heading correction
double right_voltage_scaling(double drive_voltage, double heading_voltage);
