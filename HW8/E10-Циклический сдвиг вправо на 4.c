/*
E10-Циклический сдвиг вправо на 4

Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

Input format
12 целых чисел через пробел

Output format
12 целых чисел через пробел


Input
4  -5   3  10  -4  -6   8 -10   1   0   5   7
Output
1   0   5   7   4  -5   3  10  -4  -6   8 -10

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
    int k = 4; // Величина сдвига
    int temp[4]; // Массив для сохранения хвоста

    // 1. Сохраняем последние k элементов в temp
    for(int i = 0; i < k; i++) {
        temp[i] = arr[SIZE - k + i];
    }
    
    // 2. Сдвигаем элементы (безопасно, чтобы индекс не стал < 0)
    for(int i = SIZE - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
    // 3. Копируем сохраненные элементы в начало
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
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
