/*
E20-Составить наибольшее число

Переставить цифры в числе так, что бы получилось максимальное число.

Input format
Одно целое не отрицательное число

Output format
Целое не отрицательное число


Input
1229
Output
9221
 */


#include <stdio.h>


void PrintMaxNumber(int number)
{
	if (number == 0) {
        printf("0");
        return;
    }
    
    
	int array[11] ={0}; // Фиксированный размер, хватит для любого int (максимум 10 цифр + запас)
	int count=0;
	
	for(int i=0; number>0; i++){
		array[i] = number%10;
		number /=10;
		count++;
	}
	
	// Сортировка пузырьком по убыванию (большие цифры в начало)
	for(int i=0; i<count-1; i++){
		for(int j=i+1; j<count; j++){
			if(array[i]<array[j]){
				int t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
	
	
	for(int i=0; i<count; i++){
		printf("%d", array[i]); 
	}
}



int main(int argc, char **argv)
{
	
	int number;
	
	if(scanf("%d", &number) !=1) printf("Error");
	
	PrintMaxNumber(number);
	
	return 0;
}

