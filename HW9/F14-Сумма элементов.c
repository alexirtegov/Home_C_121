/*
F14-Сумма элементов


Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции int sum_between_ab(int from, int to, int size, int a[])

Input format
Функция принимает концы отрезка from и to, размер массива, массив целых чисел

Output format
Функция возвращает сумму элементов в интервале [from, to]


Input
4 6 1 2 3 4 5 6 7 8 9 10
Output
15
 */


#include <stdio.h>
#define SIZE 10

void Input(int array[])
{
	for(int i = 0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}




int sum_between_ab(int from, int to, int size, int a[])
{
	if(from>to){
	int temp = from;
	from = to;
	to = temp;
	}
	
	
	
	int count = 0;
	
	for(int i=0; i<size; i++){
		if(a[i]>=from && a[i]<=to){ //проверяем 4<=a[i]<=6
		count+=a[i];
		}
	}
	
	return count;
}


int main(int argc, char **argv)
{
	int array[SIZE];
	Input(&array[0]);
	
	//~ //Отрезок: [4, 6]
	int from = 4;
	int to = 6;
	
	int count = sum_between_ab(from, to, SIZE, array);
	
	printf("%d", count);
	
	return 0;
}
