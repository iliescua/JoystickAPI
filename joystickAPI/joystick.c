/*
 * Andrew Iliescu
 * 4/1/19
 * File the provides logic for what the servos should do based on joystick movement
 */

#include "alt_types.h"
#include "system.h"

volatile alt_u32* joystickBase = JOYSTICK_ADC_SEQUENCER_CSR_BASE;
volatile alt_u32* joystickBot = JOYSTICK_ADC_SAMPLE_STORE_CSR_BASE;
volatile alt_u32* joystickTop = JOYSTICK_ADC_SAMPLE_STORE_CSR_BASE + 0x4;
volatile alt_u32* switchBase = SLIDER_SWITCHES_BASE;
volatile alt_u32* hex5Base = HEX5_HEX4_BASE;
int distBot = 0;
int distTop = 0;

/* By taking the data from the Sample Store and splitting it based on channel,
 * that number then divided by 20 falls into the range for the servo and then moves
 * the servos based on that
 */
void joystickRotate() {
	distBot = *joystickBot / 20; //Puts it in servo range
	distTop = *joystickTop / 20; //Puts it in servo range
	moveServos(distBot, 0); //Move bot servo
	moveServos(distTop, 1); //Move top servo
	//Added to show Sample Store and channel data on 7Seg
	if (*switchBase == 0) { //Channel 0
		displayNum(*joystickBot);
		*hex5Base = (0x3F) << 8;
	} else if (*switchBase == 1) { //Channel 1
		displayNum(*joystickTop);
		*hex5Base = (0x06) << 8;
	}
}

/* This method is used to simply toggle whether the josytick data gets read or
 * not if it is moved
 */
void toggleJoystick(int choice) {
	if (choice == 0) { //joystick off
		*joystickBase = 0;
	} else if (choice == 1) { //joystick on
		*joystickBase = 1;
	}
}
