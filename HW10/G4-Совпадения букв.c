/*
G4-Совпадения букв

В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

Input format
Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.

Output format
Маленькие английские буквы через пробел.


Input in input.txt
hello world

Output in output.txt
o

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//откроем файл для чтения заданной строки	
	FILE *in = fopen("input.txt", "r");
	if(in==NULL){
		printf("Error");
		perror("input.txt");
		return 1;
	}
	
	//создадим буферы для двух слов до 100 символов + '\0'
	char s1[101];
	char s2[101];
	
	//считаем два слова, разделенных по условию задачи пробелом
	if((fscanf(in, "%100s %100s", s1, s2))!=2){
		printf("Some thing wrong");
		fclose(in);
		return 1;		
	}
	
	//создаем массивы для счетчиков 'a' ... 'z' a - 96, z - 122
	int count_s1[26] = {0};
	int count_s2[26] = {0};	

	//считаем символы в первом слове	
	for(int i =0; s1[i]!='\0'; i++){
		int index = s1[i] - 'a';
		if(index>=0 && index<26){ //если 0<=index<26 - это 'a'<=index<'z'
			count_s1[index] ++; //посчитаем каждую букву столько раз, сколько она встретится в слове 
		}
	}
	
	//считаем символы во втором слове
	for (int i =0; s2[i]!='\0'; i++){
		int index = s2[i] - 'a';
		if(index>=0 && index<26){ //если 0<=index<26 - это 'a'<=index<'z'
			count_s2[index] ++; //посчитаем каждую букву столько раз, сколько она встретится в слове 
		}
	}
	
	//открываем второй файл для записи
	FILE*out;
	out = fopen("output.txt", "w");
	if(out == NULL){
		perror("output.txt");
		return 1;
	}	
	
			
	//выводим буквы, которые встречаются в обоих словах
	int first = 1;
	for(int i = 0; i<26; i++){
		if(count_s1[i]==1 && count_s2[i]==1){
			if(first == 0){
				fprintf(out, " ");
			}
			fprintf(out, "%c", 'a' + i);
			first = 0;
		}
	}
	fclose(out);
	
	return 0;
}
