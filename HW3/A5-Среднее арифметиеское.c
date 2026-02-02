/*
A5-Среднее арифметиеское
Среднее арифметическое трех чисел
Ввести три числа, найти их среднее арифметическое.

Input format
Три целых числа

Output format
Вещественное число в формате %.2f

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	float arithmetic_mean = (float)(A+B+C)/3;

	printf("%.2f\n", arithmetic_mean);
	
	return 0;
}

