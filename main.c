/*
 * main.c
 *
 *  Created on: 28 Apr 2020
 *      Author: greg
 */

#include <stdio.h>
#include <stdlib.h>

/* the number and values of the addenda */
enum {DIMENSION = 7};
char addenda[DIMENSION] = {2, 3, 4, 5, 6, 7, 8};

/* number of on/off permutations of DIMENSION bits = 1 bit-shifted left DIMENSION times */
enum {PERMUTATION_COUNT = 1 << DIMENSION};

/* array of structures to hold information about permutations  */
struct permutation_stats_def {
	char count_ones;
	char value_sum;
}permutation_stats[PERMUTATION_COUNT];


void get_stats(void)
{

	for (size_t i = 0; i < PERMUTATION_COUNT; ++i) {

		permutation_stats[i].count_ones = 0;
		permutation_stats[i].value_sum = 0;

		for (size_t j = 0; j < DIMENSION; ++j) {

			/* is bit j of i set to 1? */
			if (i & (1 << j)) {
				++(permutation_stats[i].count_ones);
				permutation_stats[i].value_sum += addenda[j];
			}
		}

	}

}


void print_stats(void)
{
	for (size_t i = 0; i < PERMUTATION_COUNT; ++i) {

		/* print the addenda */
		printf("{ ");
		for (size_t j = 0; j < DIMENSION; ++j) {

			/* is bit j of i set to 1? */
			if (i & (1 << j)) {
				printf("%d ", addenda[j]);
			}
		}
		printf("} ");

		/* print the ones-count and the value sum */
		printf(
			"%d %d\n",
			permutation_stats[i].count_ones,
			permutation_stats[i].value_sum
		);

	}

}


int main(void)
{
	get_stats();
	print_stats();
	return 0;
}
