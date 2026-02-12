/*
C15-Цифры по возрастанию


Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)

Input format
Одно целое не отрицательное число

Output format
YES или NO


Input
258
Output
YES
 */


#include <stdio.h>

int grow_up(int n)
{
	int res =1;
	for(int end, b_end; n>0; ){
		end = n%10;
		n /=10;
		b_end = n%10;
		if(b_end >= end) res =0;
	}
	
	return res;
}


int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	int res = grow_up(number);
	
	res == 1 ? printf("YES") : printf("NO");
	
	return 0;
}



