/*
	Author: Nathan Brown
	Created: 10/08/2019
	Description: Text-based version of Yahtzee! Function declarations
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void display_menu(void);
void rules(void);
char roll_count(int roll_num);
void scorecard(int scores[]);
void roll(int dice[]);
void scoring(int scores[]);
int get_score_method(void);
bool scorecard_check(int arr[]);
void sort_arr(int arr[], int size);
void sum_arr(int arr[], int size);
void final_scores(int p1_scores[], int p2_scores[]);
