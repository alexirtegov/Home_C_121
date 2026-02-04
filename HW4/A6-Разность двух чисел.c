/*
A6-Разность двух чисел

Разность двух чисел
Ввести два числа и найти их разность.

Input format
Два целых числа

Output format
Ответ - одно целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, difference;
	scanf("%d %d", &A, &B);
	
	difference = A-B;

	printf("%d", difference);

	
	return 0;
}

