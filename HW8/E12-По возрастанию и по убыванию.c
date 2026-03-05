/*
E12-По возрастанию и по убыванию

По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

Input format
10 целых чисел через пробел

Output format
Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.


Input
14  25  13  30  76  58  32  11  41  97
Output
13  14  25  30  76  97  58  41  32  11
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
int half = SIZE / 2;
    
    // 1. Сортировка первой половины по возрастанию (индексы от 0 до 4)
    for(int i = 0; i < half; i++){
        int min_idx = i; // Предполагаем, что минимальный элемент на текущей позиции i
        for(int j = i + 1; j < half; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j; // Запоминаем индекс найденного минимума
            }
        }
        // Если минимальный элемент оказался не на позиции i, меняем их местами (один обмен за проход)
        if(min_idx != i){
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    // 2. Сортировка второй половины по убыванию (индексы от 5 до 9)
    for(int i = half; i < SIZE; i++){
        int max_idx = i; // Предполагаем, что максимальный элемент на текущей позиции i
        for(int j = i + 1; j < SIZE; j++){
            if(arr[j] > arr[max_idx]){
                max_idx = j; // Запоминаем индекс найденного максимума
            }
        }
        // Если максимальный элемент оказался не на позиции i, меняем их местами
        if(max_idx != i){
            int temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
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
