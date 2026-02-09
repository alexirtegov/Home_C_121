/*
B11-Перевернуть число


Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

Input format
Целое неотрицательное число

Output format
Целое не отрицательное число наоборот


Input
1234
Output
4321
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	if (number == 0) {
        printf("0\n");
        return 0;
	}
	
	int counter = 0; //здесь будем считать число
	
	for(int current; number>0; number /=10){
		 current= number%10;
		 counter=counter*10+current;
		 
	}
	
	printf("%d", counter); 
	
	return 0;
}

