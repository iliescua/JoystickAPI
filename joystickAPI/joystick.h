/*
 * Andrew Iliescu
 * 4/1/19
 * The .h file for the joystick
 */
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include "alt_types.h"
#include <unistd.h>
#include "servoControl.h"
#include "sevenSegDisplay.h"

//The method that allows the servos to move based on joystick dir
void joystickRotate();
//Method used to toggle whether the joystick data gets sent through or not
void toggleJoystick(int choice);

#endif
