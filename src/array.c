#include "./array.h"

#include <stdio.h>
#include <stdint.h>

Array new_array(int n) {
	Array out={calloc(n, sizeof(int)), n};
	return out;
}

Array random_arr(int size, int range) {
    Array array = new_array(size);
    randomize(&array, range);
    return array;
}

void randomize(Array* array_p, int range) {
    for(int i=0; i<array_p->n; i++) {
        int rand_val = (rand()%range*2)-range;
        set(array_p, i, rand_val);
    }
}

void print_arr(Array array) {
    printf("[");
	for(int i=0; i<array.n; i++) {
		printf("%d", array.arr[i]);
        if(i!=array.n-1) {
            printf(", ");
        }
	}
	printf("]\n");
}

int is_sorted(Array array) {
	int prev=array.arr[0];
	for(int i=1; i<array.n; i++) {
		if (prev>array.arr[i])
			return 0;
		prev=array.arr[i];
	}
	return 1;
}

void set(Array* array, int index, int val) {
    array->arr[index] = val;
}