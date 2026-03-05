/*
E11-Отсортировать по последней цифре

Считать массив из 10 элементов и отсортировать его по последней цифре.

Input format
10 целых чисел через пробел

Output format
Этот же массив отсортированный по последней цифре

Input
14  25  13  30  76  58  32  11  41  97
Output
30  11  41  32  13  14  25  76  97  58
 */


#include <stdio.h>



#define SIZE 10

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

void replacement(int arr[])
{
   for(int i=0; i<SIZE; i++){
		for(int j=i+1; j<SIZE; j++){
			if(arr[i]%10 > arr[j]%10){
				int temp = arr[j];
				 arr[j]= arr[i];
				 arr[i] = temp;
			}
		}
   }
}


void output_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		printf("%d ", arr[i]);
	}
}


int main(int argc, char **argv)
{
	int array[SIZE];
	
	input_array(array); 
	
	replacement(array);
	
	output_array(array); 
	
	return 0;
}
