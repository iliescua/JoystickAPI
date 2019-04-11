/*
 * Andrew Iliescu
 * Lab1: SevenSegDisplay.c
 * Holds the logic for the sevenSegDisplay.c
 */
#include "sevenSegDisplay.h"
#include "system.h"
#include "alt_types.h"
#include <stdio.h>

alt_u32* sevenSegBase = (alt_u32*) HEX3_HEX0_BASE; //7Seg Base
//alt_u16* switchBase = (alt_u16*) SLIDER_SWITCHES_BASE; //Switches base

char val[5] = { 0 }; //Value array that stores user input
int num[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67 }; //Array that stores 7Seg display vals

void clearSeg() { //Sets 0 on first 7 Seg
	*sevenSegBase = num[0];
}

void displayNum(alt_u32 input) {//Displays the switch number on 7Seg
	sprintf(val, "%d", input);
	if ((input / 1000) > 0) { //If the value entered is 4 digits
		*sevenSegBase = (num[(val[0] - 48)] << 24) + (num[(val[1] - 48)] << 16)
				+ (num[(val[2] - 48)] << 8) + (num[(val[3] - 48)]); //Num entered -48 is the deci val to be shown
	} else if ((input / 100) > 0) { //If the value entered is 3 digits
		*sevenSegBase = (num[(val[0] - 48)] << 16) + (num[(val[1] - 48)] << 8)
				+ (*sevenSegBase = num[(val[2] - 48)]);
	} else if ((input / 10) > 0) { //If the value entered is 2 digits
		*sevenSegBase = (num[(val[0] - 48)] << 8) + (num[(val[1] - 48)]);
	} else { //If the value entered is 1 digit
		*sevenSegBase = num[(val[0] - 48)];
	}
}

//void updateVal() { //Updates the value from which switches are flipped
//	sprintf(val, "%d", input);
//}
