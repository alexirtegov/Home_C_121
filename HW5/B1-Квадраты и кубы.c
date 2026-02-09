/*
B1-Квадраты и кубы

Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.

Input format
Одно целое число не превосходящее 100

Output format
Для каждого из чисел от 1 до введенного числа напечатать квадрат числа и его куб.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//~ printf("please input digit <=100\n");
	
	int digit;
	scanf("%d", &digit);
	
	for (int num=1, i=1; i<=digit; i++){
		printf("%d %d %d\n", num, num*num, num*num*num);
		num++;
	
	}
	
	return 0;
}

