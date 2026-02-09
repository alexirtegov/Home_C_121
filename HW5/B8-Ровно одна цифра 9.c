/*
B8-Ровно одна цифра 9

Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

Input format
Одно целое число
Output format
Ответ: YES или NO

Input
1994
Output
NO
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	
	if(scanf("%d", &number) !=1){
		printf("wrong input, restart and try again");
		return 0;
	}
	
	int cnt=0;
	for(int i=1; number>0; ){
		i=number%10;
		if(i==9){
			cnt++;
		}
		number /=10;
	}
	
	if(cnt == 1){
		printf("YES");
	} else {
		printf("NO");
	}
	
	
	return 0;
}

