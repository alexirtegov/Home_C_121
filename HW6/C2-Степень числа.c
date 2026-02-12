/*
C2-Степень числа


Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.

Input format
Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0

Output format
Одно целое число

Input
8 3
Output
512
 */


#include <stdio.h>

int power(int n, int p)
{
	int res=1;
	for(;p !=0; --p){
		res *= n;
	
	}
	return res;
}


int main(int argc, char **argv)
{
	
	int N, P;
	
	if (scanf("%d %d", &N, &P) !=2){
		puts("Wrong input");
		return 1;
	}
	
	if (N>1000 && P<0) {
		puts("Wrong input");
		return 1;	
	}
	
	printf ("%d", power(N, P));
	
	return 0;
}

