/*
F7-Упаковать массив 0 1


Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу: 
например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] 
(т.к. начинается с нуля, то сразу записывается количество элементов первой серии); 
а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).


Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)

Input format
Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].

Output format
Функция возвращает число элементов сжатого массива b[]


Input
1 1 0 0 1 1 1 0 1 1 0 0 1 0 1 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 0 0 1 1 1 0 1 1 0 1 0 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0
Output
[0,2,2,3,1,2,2,1,1,1,2,1,4,4,1,1,4,3,1,2,1,1,3,2,2,1,3,1,2,3,1,1,6,1,1,1,2,2,1,1,4,1,2,2,1,1,3,1,1,6,1,1,2]

 */


#include <stdio.h>
#define SIZE 100



void input(int array_number[])
{
	for(int i = 0; i<SIZE; i++){
		scanf("%d", &array_number[i]);
	}
}

int compression(int a[], int b[], int N)
{
	int count_array_compression = 0;
	
	if(a[0] == 1){
		b[count_array_compression] = 0;
		count_array_compression++;
	}
	
	for(int i=0; i<N;){
		int run_len =1;
		while (i+run_len<N && a[i + run_len] == a[i]){
			run_len++;
		}
		
		b[count_array_compression] = run_len;
		count_array_compression++;
		i=i+run_len;
	}
	
	return count_array_compression;
	
}

//~ int compression(int a[], int b[], int N)
//~ {
    //~ if (N <= 0) return 0; 
    
    //~ int count = 0;
    
    //~ // Если массив начинается с единицы, первым делом пишем 0 нулей
    //~ if (a[0] == 1) {
        //~ b[count] = 0;
        //~ count++;
    //~ }
    
    //~ int seq_len = 1;
    
    //~ // Проходим по массиву один раз, начиная со второго элемента
    //~ for (int i = 1; i < N; i++) {
        //~ if (a[i] == a[i - 1]) {
            //~ seq_len++;
        //~ } else {
            //~ b[count] = seq_len;
            //~ count++;
            //~ seq_len = 1; // Сброс счетчика для новой серии
        //~ }
    //~ }
    
    //~ // Обязательно записываем длину самой последней серии
    //~ b[count] = seq_len;
    //~ count++;
    
    //~ return count;
//~ }


void output(int array_number[], int count)
{
	printf("[");
	for(int i = 0; i<count; i++){
		printf("%d,", array_number[i]);
	}
	printf("]");
}

int main(int argc, char **argv)
{
	int array_number [SIZE];
	input(array_number);
	
	int array_compression [SIZE];
	
	int count = compression(array_number, array_compression, SIZE);
	
	output(array_compression, count);
	
	return 0;
}

