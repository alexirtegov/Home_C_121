/*
G11-Заканчивается на a

В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. 
Ответ записать в файл output.txt.

Input format
Строка из английских букв и пробелов не более 1000 символов.

Output format
Одно целое число



Input in input.txt
Mama mila ramu

Output in output.txt
2

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
	if(in == NULL){ //если отсутствие данных
		perror("input.txt");
		if(out != NULL){
			fclose(out);
		}
		return 1;
	}
	
	if(out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//читаем input.txt с помощью fgets в buffer[1001]
	char buffer[1001];
	
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
		fclose(in);
		fclose(out);
		return 1;
	}
	
	
	int a = 0; // счетчик слов, заканчивающихся на 'a'
	
	for(int i = 0; buffer[i] != '\0'; i++){
		// Проверяем, является ли текущий символ буквой 'a' (или 'A', на всякий случай)
		if(buffer[i] == 'a' || buffer[i] == 'A'){
			// Смотрим на следующий символ. 
			// Если там пробел, enter или конец строки — значит, это конец слова.
			char next_char = buffer[i+1];
			if(next_char == ' ' || next_char == '\n' || next_char == '\0'){
				a++;
			}
		}
	}
	
	fprintf(out, "%d", a);
	
		fclose(in);
		fclose(out);
	
	
	return 0;
}
