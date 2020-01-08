#include "partition_function_iterator.h"

#include <assert.h>

static int entire_size;

static int current_idx;

static bool has_next; // use set_array != NULL as indication

static int * set_array = NULL;

static int * sum_array = NULL;

static void compute_sums(void)
{
	int sum = 0;
	for (int i = 0; i < entire_size; ++i)
	{
		sum += set_array[i];
		sum_array[i] = sum;

		if (sum >= entire_size)
		{
			current_idx = i;
			set_array[i + 1] = 0; // terminator
			return;
		}
	}
}

static void compute_right_values(void)
{
	while (sum_array[current_idx] < entire_size)
	{
		current_idx++;
		set_array[current_idx] = 1;
		sum_array[current_idx] = sum_array[current_idx - 1] + 1;
	}
	set_array[current_idx + 1] = 0; // terminator
}

/*
 * API function to set the number to be partitioned
 */
void partition_function_iterator__init(
		const int _entire_size)
{
	if (set_array != NULL)
	{
		free(set_array);
	}

	if (sum_array != NULL)
	{
		free(sum_array);
	}

	if (_entire_size < 1)
	{
		has_next = false;
		return;
	}
	has_next = true;

	entire_size = _entire_size;

	set_array = malloc((_entire_size + 1) * sizeof(int));

	for (int i = 0; i < _entire_size; ++i)
	{
		set_array[i] = 0;
	}

	sum_array = malloc(_entire_size * sizeof(int));
}

/**
 * API function for checking the existence of the next partitioning.
 */
bool partition_function_iterator__has_next()
{
	return has_next;
}

/**
 * API function to get the next partitioning
 * as zero terminated array.
 */
int * const partition_function_iterator__next()
{
	assert(has_next);

	if (set_array[0] == 0)
	{
		// first run
		for (int i = 0; i < entire_size; ++i)
		{
			set_array[i] = 1;
		}

		compute_sums();
	}
	else if (set_array[0] >= entire_size)
	{
		assert(false);
	}
	else
	{
		while (true)
		{
			--current_idx;

			assert(current_idx >= 0);
			assert(current_idx < entire_size);

			if (sum_array[current_idx] < entire_size)
			{
				set_array[current_idx]++;
				sum_array[current_idx]++;

				compute_right_values();
				break;
			}
		}
	}

	if (set_array[0] >= entire_size)
	{
		has_next = false;
	}

	return set_array;
}

