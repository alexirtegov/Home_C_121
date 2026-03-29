/*
G9-Удалить повторяющиеся символы


В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

Input format
Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.

Output format
Строка из меленьких и больших английских букв.


Input in input.txt
abc cde def

Output in output.txt
abcdef

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	//открываем файлы
	FILE *in =fopen("input.txt","r");
	FILE *out =fopen("output.txt","w");
	if(in==NULL){
		perror("input.txt");
		if(out != NULL) fclose(out);
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//читаем через fgets в массив buffer[1001]
	char buffer[1001];
	if (fgets(buffer, sizeof(buffer), in) == NULL){
		fclose(out);
		fclose(in);
		return 1;
	}
	int len =0;
	while(buffer[len] != '\n' && buffer[len] != '\0') len++;
	buffer[len] = '\0';
	
	//массив для результата
	char result [1001];
	int res_len = 0;
	
	//перебираем строку buffer[len]
	for(int i = 0; i<len; i++){
		if(buffer[i] == ' ') continue; // пропуск пробелов. сразу берем следующий i в цикле for
		
		//проверка на повторение символа
		int already = 0;
		for(int j=0; j<res_len; j++){
			if(result[j] == buffer[i]){
				already = 1;
				break;
			}
			
		}
		if(already ==0){
			result[res_len] = buffer[i];
			res_len++;
		}
	}	
	
			
	//завершаем строку
    result[res_len] = '\0';

    // записываем результат
    fputs(result, out);
    
    fclose(in);
    fclose(out);	
	
	return 0;
}
