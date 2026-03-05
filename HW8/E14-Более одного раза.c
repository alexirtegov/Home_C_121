/*
E14-Более одного раза


Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза. В результирующем массиве эти числа не должны повторяться.

Input format
10 целых чисел через пробел

Output format
Целые числа через пробел, которые встречаются более одного раза в исходном массиве.


Input
4 1 2 1 11 2 34 8 9 10
Output
1 2
 */


#include <stdio.h>
#define SIZE 10

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

int Replace(int array[], int arr[])
{
	int count = 0;
	
	for(int i=0; i<SIZE; i++){ 
		int already =0;
		for(int k =0; k<SIZE; k++){ //перебераем все члены нового массива чтобы исключить повторение и не взять не правильный i
			if(array[i] == arr[k]){//сравнивваем все члены массива arr[k] с одним членом array[i]
				already = 1;// если нанши совпадение значит already =1 и 
				break; //выходим из внутреннего цикла во внешний для для того чтобы взять следующий член i
			}
		}
		if(already!=1){
			
			for(int j=i+1; j<SIZE; j++){// в этот цикл мы попадаем по условию if(already!=1)
				
				if(array[i] == array[j]){ //например для 1 2 1 2 1 2 array[0]=array[2]
				arr[count] = array[i]; //запишем в arr[count] на место 0 значение 1 arr[0]=1
				count ++; //1
				break;
				}
			}
		
		}
	
	}
	return count;
}	

void output_array (int arr[], int count)
{
	for(int i=0; i<count; i++){
		printf("%d ", arr[i]);
	}
}

int main(int argc, char **argv)
{
	int array[SIZE];
	input_array(array); 
	
	int arr[SIZE]={0};
	
	int count = Replace(array, arr);
		
	output_array(arr, count); 
	
	return 0;
}

