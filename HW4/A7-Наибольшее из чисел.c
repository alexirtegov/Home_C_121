/*
A7-Наибольшее из чисел

Наибольшее из двух чисел
Ввести два числа и вывести их в порядке возрастания.

Input format
Два целых числа

Output format
Два целых числа

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B;
	scanf("%d %d", &A, &B);
	
	
	//~ (A>B)?printf("%d %d", B, A):printf("%d %d", A, B);
	
	if(A>B){
		printf("%d %d", B, A);
	} else {
		printf("%d %d", A, B);
	}


	
	return 0;
}

