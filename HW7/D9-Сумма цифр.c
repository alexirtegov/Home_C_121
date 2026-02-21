/*
D9-Сумма цифр


Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
int sum_digits(int n)

Input format
Одно натуральное число.

Output format
Целое число - сумма цифр введенного числа.


Input
123
Output
6
 */


#include <stdio.h>

int sum_digits(int n)
{
	int sum;
	if(n<=0){
		return 0;
	}
	sum = n%10 + sum_digits(n/10);
	return sum;
}

// 123%10+sum_digits(12)
// 3+2 + sum_digits(1)
//3+2+1 

int main(int argc, char **argv)
{
	int number;
	
	scanf("%d", &number);
	
	printf("%d", sum_digits(number));
	
	return 0;
}

