/*
G19-Составить палиндром

Разработать функцию дана строка из маленьких английских букв. 
Составить из символов палиндром максимальной длинны. 
При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. 
Записать ответ в файл output.txt.

Input format
Строка из маленьких английских букв. Не более 1000 символов.

Output format
Строка из маленьких английских букв.


Input in input.txt
kazaki

Output in output.txt
akika

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
	
	char buffer[1001]; //записали строку из файла в буфер
	if(fgets(buffer, sizeof(buffer), in)==NULL){
		printf("Error read file");
		fclose(out);
		fclose(in);
		return 1;
	}
	
	//посчитаем буквы от 'a' до 'z' всего их 26 и запишем в массив number_of_letters
	int number_of_letters [26] = {0};

	for(int i = 0; buffer[i] != '\0'; i++){
		if(buffer[i]>='a' && buffer[i]<='z'){
			number_of_letters[buffer[i] - 'a']++;
		}
	}
	
	//составляем палиндром
	char first_half[1001]; //первая половина
	int first_len = 0;     //длина первой половины
	char middle_letter = 0; //символ для середины
	
	for(int i =0; i<26; i++){
		int count = number_of_letters[i];
		if(count>0){ //если есть хоть одна буква
			for(int j =0; j<count/2; j++){ //сюда попдаем только если count >2, иначе условие j<count/2 не выполняется
				first_half[first_len] = 'a' + i;
				first_len++;
			}
			if(count%2 !=0 && middle_letter == 0){ //запишем в середину одну первую не парную букву, остальные не попадают
				middle_letter = 'a' + i;
			}
		}
	}
	
	//оформляем строку
	first_half[first_len] = '\0';
	
	//итого первая половина
	char result[1001];
	int pos = 0;
	for (int i = 0; i<first_len; i++){
		result[pos] = first_half[i];
		pos++;
	}

	//итого серединка
	if(middle_letter)
	result[pos++] = middle_letter;
	
	//итого первая половина наоборот
	for (int i = first_len-1; i>=0; i--){
		result[pos] = first_half[i];
		pos++;
	}	
	
	result[pos] = '\0';
	
	fprintf(out, "%s", result);
	
		fclose(out);
		fclose(in);	
		
	return 0;
}
