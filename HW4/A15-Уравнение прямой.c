/*
A15-Уравнение прямой


Уравнение прямой
Определить уравнение прямой по координатам двух точек. Уравнение вида

y=k*x+b
Input format
Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2

Output format
Два числа K,B в формате "%.2f %.2f"

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int X1, Y1, X2, Y2;
	float K, B;
	
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	
	// y=k*x+b
	// b = Y1 - k*X1
	// b = Y2 - k*X2
	// Y1 - k*X1 = Y2 - k*X2  -> Y1-Y2 = k*X1-k*X2
	// k = (Y1-Y2)/(X1-X2)
	// b = Y1 - X1*(Y1-Y2)/(X1-X2)
	
	K = (float)(Y1-Y2)/(X1-X2);
	B = Y1 - (float)X1*(Y1-Y2)/(X1-X2);
	
	printf("y=%.2f*x+%.2f\n", K, B);
		
	return 0;
}

