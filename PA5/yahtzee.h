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

void display_menu(void);
void rules(void);
void roll_dice(int dice[], int hold[]);
void display_dice(int dice[]);
void hold_dice(int hold[]);
char roll_continue(int roll_count);
void scorecard(int score[]);
void tally_frequency(int dice[], int frequency[]);
int get_scoring_method(void);
int calculate_score(int option, int dice[], int frequency[]);
int sum_array(int dice[], int size);
bool scorecard_check(int arr[], int option);
int uppers_bonus(int scores[]);
void final_scores(int p1_scores[], int p2_scores[]);
char cont_playing(void);
