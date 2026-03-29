/*
G10-Самое длинное слово

В файле input.txt дана строка слов, разделенных пробелами. 
Найти самое длинное слово и вывести его в файл output.txt. 
Случай, когда самых длинных слов может быть несколько, не обрабатывать.

Input format
Строка из английских букв и пробелов. Не более 1000 символов.

Output format
Одно слово из английских букв.


Input in input.txt
Hello beautiful world

Output in output.txt
beautiful

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
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
	
//читаем всю строку и записываем в массив buffer[1001];
	char buffer [1001];
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
        fclose(in);
        fclose(out);		
		return 1;
	}
	
// теперь строку будем разбивать на слова по прнципу до ' ' или '\n'
	char current[1001];
	int cur_len = 0;
	char longest [1001];
	int max_len = 0;
	
	for (int i = 0; buffer[i] != '\0'; i++){
		if(buffer[i] != ' ' && buffer[i] != '\n'){
			current[cur_len] = buffer[i];
			cur_len ++;
		} else {
			if(cur_len>0){
				current[cur_len] = '\0';
			}
			if(cur_len>max_len){
				max_len= cur_len;
				for(int j = 0; j<= max_len; j++){
					longest[j]=current[j];
				}
				
			}
			cur_len=0;
		}
	}

     if (cur_len > 0) {
        current[cur_len] = '\0';
        if (cur_len > max_len) {

            for (int j = 0; j <= cur_len; j++)
                longest[j] = current[j];
        }
    }
    
    
 
	fprintf(out, "%s", longest);
 
    fclose(in);
    fclose(out);	
	
	return 0;
}
