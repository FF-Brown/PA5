/*
	Author: Nathan Brown
	Created: 10/08/2019 (National Hydrogen and Fuel Cell Day! Because the atomic weight of hydrogen is 1.008)
	Description: Text-based version of Yahtzee!
*/

#include "yahtzee.h"

int main(void)
{
	int dice[5] = { 0, 0, 0, 0, 0 };
	int hold[5] = { 0, 0, 0, 0, 0 };
	int roll_count = 0, turn_count = 1;
	char option = '\0';

	srand(time(NULL));
	printf("WELCOME TO THE WORLD OF YAHTZEE!\n");
	
	while (roll_count <= 3 && option != 'n') {
		roll_dice(dice);
		display_dice(dice);
		option = roll_continue();
		if (option == 'y')
			hold_dice(hold);
		roll_count++;
	}
	turn_count++;

	return 0;
}