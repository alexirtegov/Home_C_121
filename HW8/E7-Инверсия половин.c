/*
E7-Инверсия половин

Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом.

Input format
10 целых элементов массива через пробел.

Output format
10 целых элементов массива через пробел.


Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
-4 10 3 -5 4 0 1 -10 8 -6
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
	// 1. Инверсия первой половины (индексы от 0 до 4)
	int left = 0;
	int right = SIZE / 2 - 1; // 4
	
	while(left < right){
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;  // сдвигаем левый индекс вправо
		right--; // сдвигаем правый индекс влево
	}
	
	// 2. Инверсия второй половины (индексы от 5 до 9)
	left = SIZE / 2;  // 5
	right = SIZE - 1; // 9
	
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
