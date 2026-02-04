/*
A14-Максимальная цифра


Максимальная цифра
Дано трехзначное число, напечатать макисмальную цифру

Input format
Целое положительное трехзначное число
Output format
Одна цифра
Examples

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C, number;
	scanf("%d", &number);
	
	A=number%10;
	B=(number/10)%10;
	C= (number/100)%10;
	

	
	(A>B && A>C)?printf("%d", A):
	(B>A && B>C)?printf("%d", B):
	printf("%d", C);
	
	

	
	return 0;
}

