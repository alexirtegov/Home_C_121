/*
C4-Функция по фомрмуле

Функция по формуле
Описать функцию вычисления f(x) по формуле:
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.

Input format
Последовательность не нулевых целых чисел, в конце последовательности число 0.

Output format
Одно целое число

Input
8 3 -3 10 0
Output
145
 */


#include <stdio.h>

int f(int x){
	if(x<-2){
		return 4;
	}
	else if (x>=2){
		return x*x+4*x+5;
	}
	else{
		return x*x;
	}
}


int main(int argc, char **argv)
{
	
	int x;
	
	if(scanf("%d", &x)!=1 || x==0){ //если при первичнов в воде ошибка или ноль, сразу выход
		printf("Error");
		return 0;
	}
	
	//инициализируем вызов функции int f(x) через переменную int maxValue;
	
	int maxValue = f(x);
	
	//будем читать числа без конца пока не встретим ноль
	
	while(x!=0){
		
		if(scanf("%d", &x)!=1){
			printf("Error");
			return 0;
		}
		int currentValue = f(x);
	
		if(currentValue>maxValue){
			maxValue=currentValue;
		}
	
}
	//выводим maxValue
	printf("%d", maxValue);
	
	return 0;
}
