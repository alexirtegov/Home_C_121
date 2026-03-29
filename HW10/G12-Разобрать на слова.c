/*
G12-Разобрать на слова

В файле input.txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл output.txt.

Input format
Одна строка из английских букв и пробелов не более 1000 символов.

Output format
Каждое слово на отдельной строке



Input in input.txt
Mama mila ramu

Output in output.txt
Mama
mila
ramu

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	
	if(in == NULL){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);
		}
		return 1;
	}
	
	if(out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	
	//читаем input.txt через fgets в buffer[1001]
	char buffer [1001];
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
		fclose(in);
		fclose(out);
		return 1;
	}
	
	//теперь наша строка в buffer[1001]
	char current [1001]; // сюда будем записывать слова
	int cur = 0;
	
	for(int i = 0; buffer[i]!='\0'; i++){
		if(buffer[i]!= ' ' && buffer[i] != '\n'){
			current[cur] = buffer[i];
			cur++;
		} else {
			if (cur>0){
				current[cur] = '\0';
				fprintf(out, "%s\n", current);
				cur = 0;
			}
		}
	}
	
	if (cur>0){
        current[cur] = '\0';
        fprintf(out, "%s\n", current);
    }
		fclose(in);
		fclose(out);
		
	
	return 0;
}
