/*
A9-Наибольшее из пяти чисел

Наибольшее из пяти чисел
Ввести пять чисел и найти наибольшее из них.

Input format
Пять целых чисел разделенных пробелом

Output format
Одно целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C, D, E;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	
	
	(A>B && A>C && A>D && A>E)?printf("%d", A):
	(B>C && B>D && B>E && B>A)?printf("%d", B):
	(C>D && C>E && C>A && C>B)?printf("%d", C):
	(D>E && D>A && D>B && D>C)?printf("%d", D):
	printf("%d", E);
	
	

	
	return 0;
}

