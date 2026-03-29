/*
G17-Пары символов

В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. 
Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.

Input format
Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.

Output format
Строка из английских букв, пробелов и знаков препинания.



Input in input.txt
Hello world!

Output in output.txt
eHllw orodl!


Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	if(in==NULL){
		perror("input.txt");
		if(out!= NULL){
			fclose(out);
		}
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;	
	}
	
	//читаем строку из файла в массива
	char buffer [1001];
	if(fgets(buffer, sizeof(buffer), in) ==NULL ){
		fclose(in);	
		fclose(out);
		printf("error read file");
		return 1;
	}
	//убираем '\n' иначе в конце строки для Hello world! символ '!' и '\n' поменяются местами и ! уйдет на новую строчку
	int len= 0;
	while(buffer [len]!= '\n' && buffer [len]!= '\0'){
		len++;
	}
	buffer[len] = '\0';
	
	//теперь каждому символу присвоим свой индекс пропустив пробел
	int pos[1001];
	int count = 0;
	for(int i = 0; buffer[i]!='\0'; i++){
		if(buffer[i] == ' '){
			continue;
		} else {
			pos[count] = i; // для Hello world! pos[0] = 0, pos[1] = 1 ..  pos[4] = 4,  pos[5] = 6 ....пропустили пробел
			count ++;
		}
	}
	
	//меняем местами используя перемотку для пробельных символов через массив pos[]
	for(int i = 0; (i+1)<count; i+=2){ //огрнаничение (i+1)<count нужно для того чтобы в pos[i+1] не выйти за границу
		int temp = buffer[pos[i]];
		buffer[pos[i]] = buffer[pos[i+1]]; //для Hello world! пробел отработает так 
		buffer[pos[i+1]] = temp; //buffer[pos[4]] = buffer[pos[5]],  pos[4] - это 4 соответсвенно buffer[4] - это 'o' pos[5] - это 6, а buffer[6] это 'w'
	}
	
	fprintf(out, "%s", buffer);
	
	fclose(in);
	fclose(out);
	
	
	return 0;
}
