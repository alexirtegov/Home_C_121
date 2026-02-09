/*
B16-НОД

Наибольший общий делитель
Составить программу для вычисления НОД с помощью алгоритма Евклида. Даны два натуральных числа. Найти наибольший общий делитель.

Input format
Два неотрицательных целых числа

Output format
Одно целое число наибольший общий делитель

nput
14 21
Output
7

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
		if(a<0||b<0){
		printf("wrong input, 'a' and 'b' must be >0");
		return 0;
		}
	
	for(;a!=b;){
		if(a>b){
			a=a-b;
		}else{
			b=b-a;
		}
	}
	
	
		
	printf("NOD= %d", a);	
		
	return 0;
}
