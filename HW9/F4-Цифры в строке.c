/*
F4-Цифры в строке

Цифры в строке
Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. 
Цифра - количество. Функция должно строго соответствовать прототипу:
void print_digit(char s[])

Input format
Строка из английских букв, пробелов, знаков препинания и цифр

Output format
Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.


Input
Hello123 world77.
+
Output
1 1
2 1
3 1
7 2
 */


#include <stdio.h>

void print_digit(char s[])
{
	
	
	
	int counts[10]={0}; //счетчик цифр от 0 до 9
	по
	for(int i=0; s[i] !='\0'; i++){
		if(s[i]>='0' && s[i]<='9'){
			counts[s[i] -'0']++;
		}
	}
	
	for(int i=0; i<10; i++){
		if(counts[i]>0) printf("%d %d\n", i, counts[i]);
	}
}

int main(int argc, char **argv)
{
	
	char array[500];
	
	char *ptr;
	ptr = array;
	
	char ch;
	int i=0;
	
	while((ch=getchar()) != '\n' && ch !=EOF && i<499){
		array[i] = ch;
		i++;
	}
	
	array[i] = '\0';
	
	
	print_digit(array);

	
	return 0;
}

