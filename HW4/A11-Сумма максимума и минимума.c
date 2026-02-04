/*
A11-Сумма максимума и минимума


Сумма максимума и минимума
Напечатать сумму максимума и минимума.

Input format
Пять целых чисел через пробел
Output format
Одно целое число - сумма максимума и минимума

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B, C, D, E, min, max;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	
	
	if(A<B && A<C && A<D && A<E) {
		min=A;
	}
	else if (B<C && B<D && B<E && B<A) {
		min=B;
	}
	else if (C<D && C<E && C<A && C<B){
		min=C;
	}
	else if	(D<E && D<A && D<B && D<C) {
		min=D;
	}else{
		min=E;
	}
	
	(A>B && A>C && A>D && A>E)?(max=A):
	(B>C && B>D && B>E && B>A)?(max=B):
	(C>D && C>E && C>A && C>B)?(max=C):
	(D>E && D>A && D>B && D>C)?(max=D):
	(max=E);
	
	printf("%d", min+max);
	

	
	return 0;
}

