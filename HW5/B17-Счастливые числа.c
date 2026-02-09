/*
B17-Счастливые числа


Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр

Input format
Одно натуральное число большее 10

Output format
Числа у которых сумма цифр равна произведению цифр через пробел в порядке возрастания. Не превосходящие введенное число.


Input
200
Output
22 123 132
 */



#include <stdio.h>

int main(int argc, char **argv)
{
	
	int number;
	
	if(scanf("%d", &number)!=1){
		printf("wrong input");
		return 0;
	}
	
	if(number<10){
		printf("wrong input");
		return 0;
	}	
	
	
	for(int count=10; count<=number;count++){ //ввели число 124
		int sum=0;
		int multip=1;
		int i;
		
		
		for(i = count;i>0;){// теперь i=124
						
			sum+=i%10;
			multip*=i%10;
			
			i=i/10;
			
		}
		
		if(sum==multip){
			printf(" %d", count);
			}
		
	}
	
	
	return 0;
}
