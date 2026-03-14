/*
F2-Четные в начало

Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. 
Строго согласно прототипу:.
void sort_even_odd(int n, int a[])

Input format
Функцийя принмате на вход целые числа

Output format
Отсортированный исходный массив


Input
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Output
20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
 */


#include <stdio.h>

#define SIZE 20

void Input(int *array)
{
	for(int i =0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}

void sort_even_odd(int n, int a[])
 {
       int temp_arr[n];
       int count = 0;

       // Собираем четные
       for(int i = 0; i < n; i++) {
           if(a[i] % 2 == 0) {
               temp_arr[count] = a[i];
               count++;
           }
       }

       // Собираем нечетные (продолжаем заполнять temp_arr с позиции count)
       for(int i = 0; i < n; i++) {
           if(a[i] % 2 != 0) {
               temp_arr[count] = a[i];
               count++;
           }
       }

       // Копируем обратно в a[]
       for(int i = 0; i < n; i++) {
           a[i] = temp_arr[i];
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
	
	sort_even_odd(SIZE, array);
	
	Output(array);
	
	return 0;
}
