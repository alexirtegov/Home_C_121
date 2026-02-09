/*
B19-Сумма цифр равна 10

Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

Input format
Натуральное число

Output format
YES или NO

Input
1234
Output
YES
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	int number;
	scanf("%d", &number);
	
	int sum_digit_number = 0;
	
	for(; number>0; number/=10){
		sum_digit_number += number%10;
		
	}
	
	sum_digit_number == 10 ? printf ("YES"): printf ("NO");
	
	return 0;
}

