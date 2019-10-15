/*
	Author: Nathan Brown
	Created: 10/08/2019
	Description: Text-based version of Yahtzee! Function definitions
*/

#include "yahtzee.h"

//Gameplay
/*
	Function: display_menu()
	Date Created: 10/09/2019
	Last Modified:
	Description: Displays menu until valid input received
	Input parameters: None
	Returns: None
	Preconditions: None, really
	Postconditions: Rules displayed, game started, or game exited
*/
void display_menu(void)
{
	int option = 0;
	
	//Display menu until receiving valid input
	option = 0;
	while (option < 1 || option > 3)
	{
		printf("\n~~~~~~ MAIN MENU ~~~~~~\n\n");
		printf("1. Display game rules.\n");
		printf("2. Begin game.\n");
		printf("3. Exit.\n");
		printf("Select an option by typing the corresponding number.\n");
		scanf("%d", &option);

		//Run process based on input
		switch (option) {
		case RULES:
			rules();
			display_menu();
			break;
		//Leave switch and while loop to begin playing game
		case PLAY:
			break;
		//Exit program
		case EXIT:
			printf("See you next time!\n");
			exit(0);
			break;
		default:
			break;
		}
		if (option < 1 || option > 3)
			printf("Invalid entry.\n");
	}
}
/*
	Function: rules()
	Date Created: 10/09/2019
	Last Modified:
	Description: Displays game rules
	Input parameters: None
	Returns: None
	Preconditions: Menu opened
	Postconditions: Rules displayed
*/
void rules(void)
{
	printf("Yahtzee is one of many popular dice games and can be seen as having some relation to poker.\n");
	printf("On each player's turn, he/she rolls 5 dice. The player can then choose to keep as many of those dice values as they wish and re-roll the rest of the dice to get a higher-scoring combination. A player may roll up to a total of 3 times.\n\n");
	printf("When a player decides to stop rolling and score their roll, they must choose a scoring method from their scorecard. There are 13 options for scoring, enumerated below with explanations.\n\n");
	printf("Upper section of scorecard:\n");
	printf("1's\tScore = sum of 1's rolled\n");
	printf("2's\tScore = sum of 2's rolled\n");
	printf("3's\tScore = sum of 3's rolled\n");
	printf("4's\tScore = sum of 4's rolled\n");
	printf("5's\tScore = sum of 5's rolled\n");
	printf("6's\tScore = sum of 6's rolled\n");
	printf("\nAt the end of the game, if the sum of the scores in the upper section of a player's scorecard is equal to or greater than 63, the player gets 35 extra points.\n");
	printf("\nLower section of scorecard:\n");
	printf("3 of a kind\t\t\t\tScore = sum of all values rolled.\n");
	printf("4 of a kind\t\t\t\tScore = sum of all values rolled.\n");
	printf("Full house (one pair + 3 of a kind)\tScore = 25\n");
	printf("Small straight (Sequence of 4 dice)\tScore = 30\n");
	printf("Large straight (Sequence of 5 dice)\tScore = 40\n");
	printf("Yahtzee (5 of a kind)\t\t\tScore = 50\n");
	printf("Chance (any combination)\t\tScore = sum of all values rolled.\n");
	printf("\nPlayers alternate taking turns until both have played 13 rounds.\n");
	printf("The winner is the player with more points at the end of the game.\n");
}
/*
	Function: scorecard()
	Date Created: 10/09/2019
	Last Modified:
	Description: Displays player's current
	Input parameters: scores[]
	Returns: None
	Preconditions: Player scores available
	Postconditions: Scorecard displayed, filled in with values.
*/
void roll_dice(int dice[])
{
	for (int i = 0; i < 5; i++){
		dice[i] = rand() % 6 + 1;
	}
}
/*
	Function: display_dice()
	Date Created: 10/13/2019
	Description: Displays results of last roll
	Input parameters: dice[]
	Returns: None
	Preconditions: Player has rolled at least once
	Postconditions: Roll results displayed
*/
void display_dice(int dice[])
{
	for (int i = 0; i < 5; i++){
		printf("Die %d: %d\n", i + 1, dice[i]);
	}
}
/*
	Function: hold_dice()
	Date Created: 10/13/2019
	Description: Allows player to choose which dice to hold for the next roll
	Input parameters: hold[]
	Returns: None
	Preconditions: Player has rolled and chosen to roll again
	Postconditions: hold[] populated with user decisions. 1 = hold die, 0 = reroll die
*/
void hold_dice(int hold[])
{
	char option = '\0';
	for (int i = 0; i < 5; i++) {
		while (option != 'y' && option != 'n') {
			printf("Would you like to hold Die %d? (y/n)\n", i + 1);
			scanf(" %c", &option);
			if (option == 'y')
				hold[i] = 1;
			else if (option == 'n')
				hold[i] = 0;
			else
				printf("Invalid input.\n");
		}
		option = '\0';
	}
}
/*
	Function: roll_continue()
	Date Created: 10/13/2019
	Last Modified:
	Description: Displays # of rolls this round. Asks if player is ready to score their roll. If count == 3, they don't have a choice. Returns (y/n)
	Input parameters: Number of rolls so far
	Returns: (y/n)
	Preconditions: Roll count available, player's turn has begun
	Postconditions: Player has chosen whether to score or continue rolling. Number of rolls displayed.
*/
char roll_continue(int roll_count)
{
	char option = '\0';
	printf("That was roll #%d. ", roll_count);
	if (roll_count < 3) {
		while (option != 'y' && option != 'n') {
			printf("Keep rolling?\n");
			scanf(" %c", &option);
			if (option != 'y' && option != 'n')
				printf("Invalid input.\n");
		}
	}
	else if (roll_count == 3)
		option = 'n';
	return option;
}
//Scoring
/*
	Function: scorecard()
	Date Created: 10/09/2019
	Description: Displays player's current scorecard so they can choose how to score their roll
	Input parameters: score[]
	Returns: None
	Preconditions: hold[] initialized, player has finished their round of rolling
	Postconditions: Scorecard displayed
*/
void scorecard(int score[])
{
	printf("Your current scores are as follows: \n\n");
	for (int i = 0; i < 6; i++) {
		printf("%d.) %d's: %d\n", i + 1, i + 1, score[i]);
	}
	printf("7.) Three-of-a-kind: %d\n", score[6]);
	printf("8.) Four-of-a-kind: %d\n", score[7]);
	printf("9.) Full House: %d\n", score[8]);
	printf("10.) Small Straight: %d\n", score[9]);
	printf("11.) Large Straight: %d\n", score[10]);
	printf("12.) Yahtzee: %d\n", score[11]);
	printf("13.) Chance: %d\n", score[12]);

}
/*
	Function: tally_frequency()
	Date Created: 10/14/2019
	Description: Finds the frequency of each die value in dice[]
	Input parameters: dice[] for intput and frequency[] for output
	Returns: None
	Preconditions: Player round has ended, dice[] is populated
	Postconditions: frequency[] populated for use
*/
void tally_frequency(int dice[], int frequency[])
{
	for (int i = 0; i < 5; i++){
		for (int j = 1; j < 7; j++){
			if (dice[i] == (j))
				frequency[j] += 1;
		}
	}
	/* For debugging purposes
	for (int k = 1; k < 7; k++) {
		printf("You rolled %d %d's.\n", frequency[k], k);
	}*/
}
/*
	Function: get_scoring_method()
	Date Created: 10/14/2019
	Description: Allows user to choose method for scoring their roll
	Input parameters: None
	Returns: User's choice (int)
	Preconditions: Round finished. Scorecard displayed
	Postconditions: User has selected a scoring method
*/
int get_scoring_method(void)
{
	int option = 0;
	while (option < 1 || option > 13) {
		printf("How would you like to score your roll? Enter the number on the scorecard referencing the method you would like to choose.\n");
		scanf("%d", &option);
		if (option < 1 || option > 13)
			printf("Invalid entry.\n");
	}
	return option;
}
int calculate_score(int option, int dice[], int frequency[])
{
	int score = 0, success = 0;
	switch (option) {
		case 1:
			score = frequency[1];
			printf("You got %d points!\n", score);
			break;
		case 2:
			score = frequency[2] * 2;
			printf("You got %d points!\n", score);
			break;
		case 3:
			score = frequency[3] * 3;
			printf("You got %d points!\n", score);
			break;
		case 4:
			score = frequency[4] * 4;
			printf("You got %d points!\n", score);
			break;
		case 5:
			score = frequency[5] * 5;
			printf("You got %d points!\n", score);
			break;
		case 6:
			score = frequency[6] * 6;
			printf("You got %d points!\n", score);
			break;
		case THREE_OF_A_KIND:
			for (int i = 0; i < 7; i++) {
				if (frequency[i] >= 3) {
					success = 1;
					score = sum_array(dice, 5);
				}
			}
			if (success == 1)
				printf("You got %d points!\n", score);
			else if (success == 0)
				printf("Sorry, you don't have a three-of-a-kind, so you get 0 points. ;(\n");
		break;
		case FOUR_OF_A_KIND:
			for (int i = 0; i < 7; i++) {
				if (frequency[i] >= 4) {
					success = 1;
					score = sum_array(dice, 5);
				}
			}
			if (success == 1)
				printf("You got %d points!\n", score);
			else if (success == 0)
				printf("Sorry, you don't have a three-of-a-kind, so you get 0 points. ;(\n");
			break;
		case FULL_HOUSE:
			for (int i = 0; i < 7; i++) {
				if (frequency[i] == 2) {
					for (int j = 0; j < 7; j++) {
						if (frequency[j] == 3) {
							success = 1;
							score = 25;
						}
					}
				}
			}
			if (success == 1)
				printf("You got 25 points!\n");
			else if (success == 0)
				printf("Sorry, you don't have a full house, so you get 0 points.\n");
			break;
		case SM_STRAIGHT:
			//There are only 3 combinations (not including the extra number) that yield a small straight. 1-4, 2-5, and 3-6. All of these include 3 and 4. Therefore we first check if the player rolled at least one 3 and one 4.
			//Because screw sorting.
			if (frequency[3] >= 1 && frequency[4] >= 1) {
				//If so, we check whether they have a two.
				if (frequency[2] >= 1) {
					//If so, if they also have a 1 or a 5, they have a small straight.
					if (frequency[1] >= 1 || frequency[5] >= 1) {
						success = 1;
						score = 25;
					}
				}
				//If they did not have a two, they must have both a 5 and a 6 to have a small straight.
				else if (frequency[5] >= 1 && frequency[6] >= 1) {
					success = 1;
					score = 25;
				}
			}
			//Let the player know whether they got the points for the straight or not. 'Int success' resets each time the function is called, so no problem using it in multiple cases.
			if (success == 1)
				printf("You got 25 points!\n");
			else if (success == 0)
				printf("Sorry, you don't have a small straight, so you get 0 points. ;(\n");
			break;
		case LG_STRAIGHT:
			//There are only 2 combinations that yield a large straight. 1-5 or 2-6. Both require 2-5. Hence:
			if (frequency[2] >= 1 && frequency[3] >= 1 && frequency[4] >= 1 && frequency[5] >= 1) {
				//If the player has 2-5, they only need a 1 or a 6 to make the large straight.
				if (frequency[1] >= 1 || frequency[6] >= 1) {
					success = 1;
					score = 30;
				}
			}
			if (success == 1)
				printf("You got 30 points!\n");
			else if (success == 0)
				printf("Sorry, you don't have a large straight, so you get 0 points. ;(\n");
			break;
		case YAHTZEE:
			for (int i = 0; i < 7; i++) {
				if (frequency[i] == 5) {
					success = 1;
					score = 25;
				}
			}
			if (success == 1)
				printf("You got 50 points!\n");
			else if (success == 0)
				printf("Sorry, you don't have a yahtzee, so you get 0 points. ;(\n");
			break;
		case CHANCE:
			score = sum_array(dice, 5);
			printf("You got %d points!\n", score);
			break;
	}
	return score;
}
int sum_array(int dice[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += dice[i];
	}
	return sum;
}
void scoring(int scores[]);
bool scorecard_check(int arr[]);
void sort_arr(int arr[], int size);
void final_scores(int p1_scores[], int p2_scores[]);
