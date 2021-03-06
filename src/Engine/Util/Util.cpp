#include <math.h>
#include <stdio.h>

#include "Util/Util.h"

#define PI 3.14159265

float util::inverse_sqrt(float magnitude) {
    float magnitude_half = 0.5 * magnitude;
    int i = *(int*)&magnitude;
    i = 0x5f3759df - (i >> 1);
    magnitude = *(float*)&i;
    return magnitude * (1.5f - magnitude_half * magnitude * magnitude);
}

// Angle counterclockwise from vertical in degrees
double util::angle(double from_x, double from_y, double to_x, double to_y) {
    double delta_x = to_x - from_x;
    double delta_y = to_y - from_y;

    double theta_radians = atan2(delta_y, delta_x);

    // Convert to degrees
    // Add by 90 to set angle from vertical (12 o'clock)
    // As opposed to the normal angle in standard trig (3 o'clock)
    double normal_angle = (theta_radians * 180 / PI) + 90;
    return normal_angle;
}
