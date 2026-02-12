/*
C5-Сумма от 1 до N


Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

Input format
Одно целое положительное число N

Output format
Целое число - сумма чисел от 1 до N


Input
100
Output
5050
 */


#include <stdio.h>

int sum_digit(int number)
{
	int sum=0;
	
	for(int i=0; i<=number; i++){
		sum += i;
	}
	return sum;
}


int main(int argc, char **argv)
{
	
	int number;
	
	scanf("%d", &number);
	
	printf("%d", sum_digit(number));
	
	return 0;
}

