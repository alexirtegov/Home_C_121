 /*
  * 
G1-Три раза

В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

Input format
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.

Output format
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.

Examples
Input in input.txt
aab
Output in output.txt
aab, aab, aab 3

Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>
#define SIZE 101

int main(int argc, char **argv)
{
	char buffer[SIZE];
    int  count = 0;
    int  c;
    
    
	// создаем файл для записи
	FILE *file1 = fopen("C:\\Users\\User\\Desktop\\CI\\input.txt", "w");
	if(file1 == NULL){
		perror("input.txt");
		return 1; // Завершаем программу с ошибкой, если файл не открылся
	}
	
	//пишем aab в "input.txt"
	fputs("aab", file1);
	fprintf(file1, "aab");
	
	//закрываем и сохраняем в файл
	fclose(file1);
	
	//Открываем файл input.txt для чтения
	file1 = fopen("C:\\Users\\User\\Desktop\\CI\\input.txt", "r");
	if(file1 == NULL){
		perror("input.txt");
		return 1; // Завершаем программу с ошибкой, если файл не открылся
	}

    
    //читаем символы из файла input.txt
    while((c = fgetc(file1)) != EOF && count != SIZE-1){
		buffer[count++] = (char)c;
	}
	
	buffer[count] = '\0';
	
	//закрываем и сохраняем в файл
	fclose(file1);
    
    // если в конце buffer стоит '\n', заменяем его на '\0' и уменьшаем count
    if (count > 0 && buffer[count-1] == '\n') {
		buffer[count-1] = '\0';
		count--;
	}
    
    
    //Открываем файл для записи "output.txt" 
    FILE *file2 = fopen("output.txt", "w");
    if(file2 == NULL){
		perror("input.txt");
		return 2; // Завершаем программу с ошибкой, если файл не открылся
	}
    
    //Записываем в "output.txt" содержимое buffer три раза и затем count
    //   Формат: <buffer>, <buffer>, <buffer> <count> 
    fprintf(file2, "%s, %s, %s %d", buffer, buffer, buffer, count);
    
	//закрываем и сохраняем в файл
	fclose(file2);
	
	//открываем для чтения
   file2 = fopen("output.txt", "r");
   if(file2 == NULL){
		perror("input.txt");
		return 2; // Завершаем программу с ошибкой, если файл не открылся
	}
	
	// Читаем строку из "output.txt"
	char buffer2[SIZE];
	int num =0;
	
    while((c = fgetc(file2)) != EOF && num != SIZE-1){
		buffer2[num++] = (char)c;
	}
	
	buffer2[num] = '\0';	
	
    //Закрываем файл "output.txt"
    fclose(file2);
    	
    //выводим "output.txt" 
    printf("%s\n", buffer2);	
	
	return 0;
}



//вариант 2

//~ int main(void) {
    //~ char buffer[SIZE];
    //~ int  count = 0;

    //~ // Открываем существующий input.txt для чтения
    //~ FILE *in = fopen("input.txt", "r");
    //~ if (in == NULL) {
        //~ printf("Failed to open file for reading\n");
        //~ return 1;
    //~ }

    //~ // Читаем строку
    //~ /*Функция fgets(buffer, SIZE, in) читает из файла до SIZE−1 символов (либо до символа ‘\n’, 
     //~ либо до конца файла) и сразу же записывает прочитанные байты в ваш массив buffer. 
     //~ При этом она автоматически дописывает терминатор ‘\0’ в конец строки. 
     //~ Если чтение прошло успешно, то buffer уже содержит вашу строку, 
     //~ и вы можете дальше с ней работать (обрезать ‘\n’, подсчитать длину и т. д.). 
     //~ Закрытие файла на это никак не повлияет – данные в локальном массиве останутся.
     //~ */
    
    //~ if (fgets(buffer, SIZE, in)==NULL) {
        //~ fclose(in);
        //~ return 1;
    //~ }
    //~ fclose(in);


	//~ // Обрезаем возможный '\n' и считаем count */
	//~ while (buffer[count]!='\0' && buffer[count] != '\n'){
		//~ count ++;
	//~ }
	//~ if(buffer[count] =='\n'){
		//~ buffer[count] = '\0';
	//~ }
	
	
    //~ // Открываем output.txt для записи
    //~ FILE *out = fopen("output.txt", "w");
    //~ if (out == NULL) {
        //~ printf("Failed to open file for reading\n");
        //~ return 1;
    //~ }
    
    //~ // Пишем ровно одну строку без лишних '\n'
    //~ fprintf(out, "%s, %s, %s %d", buffer, buffer, buffer, count);
    
    //~ //закрываем
    //~ fclose(out);
    
    

   //~ //открываем output.txt для чтения
    //~ out = fopen("output.txt", "r");
        //~ if (out == NULL) {
        //~ printf("Failed to open file for reading\n");
        //~ return 1;
    //~ }
    
    //~ char buffer2[SIZE];
     //~ if (fgets(buffer2, SIZE, out)==NULL) {
        //~ fclose(in);
        //~ return 1;
    //~ }
  
    //~ //закрываем
    //~ fclose(out);   
    
    //~ printf("%s\n", buffer2);


    //~ return 0;
//~ }
