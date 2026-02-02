/*
A4-Произведение трех чисел
Сумма и произведение трех чисел
Ввести три числа, найти их сумму и произведение.

Input format
Три целых числа через пробел.

Output format
Строка вида
%d+%d+%d=%d
%d*%d*%d=%d

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	int sum = A+B+C;
	int multip = A*B*C;
	printf("%d+%d+%d=%d\n",A, B, C, sum);
	printf("%d*%d*%d=%d\n",A, B, C, multip);
	
	return 0;
}

