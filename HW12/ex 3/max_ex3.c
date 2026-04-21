


#include <stdio.h>
#include "max_ex3.h"  //подключаем объявление

int max(int a, int b)
{
	printf("m = %d\n", m); //Работает через extern из max_ex3.h
	return a>b ? a : b;
}
