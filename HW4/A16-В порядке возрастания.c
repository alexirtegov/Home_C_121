/*
A16-В порядке возрастания


В порядке возрастания
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

Input format
Три целых числа
Output format
Одно слово YES или NO

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C;

	
	scanf("%d %d %d", &A, &B, &C);
	
	(A<B && B<C) ? printf("YES") :   printf("NO");
	
	return 0;
}

