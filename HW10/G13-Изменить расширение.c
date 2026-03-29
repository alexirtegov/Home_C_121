/*
G13-Изменить расширение

Изменить расширение
В файле input.txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.

Input format
Строка состоящая из символов: a-z, A-Z, 0-9, /

Output format
Исходная строка с измененным расширением.



Input in input.txt
/DOC.TXT/qqq

Output in output.txt
/DOC.TXT/qqq.html


Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)

Решение (сложное для меня):
1. Прочитайте строку из файла input.txt — используйте функцию fgets, 
чтобы получить путь файла в массив символов (например, buffer[1001]).
2. Пройдитесь по всей строке от начала до конца — ищите символ точки ('.').
НО: искать только после последнего символа '/' — потому что точка в 
папке не обязательно расширение!
3. Запомните позицию последней найденной точки после последнего '/' 
— это может быть начало расширения, если оно есть.
4. Когда строка закончилась, проверьте:
если после последнего '/' нет точки, значит расширения нет,
если точка есть — она и есть расширение.
5. Скопируйте всё, что до расширения, в новую строку.
Если расширение было, обрежьте его (то есть скопируйте только до точки).
Если не было — скопируйте всю строку.
6. В конец допишите новую строку ".html". 
Просто добавьте символы ., h, t, m, l, \0 по очереди.
7. Результат запишите в output.txt — используйте fprintf или fputs.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL) {
        perror("input.txt");
        if (out != NULL) {
            fclose(out);
        }
        return 1;
    }

    if (out == NULL) {
        perror("output.txt");
        fclose(in);
        return 1;
    }
    // читаем строку в buffer[]
    char buffer[1001];
    if (fgets(buffer, 1001, in) == NULL) {
        fclose(in);
        fclose(out);
        return 1;
    }
    int len = 0;
    while (buffer[len] != '\n' && buffer[len] != '\0') {
        len++;
    }
    buffer[len] = '\0';

    // поиск последнего '/' и последней '.' после него
    int lastSlash = -1;
    int lastDot = -1;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '/'){
			 lastSlash = i;
		 }
        if (buffer[i] == '.' && i > lastSlash) {
			lastDot = i;
		}
		
    }

    // Копируем имя файла (всё до расширения, если оно есть)
    char result[1001];
    int res_i = 0;

    if (lastDot > lastSlash) {
        for (int i = 0; i < lastDot; i++) {
            result[res_i++] = buffer[i];
        }
    } else {
        // Нет расширения — копируем всю строку
        for (int i = 0; buffer[i] != '\0'; i++) {
            result[res_i++] = buffer[i];
        }
    }

    // Добавляем ".html"
    result[res_i++] = '.';
    result[res_i++] = 'h';
    result[res_i++] = 't';
    result[res_i++] = 'm';
    result[res_i++] = 'l';
    result[res_i] = '\0';

    // Записываем результат в файл
    fprintf(out, "%s", result);

    fclose(in);
    fclose(out);

    return 0;
} 
