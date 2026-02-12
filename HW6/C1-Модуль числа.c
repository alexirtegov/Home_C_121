/*
C1-Модуль числа

Модуль числа
Составить функцию, модуль числа и привести пример ее использования.

Input format
Целое число

Output format
Целое не отрицательное число


Input
-100
Output
100
 */


#include <stdio.h>

int modul (int num)
{
	return (num < 0) ? -num : num;
}


int main(int argc, char **argv)
{
	
	int number;
	
	scanf("%d", &number);
	
	printf("%d", modul(number));
	
	return 0;
}

