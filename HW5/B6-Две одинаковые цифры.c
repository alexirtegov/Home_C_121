/*
B6-Две одинаковые цифры

Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

Input format
Одно целое число
Output format
Единственное слов: YES или NO

Input
1224
Output
YES
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	for(int last, b_last; number>0;){
		last = number%10;
		number /=10;
		b_last = number%10;
		
		if(last == b_last){
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
	
	return 0;
}

