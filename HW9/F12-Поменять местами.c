/*
F12-Поменять местами

cоставить функцию которая меняет в массиве минимальный и максимальный элемент местами.
Прототип функции void change_max_min(int size, int a[])

Input format
Функция принимает на вход размер массива и массив чисел типа int

Output format
Функция не возвращает значения, измененный массив сохраняется на месте исходного.


Input
1 2 3 4 5 6 7 8 9 10
Output
10 2 3 4 5 6 7 8 9 1
 */


#include <stdio.h>
#define SIZE 10


void input(int array[])
{
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &array[i]);
    }
}

void change_max_min(int size, int a[])
{
    int min_index = 0;
    int max_index = 0;
    

    for(int i = 1; i < size; i++){
        if(a[i] < a[min_index]){
            min_index = i; // Сохраняем реальную позицию
        }
        if(a[i] > a[max_index]){
            max_index = i; // Сохраняем реальную позицию
        }
    }
    
    // Меняем местами минимум и максимум
    int temp = a[min_index];
    a[min_index] = a[max_index];
    a[max_index] = temp;
}

int main(int argc, char **argv)
{
    int array[SIZE];
    
    // Ввод
    input(array);
    
    // Обработка
    change_max_min(SIZE, array);
    
 
    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
