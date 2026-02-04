/*
A17-Время года

Какое время года
Ввести номер месяца и вывести название времени года.

Input format
Целое число от 1 до 12 - номер месяца.
Output format
Время года на английском: winter, spring, summer, autumn

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int month;

	
	scanf("%d", &month);
	
	(month>2 && month<6) ? printf("spring") :  
	(month>5 && month<9) ? printf("summer") :  
	(month>8 && month<12) ? printf("autumn") :  
	printf("winter");
	
	return 0;
}

