/*
B5-Сумма цифр

Сумма цифр
Ввести целое число и найти сумму его цифр.

Input format
Одно целое число большее или равное нулю.

Output format
Одно число - сумма цифр

Input
111
Output
3

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int digit, sum=0;
	scanf("%d", &digit);
	
	for(; digit>0; digit/=10){
		sum += digit%10;

	}
	
	printf("%d", sum);
	
	return 0;
}

