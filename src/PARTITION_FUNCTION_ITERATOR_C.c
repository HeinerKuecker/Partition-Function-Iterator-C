/*
 ============================================================================
 Name        : PARTITION_FUNCTION_ITERATOR_C.c
 Author      : Heiner Kuecker
 Version     :
 Copyright   : do what you want, no guarantee
 Description : Generate partition set of given int number in C, Ansi-style
 https://de.wikipedia.org/wiki/Partitionsfunktion
 https://en.wikipedia.org/wiki/Partition_function_(number_theory)
 https://de.wikipedia.org/wiki/Partitionierungsproblem
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "partition_function_iterator.h"

#define MAX_NUMBER_TO_BE_PARTITIONED 7

int main(void)
{
	for (int i = 1; i <= MAX_NUMBER_TO_BE_PARTITIONED; ++i)
	{
		printf("%d\n", i);
		fflush(stdout);
		partition_function_iterator__init(i);

		//int cnt = 0;
		while (partition_function_iterator__has_next())
		{
			const int * const current_partition_set =
					partition_function_iterator__next();

			//printf(" [%d]", ++cnt);
			for (int j = 0; current_partition_set[j] != 0; ++j)
			{

				printf(" %d", current_partition_set[j]);
			}
			printf("\n");
			fflush(stdout);
		};
		printf("\n");
		fflush(stdout);
	}

	puts("ok");
	return EXIT_SUCCESS;
}
