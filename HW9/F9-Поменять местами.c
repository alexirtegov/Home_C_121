/*
F9-Поменять местами

Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. 
Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])

Input format
Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.


Input
1 -2 -3 -4 5 6 7 8 9 10
Output
1 10 -3 -4 5 6 7 8 9 -2

 */


#include <stdio.h>
#define SIZE 10


void input(int array[])
{
	for(int i =0; i<SIZE; i++){
		if(scanf("%d", &array[i]) !=1){
			printf("Error input");
			return;
		}
	}
}

void swap_negmax_last(int size, int a[])
{
	//сначала нам нужно найти первое отрицательное число в массиве, чтобы дальше его сравнивать
	int flag =1; //переключатель если все числа вдруг будут положительные
	int max_neg=1;
	for(int i =0; i<size; i++){
		if(a[i]<0){
			flag =0;
			max_neg = a[i];
			break;
		}
	}
	
	if(flag == 1){ //раз все числа положительные выводим ряд как есть, ничего не меняя
		return;
	}
	
	for(int i =0; i<size; i++){
		if(a[i]<0 && max_neg<a[i]){
			max_neg = a[i];
		}
	}
	
	//производим замену максимального отрицательного числа и последнего числа в массиве
	for(int i=0; i<size; i++){
		if(a[i] == max_neg){
		int temp = a[i];
		a[i]=a[size-1];
		a[size-1]=temp;
		}
	}

}


void output(int array[])
{
	for(int i =0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
}

int main(int argc, char **argv)
{
	int array[SIZE];
	input(array);
	
	swap_negmax_last(SIZE, array);
	
	output(array);
	return 0;
}

