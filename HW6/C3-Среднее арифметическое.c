/*
C3-Среднее арифметическое


Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров). int middle(int a, int b)

Input format
Два целых не отрицательных числа
Output format
Одно целое число

Examples
Input
5 7
Output
6
 */



#include <stdio.h>

int middle(int n, int p)
{
	int res=(n+p)/2;
	

	return res;
}


int main(int argc, char **argv)
{
	
	int a, b;
	
	if (scanf("%d %d", &a, &b) !=2){
		puts("Wrong input");
		return 1;
	}
	

	
	printf ("%d", middle(a, b));
	
	return 0;
}

