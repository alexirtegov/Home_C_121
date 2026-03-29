/*
G6-Проверка на палиндром

В файле input.txt символьная строка не более 1000 символов. 
Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

Input format
Строка из заглавных английских букв

Output format
YES или NO

Input in input.txt
ABCDEF
Output in output.txt
NO

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int is_palindrom(char buffer[], int length){
	for(int i =0, j = length - 1; i<j;){
		if(buffer[i] == buffer[j]){
			i++;
			j--;
		} else {
			return 0;
		}

	}
	return 1;
}

int main(int argc, char **argv)
{
	//открываем срзу оба файла
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	if(in == NULL ){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);
		}
		return 1;
	}
	if (out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//считаем строку из input.txt через fgets и кладем ее в массив buffer
	char buffer[1001];
	fgets(buffer, 1001, in);
	
	//обрежем перевод строки '\n' и заменем его на '\0'
	int length =0;
	while(buffer[length] != '\n' && buffer[length] != '\0') length++;
	buffer[length] = '\0';

	//запишем в файл output.txt результат через обработку в функции
	fprintf (out, "%s", is_palindrom(&buffer[0], length) ==1 ? "YES" : "NO");
	fclose(in);
	fclose(out);
		
	return 0;
}

