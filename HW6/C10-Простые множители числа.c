/*
C10-Простые множители числа 


Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)

Input format
Целое положительное число.

Output format
Последовательность всех простых множителей данного числа в порядке возрастания.


Input
12
Output
2 2 3
 */


#include <stdio.h>

void print_simple(int n)
{
	for(int i=2; i<=n; i++){
		
		while (n%i == 0){
			printf("%d ", i);
			n /=i;
		}
		
	}
}


int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	print_simple(number);
	
	return 0;
}

