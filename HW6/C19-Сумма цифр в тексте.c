/*
C19-Сумма цифр в тексте


Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)

Input format
Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка.

Output format
Целое число - сумма цифр в тексте


Input
1Hello 36world.
Output
10
 */


#include <stdio.h>

int digit_to_num(void)
{
	int sum = 0;
	int ch;
	
	while ((ch=getchar())!='.' && ch!=EOF){ 
	
		if (ch>='0' && ch<='9'){
			sum+=(ch-'0');
		
		}
	}
	
return sum;
}

int main(int argc, char **argv)
{
	
	printf("%d\n", digit_to_num());
	
	return 0;
}
