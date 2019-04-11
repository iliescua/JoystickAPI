/*
 * Andrew Iliescu
 * 4/1/19
 * Main method
 */
#include "joystick.h"

int main() {
	toggleJoystick(1); //Enable reading from ADC
	while (1) {
		joystickRotate(); //Takes joystick data and moves servos
	}
	return 0;
}
