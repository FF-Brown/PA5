/*
	Author: Nathan Brown
	Created: 10/08/2019 (National Hydrogen and Fuel Cell Day! Because the atomic weight of hydrogen is 1.008)
	Description: Text-based version of Yahtzee!
	Note: I worked out a significant portion of the functions for this project with Oscar, so there are likely to be many similarities in our functions, program flow, and variables.
*/

#include "yahtzee.h"

int main(void)
{
	int dice[5] = { 0, 0, 0, 0, 0 };
	int hold[5] = { 0, 0, 0, 0, 0 };
	int frequency[7] = { 0, 0, 0, 0, 0 };
	int score1[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int score2[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int roll_count = 1;
	char option = '\0';
	bool available = false;
	char cont = '\0';

	srand(time(NULL));
	printf("WELCOME TO THE WORLD OF YAHTZEE!\n");

game_start:
	display_menu();

	//Begin gameplay
	for (int n = 0; n < 13; n++) {

		printf("Player 1 turn!\n");
		//Rolling sequence
		//Reset pertinent variables
		roll_count = 1;
		option = '\0';
		for (int i = 0; i < 5; i++) {
			hold[i] = 0;
		}
		for (int i = 0; i < 5; i++) {
			dice[i] = 0;
		}

		while (roll_count < 4 && option != 'n') {
			system("pause");
			roll_dice(dice, hold);
			dice_roll_taham(dice);
			display_dice(dice);
			option = roll_continue(roll_count);
			if (option == 'y')
				hold_dice(hold);
			roll_count++;
		}

		//Scoring sequence
		//Reset pertinent variables
		option = '\0';
		available = false;
		for (int i = 0; i < 7; i++) {
			frequency[i] = 0;
		}

		scorecard(score1);
		while (available == false) {
			option = get_scoring_method();
			available = scorecard_check(score1, option);
		}
		tally_frequency(dice, frequency);
		score1[option - 1] = calculate_score(option, dice, frequency);
		system("pause");
		system("cls");

		//~~~~~~~~~~~~~~~~PLAYER 2~~~~~~~~~~~~~~~~
		printf("Player 2 turn!\n");
		//Rolling sequence
		//Reset pertinent variables
		roll_count = 1;
		option = '\0';
		for (int i = 0; i < 5; i++) {
			hold[i] = 0;
		}
		for (int i = 0; i < 5; i++) {
			dice[i] = 0;
		}

		while (roll_count < 4 && option != 'n') {
			system("pause");
			roll_dice(dice, hold);
			dice_roll_taham(dice);
			display_dice(dice);
			option = roll_continue(roll_count);
			if (option == 'y')
				hold_dice(hold);
			roll_count++;
		}

		//Scoring sequence
		//Reset pertinent variables
		option = '\0';
		available = false;
		for (int i = 0; i < 7; i++) {
			frequency[i] = 0;
		}

		scorecard(score2);
		while (available == false) {
			option = get_scoring_method();
			available = scorecard_check(score2, option);
		}
		tally_frequency(dice, frequency);
		score2[option - 1] = calculate_score(option, dice, frequency);
		system("pause");
		system("cls");
	}
	//			    ||
	//Final scoring vv
	final_scores(score1, score2);

	//Offer another game
	cont = cont_playing();
	if (cont == 'y') {
		goto game_start;
	}
	else {
		printf("See you next time!\n");
		exit(0);
	}

	return 0;
}