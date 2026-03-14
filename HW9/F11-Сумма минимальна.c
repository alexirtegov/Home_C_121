/*
F11-Сумма минимальна


Дан целочисленный массив из 30 элементов. 
Элементы массива могут принимать произвольные целые значения помещающиеся в int. 
Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, 
сумма которых минимальна.

Input format
Последовательность из 30 целых чисел через пробел

Output format
Два целых числа через пробел


Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
Output
0 1
 */


#include <stdio.h>
#define SIZE 30

void input(int array[])
{
	for(int i = 0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}

void min_sum(int array[])
{
	int min_index_1 =0;
	int min_index_2 =1;
	int pair_sum_min = array[0]+array[1];
	
	for(int i=0; i<SIZE-1; i++){
		for(int j=i+1; j<SIZE; j++){
			int pair_sum = array[i]+array[j];
			if(pair_sum_min>pair_sum){
				pair_sum_min = pair_sum;
				min_index_1 = i;
				min_index_2 = j;
			}
		}
	}
	
	min_index_1<min_index_2 ? printf("%d %d", min_index_1, min_index_2) : printf("%d %d", min_index_2, min_index_1);
	
}

int main(int argc, char **argv)
{
	
	int array[SIZE];
	input(array);
	
	min_sum(array);
	
	return 0;
}

