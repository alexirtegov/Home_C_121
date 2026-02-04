/*
A8-Наибольшее из трех чисел

Наибольшее из трех чисел
Ввести три числа и найти наибольшее из них

Input format
Три целых числа через пробел

Output format
Одно наибольшее целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	
	(A>B && A>C)?printf("%d", A):
	((B>A && B>C)?printf("%d", B):
	printf("%d", C));
	
	

	
	return 0;
}

