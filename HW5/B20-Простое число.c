/*
B20-Простое число

Проверка на простоту
Проверить число на простоту.

Input format
Натуральное число

Output format
Если число является простым напечатать YES, иначе NO

Input
10
Output
NO
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	int number;
	scanf("%d", &number);
	
	if(number == 1){
		printf("NO");
		return 0;
	}
	
		if(number == 2){
		printf("YES");
		return 0;
	}
	
	
	int divisor =2;
	
	while (number>divisor){
		
		if(number%divisor ==0 ){
			printf("NO");
			return 0;
		}
		
		divisor++;
	
		
	}


	printf("YES");
	
	return 0;
}

