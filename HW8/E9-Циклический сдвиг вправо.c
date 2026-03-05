/*
 E9-Циклический сдвиг вправо
 
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

Input format
10 целых чисел через пробел

Output format
10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически


Input
4   -5   3  10  -4  -6  8  -10  1  0
Output
0   4   -5   3  10  -4  -6  8  -10  1
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
	int temp = arr[SIZE-1];
	
// Сдвигаем элементы вправо, начиная с конца (чтобы не затереть их)
	for(int i = SIZE - 1; i > 0; i--){
		arr[i] = arr[i - 1];
	}
	
	arr[0] = temp;

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
