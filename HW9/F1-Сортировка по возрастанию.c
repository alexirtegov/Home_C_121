/*
F1-Сортировка по возрастанию

Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.

Input format
Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.

Output format
Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.

Input
20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
Output

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 */


#include <stdio.h>

#define SIZE 20

void Input(int *array)
{
	for(int i =0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}

void sort_array(int size, int a[])
{
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(a[i]>a[j]){
				int temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}


void Output(int *array)
{
	for(int i =0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
}


int main(int argc, char **argv)
{
	int array[SIZE] ={0};
	
	Input(array);
	
	sort_array(SIZE, array);
	
	Output(array);
	
	return 0;
}

