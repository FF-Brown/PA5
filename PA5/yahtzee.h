/*
	Author: Nathan Brown
	Created: 10/08/2019
	Description: Text-based version of Yahtzee! Function declarations
*/

#define _CRT_SECURE_NO_WARNINGS
#define RULES 1
#define PLAY 2
#define EXIT 3
#define THREE_OF_A_KIND 7
#define FOUR_OF_A_KIND 8
#define FULL_HOUSE 9
#define SM_STRAIGHT 10
#define LG_STRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

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
void display_menu(void);
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
void rules(void);
/*
	Function: roll_dice()
	Date Created: 10/09/2019
	Last Modified:
	Description: Generates 5 random values from 1-6 inclusive and stores them in an array as dice rolls.
	Input parameters: dice[]
	Returns: None
	Preconditions: Turn has begun
	Postconditions: Rolls stored in dice[]
*/
void roll_dice(int dice[], int hold[]);
/*
	Function: display_dice()
	Date Created: 10/13/2019
	Description: Displays results of last roll
	Input parameters: dice[]
	Returns: None
	Preconditions: Player has rolled at least once
	Postconditions: Roll results displayed
*/
void display_dice(int dice[]);
/*
	Function: hold_dice()
	Date Created: 10/13/2019
	Description: Allows player to choose which dice to hold for the next roll
	Input parameters: hold[]
	Returns: None
	Preconditions: Player has rolled and chosen to roll again
	Postconditions: hold[] populated with user decisions. 1 = hold die, 0 = reroll die
*/
void hold_dice(int hold[]);
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
char roll_continue(int roll_count);
/*
	Function: scorecard()
	Date Created: 10/09/2019
	Description: Displays player's current scorecard so they can choose how to score their roll
	Input parameters: score[]
	Returns: None
	Preconditions: Player has finished their round of rolling
	Postconditions: Scorecard displayed
*/
void scorecard(int score[]);
/*
	Function: tally_frequency()
	Date Created: 10/14/2019
	Description: Finds the frequency of each die value in dice[]
	Input parameters: dice[] for intput and frequency[] for output
	Returns: None
	Preconditions: Player round has ended, dice[] is populated
	Postconditions: frequency[] populated for use
*/
void tally_frequency(int dice[], int frequency[]);
/*
	Function: get_scoring_method()
	Date Created: 10/14/2019
	Description: Allows user to choose method for scoring their roll
	Input parameters: None
	Returns: User's choice (int)
	Preconditions: Round finished. Scorecard displayed
	Postconditions: User has selected a scoring method
*/
int get_scoring_method(void);
/*
	Function: calculate_score()
	Date Created: 10/14/2019
	Description: Massive switch to score roll based on user-selected option.
	Input parameters: User option, dice[], frequency []
	Returns: Score for that roll
	Preconditions: Player has rolled the dice and chosen a scoring method. Frequency calculated.
	Postconditions: Score displayed and returned.
*/
int calculate_score(int option, int dice[], int frequency[]);
/*
	Function: sum_array()
	Date Created: 10/14/2019
	Description: Finds the sum of an array of the given size
	Input parameters: array[], size
	Returns: Sum
	Preconditions: dice[] populated
	Postconditions: Sum returned
*/
int sum_array(int dice[], int size);
/*
	Function: scorecard_check()
	Date Created: 10/14/2019
	Description: Checks a player's scorecard to determine whether they have already used a given scoring method or not.
	Input parameters: score[], option
	Returns: Bool
	Preconditions: Player has chosen a scoring method
	Postconditions: True/false returned
*/
bool scorecard_check(int arr[], int option);
/*
	Function: uppers_bonus()
	Date Created:
	Description: Gives the player bonus points for having a lot of points in the upper scorecard section
	Preconditions: Games over
	Postconditions: Bonus points returned if any
*/
int uppers_bonus(int scores[]);
/*
	Function: final_scores()
	Date Created:
	Description: Calculates both players' final scores
	Preconditions: Game over
	Postconditions: Scores and end result displayed
*/
void final_scores(int p1_scores[], int p2_scores[]);
/*
	Function: cont_playing()
	Date Created:
	Description: Gives player the option to play again
	Preconditions: Game over, all results displayed
	Postconditions: Returns player decision
*/
char cont_playing(void);
/*
	Function: dice_animation()
	Date Created: 10/21/2019
	Description: Displays ASCII art for dice rolls
	Preconditions: Dice have been rolled
	Postconditions: Dice displayed
*/
void dice_animation(int dice[]);
/*
	Function: dice_roll_taham()
	Date Created: 10/21/2019
	Description: Generates several random values to be passed into dice_animation() to create a faux animation. Steps the speed down, then passes the player's actual roll into dice_animation()
		NOTE: Original author of this function is Taham Khaleeq. This finished product is a result of a collaboration between the two of us in which his randomized 'animation' and my graphics were joined into one. The original function by Taham was made for use in Blackjack and as such only accepted one die value. I created the graphics and adjusted his function to work with 5 dice at once.
	Preconditions: Player roll values generated
	Postconditions: dice_animation() called several times
*/
void dice_roll_taham(int player_roll[]);
