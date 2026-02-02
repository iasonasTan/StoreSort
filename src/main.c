#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "index_sort.h"
#include "array.h"

void greet();

int main()
{
	greet();
	srand(time(NULL));
	
	Array array = random_arr(15, 50);

	printf("Unsorted: ");
    print_arr(array);

	sort(&array);
	
	printf("Sorted  : ");
	print_arr(array);

	int sorted=is_sorted(array);
	printf("Sorted  : %s\n", sorted?"true":"false");
	return 0;
}

void greet() {
	printf("**********************************\n");
	printf("************ STORE SORT **********\n");
	printf("******** INVENTED BY JASON *******\n");
	printf("************** MAYBE *************\n");
	printf("**********************************\n");
}