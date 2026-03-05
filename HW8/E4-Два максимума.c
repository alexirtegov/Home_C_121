/*
E4-Два максимума

Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.

Input format
10 целых чисел через пробел.

Output format
Сумма двух максимальных элементов.


Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
18
 */


#include <stdio.h>

#define SIZE 10

void find_two_maxes (int arr[], int *max1, int *max2)
{
	//сначала инициализируем наши максимумы первыми членами массива. Через указатели мы это делаем сразу в main
	if(arr[0]>arr[1]){
		*max1 = arr[0];
		*max2 = arr[1];
	} else {
		*max1 = arr[1];
		*max2 = arr[0];
	}
	
	//теперь будем сравнивать остальные члены с выбранными максимумами
	for(int i = 2; i < SIZE; i++) {
		if (arr[i]> *max1){ //max1 мы выбрали как самый большой, если член ряда больше него, тогда мы max2 присваеваем значение max1 а max1 присваеваем новое значение из ряда.
			*max2 = *max1;
			*max1 = arr[i];
		} 
		else if (arr[i]> *max2)  { // если новое значение из ряда меньше max1 но больше max2
			*max2 = arr[i];
		}
	}
}

int main(int argc, char **argv)
{
	int array [SIZE];
	
	for(int i=0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
	
	// Создаем обычные переменные в main для хранения результата
    int maximum1, maximum2;
	
	// Передаем массив и АДРЕСА (&) этих переменных в функцию
    find_two_maxes(array, &maximum1, &maximum2);
    
    
    // После выполнения функции в maximum1 и maximum2 будут лежать нужные числа
    printf("%d\n", maximum1 + maximum2);
    
	return 0;
}

