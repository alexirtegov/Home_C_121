/*
E8-Инверсия каждой трети

Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

Input format
12 целых чисел через пробел

Output format
12 целых чисел через пробел


Input
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Output
10 3 -5 4 -10 8 -6 -4 7 5 0 1
 */


#include <stdio.h>



#define SIZE 12

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

void replacement(int arr[])
{
	// 1. Инверсия первой трети (индексы от 0 до 3)
	int left = 0; //0
	int right = SIZE / 3 - 1; // 3
	
	while(left < right){
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;  // сдвигаем левый индекс вправо
		right--; // сдвигаем правый индекс влево
	}
	
	// 2. Инверсия второй половины (индексы от 4 до 7)
	left = SIZE / 3;  // 4
	right = SIZE/3*2 - 1; // 7
	
	while(left < right){
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;  
		right--; 
	}
	
		// 3. Инверсия второй половины (индексы от 8 до 12)
	left = SIZE / 3 *2;  // 8
	right = SIZE-1; // 12
	
	while(left < right){
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;  
		right--; 
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
