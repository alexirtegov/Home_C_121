/*
D10-Проверка на проостоту


Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее.

int is_prime(int n, int delitel)

Input format
Натуральное число

Output format
YES или NO


Input
11
Output
YES
 */


#include <stdio.h>

int is_prime(int n, int delitel)
{
	if(delitel<n){
		
		if(n%delitel ==0){
			return 0;
		}
	
		return is_prime(n, delitel+1);
	}else{
		return 1;
		
	}
}

int main(int argc, char **argv)
{
	
	int number;
	scanf("%d", &number);
	
	if(number ==1) {
		printf("NO\n");
		return 0;
	}
	
	if(number<0){
		 printf("NO\n");
	} else {
		if (is_prime(number, 2) ==1){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}

