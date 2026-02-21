/*
D7-Печать от N до 1

От 1 до N
Составить рекурсивную функцию, печать всех чисел от N до 1.

Input format
Одно натуральное число

Output format
Последовательность целых чисел от введенного числа до 1, через пробел.


Input
5
Output
5 4 3 2 1
 */


#include <stdio.h>

void numbers_from_N_to_1(int N)
{
	printf("%d ", N);
	
	if(N==1) return;
	numbers_from_N_to_1(N-1);
}

int main(int argc, char **argv)
{
	
	int N;
	scanf("%d", &N);
	
	numbers_from_N_to_1(N);
	
	return 0;
}

