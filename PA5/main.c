/*
	Author: Nathan Brown
	Created: 10/08/2019 (National Hydrogen and Fuel Cell Day! Because the atomic weight of hydrogen is 1.008)
	Description: Text-based version of Yahtzee!
	Note: I worked out a significant portion of the functions for this project with Oscar, so there are likely to be many similarities in our functions, program flow, and variables.
*/

#include "yahtzee.h"

int main(void)
{
	int dice[5] = { 0 };
	int hold[5] = { 0 };
	int frequency[7] = { 0, 0, 0, 0, 0 };
	int score1[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int score2[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int roll_count = 1, turn_count = 1;
	char option = '\0';

	srand(time(NULL));
	printf("WELCOME TO THE WORLD OF YAHTZEE!\n");

	display_menu();

	//Rolling sequence
	roll_count = 1;
	option = '\0';
	while (roll_count < 4 && option != 'n') {
		roll_dice(dice);
		display_dice(dice);
		option = roll_continue(roll_count);
		if (option == 'y')
			hold_dice(hold);
		roll_count++;
	}
	
	//Scoring sequence
	option = '\0';
	scorecard(score1);
	option = get_scoring_method();
	/*For debugging purposes
	dice[0] = 3;
	dice[1] = 3;
	dice[2] = 3;
	dice[3] = 3;
	dice[4] = 3;*/
	tally_frequency(dice, frequency);
	calculate_score(option, dice, frequency);

	turn_count++;

	return 0;
}