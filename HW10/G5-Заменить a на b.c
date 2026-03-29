/*
G5-Заменить a на b

Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. 
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

Input format
Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Output format
Строка из маленьких и больших английских букв, знаков препинания и пробелов.



Input in input.txt
aabbccddABCD

Output in output.txt
bbaaccddBACD

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//открываем файл input.txt
	FILE *in = fopen("input.txt","r");
	if(in == NULL){
		perror("input.txt");
		return 1;
	}
	
	// буфер для чтения строки (до 1000 символов + '\0')
	char buffer[1001];
	
	// считываем всю строку, включая пробелы
	if(fgets(buffer, sizeof(buffer), in) == NULL){
		printf("Something wrong");
		fclose(in);
		return 2;
	}
	
	// вычисляем длину строки до '\0' или до '\n'
	int len = 0;
	while(buffer[len] != '\n' && buffer[len] != '\0') len++;
	buffer[len] = '\0'; // отрезаем возможный '\n'
	
	//создаем массив для новой строки, куда будем добавлять перевернутые символы
	char result[1001];
	
	//проходим по char buffer[1001]
	int i =0;
	while(buffer[i] != '\0'){
		if(buffer[i] == 'a'){
			result[i] = 'b';
		} else if (buffer[i] == 'b'){
			result[i] = 'a';
		} else if (buffer[i] == 'A'){
			result[i] = 'B';
		} else if (buffer[i] == 'B'){
			result[i] = 'A';
		} else {
			result[i] = buffer[i];
		}
		i++;
	}
	result[i] = '\0';
	
	//записываем результат в output.txt
	FILE *out = fopen("output.txt", "w");
	if(out == NULL){
		perror("output.txt");
		return 2;
	}
	fprintf(out, "%s", result);
	fclose(out);
	
	return 0;
}

