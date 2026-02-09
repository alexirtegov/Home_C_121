/*
B9-Все цифры четные

Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные.

Input format
Одно целое число

Output format
YES или NO


Input
2684
Output
YES

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	
	if(scanf("%d", &number) !=1){
		printf("wrong input, restart and try again");
		return 0;
	}
	
	for(; number>0; number/=10){
		if (number%2 !=0){
			printf("NO");
			return 0;
		} 
	}
	
	printf("YES");
	return 0;
}

