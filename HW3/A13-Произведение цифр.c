/*
A13-Произведение цифр

Произведение цифр
На вход подается произвольное трехзначное число, напечать произведение цифр

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
	

	printf("%d", (any_num%10)*((any_num/10)%10)*(any_num/100));

	
	return 0;
}

