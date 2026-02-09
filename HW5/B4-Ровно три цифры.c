/*
B4-Ровно три цифры

Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

Input format
Целое положительное число

Output format
Одно слов: YES или NO

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int digit;
	
	if(scanf("%d", &digit) !=1){
		printf("Error");
		return 1;
	}
	
	// 999 /100=9
	int IF = digit/100;
	
	if(IF>=1 && IF<10){
		printf("YES");
	} else {
		printf("NO");
	}
	
	
	return 0;
}

