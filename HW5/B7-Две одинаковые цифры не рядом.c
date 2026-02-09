/*
B7-Две одинаковые цифры не рядом

Две одинаковые цифры
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, НЕ обязательно стоящие рядом.

Input format
Одно целое число

Output format
Одно слово: YES или NO

Input
1242
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
	
	if(number<0){
	number=-number;
	}
	
	int A, B;
	
	for(; number>0; ){
		A = number%10;
		number /=10;
		
		for(int i = number; i>0; i/=10){
			B = i%10;
			if(A == B){
				printf("YES");
				return 0;
			}
		}
		
	} 
	    
	    
	printf("NO");    
	
	return 0;
}

