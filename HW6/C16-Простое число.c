/*
C16-Простое число


Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу. int is_prime(int n)

Input format
Одно целое не отрицательное число.
Output format
YES или NO


Input
13
Output
YES
 */


#include <stdio.h>

int is_prime(int n)
{
	int res =1;

	if (n < 2) {
        return 0;
    }	
	
	for(int i =2; i<n; i++){

		if(n%i ==0){
			res=0;
			break;
		}
	}
	
	return res;
}


int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	int res = is_prime(number);
	
	res == 1 ? printf("YES") : printf("NO");
	
	
	return 0;
}

