/*
D19-Сколько раз встречается символ a
С

Дана строка из английских символов, пробелов и знаков препинания. 
В конце строки символ точка. Необходимо реализовать рекурсивную функцию, 
которая считывает данную строку со стандартного потока ввода и возвращает целое число - количество символов 'a' в данной строке.
int acounter(void)
Используя данную функцию решить задачу.

Input format
Строка состоящая из английских букв, пробелов и знаков препинания. В коне строки символ '.'

Output format
Одно целое число.


Input
abcd a.
Output
2
 */


#include <stdio.h>
int acounter(void)
{
	int c = getchar();
	int count =0;
	
	if(c=='.'){
		return count;
	}
	if (c=='a'){
	count++;
	}
	return count +  acounter(); // эту сумму как результат я возвращаю именно в вызов int acounter(void)
}


int main(void) {
    int result = acounter();
    printf("%d\n", result);
    return 0;
}

// вариант 1 через цикл

//~ #include <stdio.h>

//~ int acounter(void) {
    //~ int c;
    //~ int count = 0;
    
    //~ while ((c = getchar()) != '.') {
        //~ if (c == 'a') {
            //~ count++;
        //~ }
    //~ }
    //~ return count;
//~ }

//~ int main(void) {
    //~ int result = acounter();
    //~ printf("%d\n", result);
    //~ return 0;
//~ }
