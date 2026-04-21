/*
 * even_check.c
 
 */


#include <stdio.h>
#include "io_operations.h"

void check_even(int number)
{
	if(number%2 == 0){
		printf("%d is even\n", number);
	} else {
		printf("%d is odd\n", number);
	}
}
