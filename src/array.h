#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef struct {
	int* arr;
	const int n;
} Array;

void set(Array* array, int i, int val);
Array new_array(int n);
void print_arr(Array array);
int is_sorted(Array array);
void randomize(Array* array_p, int limit);
Array random_arr(int size, int range);