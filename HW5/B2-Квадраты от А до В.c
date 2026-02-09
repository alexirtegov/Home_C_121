/*
B2-Квадраты от А до В

Квадраты чисел
Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

Input format
Два целых числа по модулю не больше 100

Output format
Квадраты чисел от a до b.

Input
1 5
Output
1 4 9 16 25
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
    
    for(; a<=b; a++){
		printf("%d ", a*a);
	}
    
	return 0;
}

