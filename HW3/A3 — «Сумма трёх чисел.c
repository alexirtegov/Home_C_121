/*
A3 — «Сумма трёх чисел»
Сумма трёх чисел
Ввести три числа, найти их сумму.

Формат ввода
Три целых числа

Формат вывода
Строка вида %d+%d+%d=%d
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	int D = A+B+C;
	printf("%d+%d+%d=%d\n",A, B, C, D);
	
	return 0;
}

