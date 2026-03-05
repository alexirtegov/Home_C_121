/*
E13-Вторая с конца ноль


Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

Input format
10 целых чисел через пробел.

Output format
Целые числа через пробел, у котороых вторая с конца цифра - ноль


Input
40 105 203 1 14 1000 22 33 44 55
Output
105 203 1 1000
 */


#include <stdio.h>
#define SIZE 10

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

int Replace(int array[], int arr[])
{
	int count =0;
	
	for(int i = 0; i<SIZE; i++){
		if((array[i]/10)%10 == 0){
		
			arr[count] = array[i];
			count++;
		}
	}
	
	return count;
}

void output_array (int arr[], int count)
{
	for(int i=0; i<count; i++){
		printf("%d ", arr[i]);
	}
}

int main(int argc, char **argv)
{
	int array[SIZE];
	input_array(array); 
	
	int arr[SIZE]={0};
	
	int count = Replace(array, arr);
	
	output_array(arr, count); 
	
	return 0;
}
