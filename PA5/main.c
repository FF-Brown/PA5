/*
	Author: Nathan Brown
	Created: 10/08/2019 (National Hydrogen and Fuel Cell Day! Because the atomic weight of hydrogen is 1.008)
	Description: Text-based version of Yahtzee!
*/

#include "yahtzee.h"

int main(void)
{
	int dice[5] = { 0 };
	int hold[5] = { 0 };
	int uppers1[6] = { -1 }, uppers2[6] = { -1 };
	int lowers1[7] = { -1 }, lowers2[7] = { -1 };
	int roll_count = 1, turn_count = 1;
	char option = '\0';

	srand(time(NULL));
	printf("WELCOME TO THE WORLD OF YAHTZEE!\n");

	display_menu();

	//Rolling sequence
	while (roll_count < 4 && option != 'n') {
		roll_dice(dice);
		display_dice(dice);
		option = roll_continue(roll_count);
		if (option == 'y')
			hold_dice(hold);
		roll_count++;
	}
	
	//Scoring sequence
	scorecard(uppers1, lowers1);

	turn_count++;

	return 0;
}