/*
A10-Наименьшее из пяти чисел

Наименьшее из пяти чисел
Ввести пять чисел и найти  наименьшее из них.

Input format
Пять целых чисел
Output format
Одно целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C, D, E;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	
	
	if(A<B && A<C && A<D && A<E) {
		printf("%d", A);
	}
	else if (B<C && B<D && B<E && B<A) {
		printf("%d", B);
	}
	else if (C<D && C<E && C<A && C<B){
		printf("%d", C);
	}
	else if	(D<E && D<A && D<B && D<C) {
		printf("%d", D);
	}else{
		printf("%d", E);
	}
	
	

	
	return 0;
}

