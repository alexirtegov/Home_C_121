/*
D11-Количество двоичных 1

Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

Input format
Натуральное число

Output format
Целое число - количество единиц в двоичной записи числа.


Input
5
Output
2

Input
255
Output
8
 */



#include <stdio.h>


int print_bin(unsigned int n) {
    
    
    
    if (n < 2) {
        return n;
    }
    
    print_bin(n / 2);	// Сначала печатаем старшие биты
    
    int one = print_bin(n / 2);
    if(n % 2 != 0) one++;
    
    return one;
}


int main(void) 
{
    unsigned int n;
    if (scanf("%u", &n) != 1) {
        printf("wrong input\n");
        return 0;
    }

    printf("%d", print_bin(n));
    
    
    
    return 0;
}
