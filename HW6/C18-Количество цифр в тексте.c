/*
C18-Количество цифр в тексте


Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте. int is_digit(char c)

Input format
Текст из английских букв и знаков препинания. В конце текста символ точка.

Output format
Одно целое число - количество цифр в тексте.


Input
1Hello 36world.
Output
3
 */


#include <stdio.h>

int is_digit(char c)
{
	if (c>='0' && c<='9'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char **argv)
{
	int count = 0;
	int ch;
	
	while ((ch=getchar())!='.' && ch!=EOF){ //пока вызов не точка
		
		if (is_digit (ch) ==1){ //если вызов return 1 попадаем в счетчик
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
