/*
C17-Сумма цифр равна произведению


Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n)

Input format
Целое не отрицательное число

Output format
YES или NO


Input
123
Output
YES
 */


#include <stdio.h>

int is_happy_number(int n)
{
	if (n == 0) return 1;
	
	int sum = 0;
	int multip = 1;
	
	for(; n>0; n /=10){
		sum += n%10;
		multip *= n%10;
	}
	
	return sum == multip ? 1: 0;
}



int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	int res = is_happy_number(number);
	
	res == 1 ? printf("YES") : printf("NO");
	
	return 0;
}

