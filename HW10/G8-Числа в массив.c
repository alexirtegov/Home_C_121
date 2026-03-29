/*
G8-Числа в массив

В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
Вывести массив по возрастанию в файл output.txt.

Input format
Строка из английских букв, цифр и знаков препинания

Output format
Последовательность целых чисел отсортированная по возрастанию

Input in input.txt
data 48 call 9 read13 blank0a

Output in output.txt
0 9 13 48

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//открываем файлы
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
	if(in==NULL){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);}
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}	
	
	//читаем через fgets в массив buffer[1001]
	char buffer[1001];
	if(fgets(buffer, sizeof(buffer), in)==NULL){
		printf("file read error");
        fclose(in);
        fclose(out);		
		return 1;
	}
	
	int len = 0;
	while(buffer[len]!='\n' && buffer[len] != '\0'){
		len ++;
	}
	buffer[len] = '\0';
	
	//читаем числа
	int numbers[1000]; //сюда будем записывать символы цифр, преобразованные в числа
	int count = 0;
	int num = 0;
	int in_number = 0; // флаг внутри ли мы числа
	
	for (int i = 0; i< len; i++){
		if (buffer[i] >='0' && buffer[i]<='9'){
			num = num*10 + (buffer[i] - '0');
			in_number = 1;
		} else {
			if(in_number == 1){
				numbers[count++] = num;
				num = 0;
				in_number = 0;
			}
		}
	}
	
	
	if(in_number == 1){ // этот вывод нужен если строка закончилась цифрой
		numbers[count++] = num;
	}
	 // Сортировка чисел
	 
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(numbers[i] > numbers[j]) {
                int t = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = t;
            }
        }
    }
    
    //вывод отсортированных чисел в файл
    for(int i = 0; i < count; i++) {
        fprintf(out, "%d ", numbers[i]);
    }
    	
	fclose(in);
	fclose(out);
	
	return 0;
}
