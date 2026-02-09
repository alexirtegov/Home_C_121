/*
B12-Наименьшая и наибольшая цифра


Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

Input format
Целое неотрицательное число

Output format
Две цифры через пробел. Сначала наименьшая цифра числа, затем наибольшая.


Input
15
Output
1 5

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	int max=0, min=9;
	
	for(int A; number>0; number/=10){
		A = number%10;
		
		if(max < A){
		max = A;
		}
		
		if(min > A){
		min = A;
		}		
		
	}
	
	printf("%d %d", min, max);
	
	return 0;
}

