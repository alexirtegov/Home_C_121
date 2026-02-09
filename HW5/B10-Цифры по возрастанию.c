/*
B10-Цифры по возрастанию


Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

Input format
Целое число

Output format
YES или NO


Input
1238
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
	
	for(int last, b_last; number>0; number /=10){
		last = number%10;
		number /=10;
		b_last = number%10;
		
		if(b_last >= last){
			printf("NO");
			return 0;
		}
	}
	
	printf("YES");
	
	return 0;
}

