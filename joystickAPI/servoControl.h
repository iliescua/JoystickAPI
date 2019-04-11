/*
 * Andrew Iliescu
 * 3/26/19
 * The .h file for the servoControl
 */
#ifndef SERVOCONTROL_H_
#define SERVOCONTROL_H_

#include "alt_types.h"
#include <unistd.h>

//Moves servo and dir based on user choice
void moveServos(int num, int choice);
//Sets both servos to 0 pos
void resetPos();
//Pans the bot servo for the number of turns the user wants
void panServos(int turns);

#endif
