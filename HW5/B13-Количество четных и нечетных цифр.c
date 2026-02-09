/*
B13-Количество четных и нечетных цифр


Посчитать количество четных и нечетных цифр числа.

Input format
Одно целое неотрицательное число.
Output format
Два числа через пробел. Количество четных и нечетных цифр в числе.


Input
1234
Output
2 2
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	int even_num=0, odd_num=0;
	
	for(int current=0; number>0; number /=10){
		current = number%10;
		
		if(current%2 == 0){
			even_num ++;
		} else {
			odd_num ++;
		}
		
	}
	
	printf("%d %d", even_num, odd_num);
	
	
	return 0;
}

