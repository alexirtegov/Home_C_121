/*
D2-Сумма от 1 до N


Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

Input format
Одно натуральное число

Output format4
Сумма чисел от 1 до введенного числа

Input
5
Output
15

sum_numbers(5)
= 5 + sum_numbers(4)
= 5 + (4 + sum_numbers(3))
= 5 + (4 + (3 + sum_numbers(2)))
= 5 + (4 + (3 + (2 + sum_numbers(1))))
= 5 + (4 + (3 + (2 + (1 + sum_numbers(0)))))
= 5 + (4 + (3 + (2 + (1 + 0))))  ← базовый случай: sum_numbers(0) = 0
= 5 + (4 + (3 + (2 + 1)))
= 5 + (4 + (3 + 3))
= 5 + (4 + 6)
= 5 + 10
= 15
 */


#include <stdio.h>

int sum_numbers(int number)
{
    if (number <= 0)      // ← БАЗОВЫЙ СЛУЧАЙ: остановка рекурсии
        return 0;
    return number + sum_numbers(number - 1);  // РЕКУРСИВНЫЙ ВЫЗОВ
}


int main(int argc, char **argv)
{
	
	int number;
	if (scanf("%d", &number)!=1 || number <0){
		printf("ERROR");
		return 1;
	}
	
	
	printf("%d", sum_numbers(number));
	
	return 0;
}

