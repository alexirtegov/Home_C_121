/*
B3-Сумма квадратов


Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.

Input format
Два целых числа по модулю не больше 100

Output format
Сумма квадратов от первого введенного числа до второго
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	if(scanf("%d %d", &a, &b) !=2){
		printf("Error");
		return 1;
	}
	
	if (a > b || (a>100 || b>100)) {
        printf("Error");
        return 1;
    }
    
    int sum_of_squares=0;
    for(; a<=b; a++){
		sum_of_squares += a*a;
	}
    
    printf("%d", sum_of_squares);
    
	return 0;
}
