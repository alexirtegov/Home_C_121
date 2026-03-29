/*
G20-Можно ли составить палиндром

Считать предложение из файла input.txt и определить 
можно ли из английских букв предложения записанного 
в файле получить одно слово - палиндром. 
Ответ напечатать на стандартный поток вывода. 
Требуется реализовать логическую функцию и применить ее.
is_palindrom(string)


Формат входных данных:
Строка из маленьких английских букв. Не более 1000 символов.

Input in input.txt
kak za

Формат результата:
YES или NO

Output
YES

Решение (нормальная сложность):
Для составления палиндрома из букв слова:

Если длина строки чётная: 
у каждой буквы должно быть чётное число вхождений.

Если длина нечётная: 
только у одной буквы может быть нечётное число, 
все остальные буквы должны быть в чётном количестве.

 */


#include <stdio.h>

int is_palindrom (int count_letters[])
{
	int Odd_flag = 0;
	for(int i = 0; i<26; i++){
		if(count_letters[i]%2!=0){ // если нечетное
			Odd_flag++;
		}
		if(Odd_flag>1){
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");

	if(in==NULL){
		perror("input.txt");

		return 1;
	}
	

	
	//читаем строку из файла
	char buffer [1001];
	char*b = buffer;
	if(fgets(b, sizeof(buffer), in)==NULL){
	printf("can't read file\n");
	fclose(in);

	return 1;
	}
	
	//считаем количество букв в buffer[1001]
	
	//создаем массив на 26 ячеек, куда запишем все буквы от 'a' до 'z'
	int count_letters[26] ={0};
	for(int i =0; buffer[i] != '\0'; i++){
		if(buffer[i]>='a' && buffer[i]<='z'){
			count_letters[buffer[i] - 'a'] ++;
		}
	}
	
	//проверяем условие полиндрома. Если count_letters[i] нечетных больше чем 1
	printf("%s", is_palindrom(count_letters) == 1 ? "YES" : "NO");
	
	fclose(in);

	
	return 0;
}
