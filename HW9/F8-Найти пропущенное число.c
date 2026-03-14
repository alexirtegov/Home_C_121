/*
F8-Найти пропущенное число

В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, 
но одно из чисел пропущено (остальные встречаются ровно по одному разу). 
N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.

Input format
Последовательность целых чисел от M до N. M, N не превосходит 1000.

Output format
Одно целое число


Input
2   3   1   4   7   6   9   8  10   0
Output
5

Решение:
Считываем последовательность целых чисел до первого нуля и сохраняем их
В процессе чтения поддерживаем три величины:
– минимум m читанных чисел;
– максимум n читанных чисел;
– сумму s всех прочитанных чисел.
После окончания ввода по m и n определяем полный диапазон чисел от m до n включительно
Вычисляем математическую сумму всех чисел этого диапазона по формуле 
суммы арифметической прогрессии
Sожид = Sожид = (max+min)(max−min+1)/2
Разница между этой «ожидаемой» суммой и фактической суммой s даст именно то число, 
которого не было в исходной последовательности
 */

#include <stdio.h>
#define SIZE 1000

int Input_array(int array[], int N)
{
	int number_of_digit =0;
	for(int i =0; i<N; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return 0;
		}
		if(array[i]==0){ //встречаем ноль - идем на выход
			break;
		}
		number_of_digit ++; //считаем количество заполненных ячеек памяти в массиве
	}
	return number_of_digit;
}

int What_minimum(int array[], int number_of_digit)
{
	int min=array[0];
	for(int i =0; i<number_of_digit; i++){
		if(min>array[i]){
			min=array[i];
		}
	}
	return min;
}


int What_maximum(int array[], int number_of_digit)
{
	int max=array[0];
	for(int i =0; i<number_of_digit; i++){
		if(max<array[i]){
			max=array[i];
		}
	}
	return max;
}


int What_sum(int array[], int number_of_digit)
{
	int sum = 0;
	for(int i =0; i<number_of_digit; i++){
		sum+=array[i];
	}
	return sum;
}


int What_arithmetic_sum_of_range(int max, int min) //расчет по формуле Sожид = (max+min)(max−min+1)/2
{
	int arth_sum_r = (max+min)*(max-min+1)/2; //для нашего примера 2   3   1   4   7   6   9   8  10  (10+1)*(10-1+1)/2=55
	return arth_sum_r; //в примере должны вернуть 55
}

int What_the_point(int arth_sum_r, int sum)
{
	int point = arth_sum_r-sum;
	return point;
}
int main(int argc, char **argv)
{
	//формируем массив с выходом по вводу нуля
	int array[SIZE];
	int number_of_digit = Input_array(array, SIZE);
	printf("number_of_digit = %d\n", number_of_digit); //проверка 
	
	//находим минимум в массиве
	int min = What_minimum(array, number_of_digit); 
		printf("min = %d\n", min); //проверка 
	int max = What_maximum(array, number_of_digit); 
		printf("max = %d\n", max); //проверка 
		
	//находим сумму sum всех прочитанных чисел
	int sum = What_sum(array, number_of_digit);
		printf("sum = %d\n", sum); //проверка
		
	//находим сумму диапазона от минимума до максимума
	//расчет по формуле Sожид = (max+min)(max−min+1)/2
	int arth_sum_r = What_arithmetic_sum_of_range(max, min);
		printf("arithmetic sum of range = %d\n", arth_sum_r); //проверка
		
	//теперь разница между суммой диапазона и суммой прочитанных чисел массива даст ответ
	int point = What_the_point(arth_sum_r, sum);
		printf("%d\n", point); //ОТВЕТ
		
						
	return 0;
}

