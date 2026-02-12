/*
C14-Сумма цифр четна


Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.

Input format
Одно целое не отрицательное число

Output format
Ответ YES или NO

 
Input
136
Output
YES
 */


#include <stdio.h>

void Is_the_number_even(int number)
{
	int sum_digit =0;
	
	for(; number>0; number /=10){
		sum_digit += number%10;
	}
	
	sum_digit%2 == 0 ? printf ("YES") : printf ("NO");
}

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	Is_the_number_even(number);
	
	return 0;
}

