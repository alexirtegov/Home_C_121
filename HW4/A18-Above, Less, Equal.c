/*
A18-Above, Less, Equal

Ввести два числа. Если первое число больше второго, то программа печатает слово Above. 
Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.

Input format
Два целых числа
Output format
Одно единственное слово: Above, Less, Equal

 */


#include <stdio.h>

int main(int argc, char **argv)
{

	int A, B;
	scanf("%d %d", &A, &B);
	
	
	(A==B) ? printf("Equal"):
	(A>B) ? printf("Above"):
	printf("Less");
	
	

	
	return 0;
}

