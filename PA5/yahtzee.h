/*
	Author: Nathan Brown
	Created: 10/08/2019
	Description: Text-based version of Yahtzee! Function declarations
*/

#define _CRT_SECURE_NO_WARNINGS
#define RULES 1
#define PLAY 2
#define EXIT 3

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void display_menu(void);
void rules(void);
void roll_dice(int dice[]);
void display_dice(int dice[]);
void hold_dice(int hold[]);
char roll_continue(int roll_count);
void scorecard(int upper_scores[], int lower_scores[]);
void scoring(int scores[]);
int get_score_method(void);
bool scorecard_check(int arr[]);
void sort_arr(int arr[], int size);
void sum_arr(int arr[], int size);
void final_scores(int p1_scores[], int p2_scores[]);
