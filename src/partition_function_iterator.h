#ifndef PARTITION_FUNCTION_ITERATOR_H_OR_H_
#define PARTITION_FUNCTION_ITERATOR_H_TERATOR_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

void partition_function_iterator__init(
		const int _entire_size);

bool partition_function_iterator__has_next();

int * const partition_function_iterator__next();

#endif /* PARTITION_FUNCTION_ITERATOR_H_ION_ITERATOR_H_ */
