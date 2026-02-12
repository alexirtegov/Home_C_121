/*
C8-Строчную в заглавную


Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.

Input format
Строка состоящая из английских букв, пробелов и запятых. В конце строки символ точка.

Output format
Исходная строка в которой маленькие английские буквы заменены заглавными.


Input
hello World!.
Output
HELLO WORLD!
 */


#include <stdio.h>

void azAZ(void)
{
	char c;
	
	while((c=getchar())!='.'){
		if(c>='a' && c<='z'){
			putchar(c-0x20);
		} else {
			putchar(c);
		}
	}
}



int main(int argc, char **argv)
{
	azAZ();
	
	return 0;
}

