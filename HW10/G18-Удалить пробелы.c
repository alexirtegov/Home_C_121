/*
G18-Удалить пробелы

В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). 
Для решения задачи разработать функцию. Результат записать в output.txt.

Input format
Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.

Output format
Строка из английских букв, знаков препинания и пробелов.



Input in input.txt
    Hello     world!
    
Output in output.txt
Hello world!

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */

#include <stdio.h>

void remove_extra_spaces(char buffer[], char result[])
{
	int i = 0; //положение места чтения в buffer[]
	int j = 0; //положение места куда записываем строку без пробелов
	
	while (buffer[i] == ' '){ //здесь мы установим i  в положение не первого пробела
		i++;
	}
	
	int space_flag =0; 			//устанавливаем флаг пробела
	for(; buffer[i]!='\0' && buffer[i]!='\n';i++){
		if(buffer[i] != ' '){
			result [j++] = buffer[i];
			space_flag = 0;  	//положение флага 0 - то есть пробела нет
	} else {					//встретили пробел
		if(space_flag == 0){	// если пробела не было ставим
			result [j++] = ' ';
			space_flag = 1; // раз сюда попали значит пробел поставили
		}
	}

	}
	 // Завершить строку
    result[j] = '\0';	
}

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
	
	char buffer[1001]; //записали строку из файла в буфер
	if(fgets(buffer, sizeof(buffer), in)==NULL){
		printf("Error read file");
		fclose(out);
		fclose(in);
		return 1;
	}
	
	char result[1001];
	
	remove_extra_spaces(buffer, result);
	
	fprintf(out, "%s", result);
	fclose(out);
	fclose(in);
	
	return 0;
}
