/*
C9-Факториал

Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)

Input format
Целое положительное число не больше 20

Output format
Целое положительное число


Input
5
Output
120
Например, факториал числа 5 будет равен 1 × 2 × 3 × 4 × 5 = 120.
 */


#include <stdio.h>

int factorial(int number)
{
	int factorial =1;
	for(int i=1; i<=number; i++){
		factorial *=i;
	}
	return factorial;
}

int main(int argc, char **argv)
{
	
	int number;
	
	scanf("%d", &number);
	
	printf("%d", factorial(number));
	
	
	
	return 0;
}

