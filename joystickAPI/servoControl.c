/*
 * Andrew Iliescu
 * 3/26/19
 * File the provides logic to all servo functions
 */

#include "servoControl.h"
#include "system.h"

volatile alt_u32* servoBot = SERVO_ONE_BASE; //Bot servo base addr
volatile alt_u32* servoTop = SERVO_TWO_BASE; //Top servo base addr

/*
 * This method allows someone to move either servos and in
 * any dir they want by passing in the 2 parameters for
 * dir and servo choice
 */
void moveServos(int num, int choice) {
	if (choice == 0) { //Move bot servo
		*servoBot = num;
	} else if (choice == 1) { //Move top servo
		*servoTop = num;
	}
	usleep(25000); //Delay to not cause servos to stall
}

/*
 * Resets both servos to default start pos
 */
void resetPos() {
	*servoBot = 100;
	*servoTop = 0;
	usleep(25000);//Delay to not cause servos to stall
}

/*
 * This method is used to pan the servos however many
 * times the user wants to
 */
void panServos(int turns) {
	resetPos(); //Has pan process start at default pos
	alt_u32 dur = turns * 200; //200 is the total moves i needs to make 1 turn
	int count = 0; //Var used to keep track of position
	alt_u32 temp = 0; //Keeps track of the number of turns left
	while (temp != dur) {
		*servoBot = count; //Moves 1 turn value
		usleep(5000); //Small delay to allow panning motion
		temp++;
		count++;
		if (count == 200) { //If Bot servo reaches the end of its turn cycle
			while (count != 0) {
				count--; //Moves bot servo back in the other dir
				*servoBot = count;
				usleep(5000); //Small delay to allow panning motion
			}
		}
	}
	usleep(25000); //Delay to not cause servos to stall
}
