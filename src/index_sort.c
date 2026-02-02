#include "index_sort.h"

#include "array.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int map_len(int*, int, const int);
static void init_maps(int*, int, Array, int*, Array);
static void extract_map(int*, Array, int, Array);
static void push(int*, int*, int);

void sort(Array* array) {
	int n = array->n;
	int* arr = array->arr;

	int map_zero=0;
	Array map_neg=new_array(map_len(arr, n, 0)+1);
	Array map_pos=new_array(map_len(arr, n, 1)+1);

	init_maps(arr, n, map_neg, &map_zero, map_pos);
	extract_map(arr, map_neg, map_zero, map_pos);
	
	free(map_pos.arr);
	free(map_neg.arr);
}

static int map_len(int* arr, int n, const int pos) {
	int out=arr[0];
	for(int i=1; i<n; i++) {
		if ( pos&&out<arr[i])out=arr[i];
		if (!pos&&out>arr[i])out=arr[i];
	}
	return abs(out);
}

static void init_maps(int* main_arr, int main_n, 
	Array map_neg, int* map_zero, Array map_pos) {

	for(int i=0; i<main_n; i++) {
		int curr=main_arr[i];
		if(curr>0) {
			map_pos.arr[curr]++;
		} else if (curr<0) {
			map_neg.arr[abs(curr)]++;
		} else {
			(*map_zero)++;
		}
	}
}

static void extract_map(int* main_arr, Array map_neg,
	int map_zero, Array map_pos) {

	int arr_idx=0;
	for (int i=map_neg.n-1; i>0; i--) {
		while(map_neg.arr[i]>0) {
			push(main_arr, &arr_idx, -i);
			map_neg.arr[i]--;
		}
	}
	while(map_zero>0) {
		push(main_arr, &arr_idx, 0);
		map_zero--;
	}
	for(int i=0; i<map_pos.n; i++) {
		while(map_pos.arr[i]>0) {
			push(main_arr, &arr_idx, i);
			map_pos.arr[i]--;
		}
	}

}

static void push(int* arr, int* idx_p, int val) {
	arr[(*idx_p)]=val;
	(*idx_p)++;
}