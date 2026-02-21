/*
D8-Числа от A до B

От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.

Input format
Два целых числа через пробел.

Output format
Последовательность целых чисел.


Input
5 2
Output
5 4 3 2
 */


#include <stdio.h>

void numbers_from_A_to_B(int A, int B)
{
	    
    if (A == B) {	// Базовый случай: A == B
        printf("%d", A);
        return;
    }
    
    
	printf("%d ", A);
    if(A<B){
		numbers_from_A_to_B(A+1, B);
	} else {
		numbers_from_A_to_B(A-1, B);
	}
}

int main(int argc, char **argv)
{
	
	int A, B;
	scanf("%d %d", &A, &B);
	
	numbers_from_A_to_B(A, B);
	
	return 0;
}

