/*
G2-Строка и цифры

Строка и цифры
Считать число N из файла input.txt. 
Сформировать строку из N символов. N четное число, не превосходящее 26. 
На четных позициях должны находится четные цифры в порядке возрастания, 
кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. 
Результат записать в файл output.txt

Input format
Четное N ≤ 26

Output format
Строка из английских букв и цифр


Input in input.txt
10

Output in output.txt
A2B4C6D8E2


Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*file;
	
	//откроем файл input.txt для чтения
	file = fopen("input.txt", "r");
	if(file == NULL){
		perror("input.txt");
		return 1;
	}
	//через fscanf считываем число из файла и записываем в N,затем закрываем файл
	int N=0;
	if(fscanf(file, "%d", &N)!=1){
		printf("Error");
		fclose(file);
		return 1;
	}
	fclose(file);
	
	//проверяем на условие N чётное (N % 2 == 0) и N ≤ 26.
	if(N%2!=0 || N>26){
		printf("Error");
		return 1;
	}
	
	// создаем массив букв и цифр
	char letters[26];			 //можно так char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i=0; i<26; i++){
		letters[i] = 'A'+i;
	} 

	
	char digits[4] = {'2', '4', '6', '8'};

	//создаем массив буфер (последний под '\0').
	char result_string [N+1];
	
	// индексы для перебора букв и цифр
	int letters_index = 0;
	int digits_index = 0;

	//построение строки по позициям 1…N
	for(int pos = 0; pos<N; pos++){
		// Если позиция чётная (pos = 0, 2, 4 …), 
		//это «нечётное» место в понимании задачи
		if((pos%2) ==0){
			// Берём следующую букву и увеличиваем 
			//letter_index, при выходе за границу — обнуляем
			result_string[pos] = letters[letters_index];
			letters_index++;
			if (letters_index>=sizeof(letters)){ //Когда letters_index доходит до конца алфавита 
				//(26 букв), мы возвращаем его к нулю, чтобы снова начать с «A».
				letters_index = 0;
			}
		} else {
			  // На «чётных» местах (pos = 1, 3, 5 …) ставим цифру
			  result_string[pos] = digits[digits_index];
			  digits_index++;
			  if(digits_index>= sizeof(digits)){ //digits_index дойдет до 4 обнуляем
				  digits_index = 0;
			  }
		}
		
	}
	result_string[N] = '\0';
	
	//открываем выходной файл output.txt
	FILE*file2;
	file2 = fopen("output.txt", "w"); //открываем в формате записи
		if(file2 == NULL){
		perror("output.txt");
		return 1;
	}
	
	//пишем в выходной файл буфер  result_string[N]
	fprintf(file2, "%s", result_string);
	fclose(file2);
	

	return 0;
}
