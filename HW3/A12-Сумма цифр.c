/*
A12-Сумма цифр

Сумма цифр
На вход подается произвольное трехзначное число, напечать сумму цифр

Input format
Трехзначное целое положительное число
Output format
Одно целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int any_num;
	scanf("%d", &any_num);
	
	int num_of_units = any_num%10;
	int num_of_tens = (any_num/10)%10;
	int num_of_hundreds = (any_num/10/10)%10;
	
	int sum_of_units_tens_hundreds = num_of_units+num_of_tens+num_of_hundreds;
	printf("%d", sum_of_units_tens_hundreds);

	
	return 0;
}

