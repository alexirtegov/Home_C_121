/*
B18-Фибоначчи

Числа Фибоначчи
Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …, в которой каждое последующее число равно сумме двух предыдущих.

Input format
Одно натуральное число

Output format
Ряд чисел Фибоначчи через пробел


Input
5
Output
1 1 2 3 5
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	
	if(scanf("%d", &number)!=1 || number<=0){
		printf("wrong input");
		return 0;
	}
	

	
	if(number>=2)
	printf(" 1");
	printf(" 1");
	
    int a=1, b=1, c;	
	for(int i=3; i<=number;i++){
		
		c=a+b;
		printf(" %d", c);
		a=b;
		b=c;
		

	}
	
	
	return 0;
}
