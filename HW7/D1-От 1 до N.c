/*
D1-От 1 до N

Составить рекурсивную функцию, печать всех чисел от 1 до N

Input format
Одно натуральное число

Output format
Последовательность чисел от 1 до введенного числа


Input
5
Output
1 2 3 4 5
 */


#include <stdio.h>

void print_numbers(int n) {
 
    
    if (n > 1) {
        print_numbers(n - 1);
        printf(" ");
    }
    
    printf("%d", n);
}

int main(int argc, char **argv)
{
	
	int number;
	if (scanf("%d", &number)!=1 || number <1){
		printf("ERROR");
		return 1;
	}
	
	
	print_numbers(number);
	
	return 0;
}

