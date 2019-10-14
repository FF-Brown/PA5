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
	Function: roll_count()
	Date Created: 10/09/2019
	Last Modified:
	Description: Displays # of rolls this round. Asks if player is ready to score their roll. If count == 3, they don't have a choice. Returns (y/n)
	Input parameters: Number of rolls so far
	Returns: (y/n)
	Preconditions: Roll count available, player's turn has begun
	Postconditions: Player has chosen whether to score or continue rolling. Number of rolls displayed.
*/
char roll_count(int roll_num);
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
void scorecard(int scores[]);
void roll_dice(int dice[])
{
	for (int i = 0; i < 5; i++){
		dice[i] = rand() % 6 + 1;
	}
}
void display_dice(int dice[])
{
	for (int i = 0; i < 5; i++){
		printf("Die %d: %d\n", i + 1, dice[i]);
	}
}
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
char roll_continue(void)
{
	char option = '\0';
	while (option != 'y' && option != 'n') {
		printf("Keep rolling?\n");
		scanf(" %c", &option);
		if (option != 'y' && option != 'n')
			printf("Invalid input.\n");
	}
	return option;
}
//Scoring
void scoring(int scores[]);
int get_score_method(void);
bool scorecard_check(int arr[]);
void sort_arr(int arr[], int size);
void sum_arr(int arr[], int size);
void final_scores(int p1_scores[], int p2_scores[]);
