/*
D6-Строка наоборот


Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
void reverse_string()

Input format
Строка из английских букв и знаков препинания. В конце строки символ точка.

Output format
Исходная строка задом наперед.


Input
Hello world!.
Output
!dlrow olleH
 */


#include <stdio.h>

void string_is_reversed(void)
{
	char ch = getchar(); //читаем символ в переменную ch
	
	if(ch == '.') return;
	
	string_is_reversed();
	
	printf("%c", ch);
	
}

int main(int argc, char **argv)
{
	
	string_is_reversed();
	
	return 0;
}

