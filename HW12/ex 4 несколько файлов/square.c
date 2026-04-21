/*
 * square.c
 */


#include <stdio.h>
#include "math_operations.h"

//реализация функции возведения в квадрат
int square(int number)
{
	return number*number;
}

// Реализация печати
void print_square(int number, int sq)
{
	printf("Square of %d is %d\n", number, sq);
}
