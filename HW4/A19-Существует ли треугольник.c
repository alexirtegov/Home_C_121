/*
A19-Существует ли треугольник

Существует ли треугольник
Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

Input format
Три целых числа. Стороны треугольника a, b, c.
Output format
YES или NO

 */


#include <stdio.h>

int main(int argc, char **argv)
{

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	
	((A+B>C && A+C>B && B+C>A) && (A>0 && B>0 && C>0)) ? printf("YES") : printf("NO");
	
	

	
	return 0;
}

