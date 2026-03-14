/*
F10-Упаковать строку

Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>

Input format
Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'

Output format
Результат состоящий из букв и чисел, без пробелов


Input
aaaaabbbc.

Output
a5b3c1
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	char array[1001];
	int ch;
	int i=0;
	while( (ch=getchar()) !='\n' && ch !='.' && ch != EOF && i<1000){
		array[i] = (char)ch;
		i++;
	}
	array[i] = '\0';
	
		//~ if(scanf("%1000[^.].", array)!=1){    // %1000[^.]  — считать до 1000 любых символов, кроме точки, . — затем «съесть» саму точку (literal ‘.’),
		//~ return 0;
	//~ }
		
	char current_char = array[0];
	int count=1;
	
	//перебираем строку
	for (int i =1; array[i]!= '\0'; i++){
		if(array [i] == current_char){ //СРАВНИВАЕМ НЕ СИМВОЛЫ А ЗНАЧЕНИЯ ТАБЛИЦЫ ASCII
			count++;
		} else{
		printf("%c%d", current_char, count);
		current_char=array[i];
		count=1;
		}
	}
	printf("%c%d", current_char, count);
	
	return 0;
}

