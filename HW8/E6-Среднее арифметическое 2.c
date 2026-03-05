/*
E6-Среднее арифметическое 2

Среднее арифметическое массива
Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.

Input format
12 целых чисел через пробел

Output format
Среднее арифметическое в формате "%.2f"


Input
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Output
1.08
 */


#include <stdio.h>



#define SIZE 12

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

float arithmetic_mean (int arr[])
{
	int sum =0;
	
	for(int i=0; i<SIZE; i++){
		sum+= arr[i];
	}
	
	return (float)sum/SIZE;
}

int main(int argc, char **argv)
{
	int array[SIZE];
	
	input_array(array); 
	
	printf("%.2f", arithmetic_mean(array));
	
	return 0;
}
