/*
E16-Чаще всего

Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.

Input format
10 целых числе через пробел

Output format
Одно число, которое встречается чаще других.


Input
4  1  2  1  11  2  34  11  0  11
Output
11
 */


#include <stdio.h>
# define SIZE 10

void input_array(int array[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}

int mostly(int array[])
{
	int max =0;

	int number = 0;
	
	for(int i=0; i<SIZE; i++){
		int count =0; 
		for(int j=i+1; j<SIZE; j++){
			if(array[i]==array[j]){
				count++;
			}
		}
	if(max<count){
		max=count;
		number = array[i];
	}		
	}
	return number;
}

int main(int argc, char **argv)
{
	int array[SIZE];
	
	input_array(&array[0]);
	
	printf("%d", mostly(array));
	
	return 0;
}

