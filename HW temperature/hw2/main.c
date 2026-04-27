/*
На основе ДЗ предыдущего урока реализовать:

Функции вывода статистики по каждому месяцу: среднемесячная температура, 
минимальная темпераура в текущем месяце, максимальная температура в текущем месце, 
вывод статистики за год:
-среднегодовая температура
-минимальная температура
-максимальная температура

	optarg:
Это специальная переменная из библиотеки getopt.h, которая автоматически сохраняет аргумент, следующий за флагом.
Пример: для команды ./program -d 7 → optarg = "7".
	atoi(optarg):
Функция atoi (ASCII to Integer) преобразует строку в целое число.
Примеры:
atoi("5") → 5
atoi("42") → 42
atoi("abc") → 0 (ошибка преобразования)

Функции добавления, удаления записей, сортировки и создания массива структур, печати массива

Приложение должно обрабатывать аргументы командной строки: минимальный набор поддерживаемых ключей:
-h Описание функционала приложения. Список ключей, которые обрабатывают данное приложение и их назначение
-f входной файл CSV для обработки
-m <номер месяца> если задан данный ключ, то выводится только статистика за указнный месяц.

Основные команды:
Справка (помощь по аргументам):
.\temperature.exe -h

Обязательный аргумент (указание входного файла):
.\temperature.exe -f temperature.txt

Статистика за конкретный месяц (1-12):
.\temperature.exe -f temperature.txt -m 5

Пример: статистика за май
Указание года (1900-2100, по умолчанию 2021):
.\temperature.exe -f temperature.txt -y 2021

Печать всех записей:
.\temperature.exe -f temperature.txt -p

Сортировка записей по дате/времени:
.\temperature.exe -f temperature.txt -s

Удаление записи по индексу (начиная с 0):
.\temperature.exe -f temperature.txt -d 2

Пример: удаление записи с индексом 2
Добавление новой записи (формат: yyyy;mm;dd;hh;mm;temp):
.\temperature.exe -f temperature.txt -a "2023;12;31;23;59;5"


Комбинированные примеры:
Добавление + печать:
.\temperature.exe -f temperature.txt -a "2023;12;31;23;59;5" -p

Удаление + печать:
.\temperature.exe -f temperature.txt -d 2 -p

Сортировка + печать:
.\temperature.exe -f temperature.txt -s -p

Статистика за май + печать:
.\temperature.exe -f temperature.txt -m 5 -p

Работа с другим годом:
.\temperature.exe -f temperature.txt -y 2022 -m 3

Особенности работы:
При запуске без аргумента -m выводит статистику по всем месяцам + годовую сводку
Файл данных должен содержать записи в формате:
2021;1;5;12;00;-7
При добавлении/удалении автоматически сохраняются изменения в памяти (но не в исходном файле)
 */







#include <stdio.h>
#include <limits.h> // Для INT_MAX и INT_MIN
#include <stdlib.h> // Для atoi(), exit()
#include <string.h> // Для strtok(), strcspn()
#include <unistd.h> // Для getopt()

#include "temp_api.h"



int main(int argc, char **argv)
{	
	//создаем путь к файлу      "C:\\git\\Home_C1\\hw temperature\\hw2\\temperature.txt";
	const char *filepath = NULL; 
	
	//объявляем массив структур с тегом temperature
	struct temperature date[SIZE];
	

	int count =0; // переменная в которую будем возвращать количество записей
	int target_month = 0; // 0 = все месяцы
	int year = 2021; // Год по умолчанию
   //добавил:
 
    int print_flag = 0;
    int sort_flag = 0;
    int delete_index = -1;
    int add_data = 0;
    int add_year, add_month, add_day, add_hour, add_minute, add_temp;	
	
	
	
	//Парсинг аргументов
	int opt;
	while((opt = getopt(argc, argv, "hf:m:y:ipd:sa:"))!=-1){ //Функция getopt возвращает следующий символ опции (например, 'h', 'f', 'm') или -1, если больше опций нет.
		//цикл while выполняется, пока getopt не вернет -1 (что означает конец опций).
		//'?', если встречена неизвестная опция/ошибка.
		
		switch(opt){
			
			case 'h':
                printf("Usage: %s -f <file.csv> [options]\n", argv[0]);
                printf("Options:\n");
                printf("  -f <file>  CSV file with data\n");
                printf("  -m <month> Month number (1-12)\n");
                printf("  -y <year>  Year (1900-2100)\n");
                printf("  -p         Print all records\n");
                printf("  -s         Sort records by date\n");
                printf("  -d <index> Delete record by index\n");
                printf("  -a <data>  Add new record (format: yyyy;mm;dd;hh;mm;temp)\n");
                printf("  -i         Interactive mode\n");
                printf("  -h         This help\n");
                return 0;
           
            case 'f':
				filepath = optarg; // - f temperature.txt тогда opt = 'f', optarg = temperature.txt
				break;
				
			case 'm': 				//-m <month> Month number (1-12)
				target_month = atoi(optarg);
                if (target_month < 1 || target_month > 12) {
                    fprintf(stderr, "Invalid month! Use 1-12\n");
                    return 1;
                }
                break;
                
           case 'y': 				//-y <year>  Year (1900-2100
                year = atoi(optarg);
                if (year < 1900 || year > 2100) {
                    fprintf(stderr, "Invalid year! Use 1900-2100\n");
                    return 1;
                }
                break;
                
            case 'p': 				// -p         Print all records
				print_flag = 1;
				break;
				
			case 's': 				//-s         Sort records by date
                sort_flag = 1;
                break;
                
            case 'i':				//-i         Interactive mode
			
				break;
				
			case 'd': 				//-d <index> Delete record by index
				delete_index = atoi(optarg);
				break;
				
			case 'a': 				//-a <data>  Add new record (format: yyyy;mm;dd;hh;mm;temp)
				if(sscanf(optarg, "%d;%d;%d;%d;%d;%d", // sscanf считывает данные из строки optarg по заданному формату
				 &add_year, &add_month, &add_day, &add_hour, &add_minute, &add_temp)==6){
					 add_data = 1;
				} else {
                    fprintf(stderr, "Invalid format for -a! Use yyyy;mm;dd;hh;mm;temp\n");
                    return 1;
                }
                break;
				
            case '?':
                fprintf(stderr, "Unknown option! Use -h for help.\n");
                return 1;
				
		}
		
	}
	
	if (!filepath) {
        fprintf(stderr, "CSV file required! Use -f <file>\n");
        return 1;
    }

	//функция чтения из файла -a
	count = load_from_csv(date, filepath);
    
    //добавление через аргумент командной строки
    if (add_data) {
        if (add_record(date, &count, add_year, add_month, add_day,
                      add_hour, add_minute, add_temp)) {
            printf("New record added successfully!\n");
        }
    }	
	
	//удаление через аргумент командной строки -d
    if (delete_index != -1) {
        delete_record(date, &count, delete_index); //delete_index из ввода аргумента
    }
   
   //сортировка через аргумент -s
   if (sort_flag) {
        sort_records(date, count);
    }    
    
    //печать через аргумент -p
    if (print_flag) {
        print_all(date, count);
    }
    
      
    
	//сортировка через аргумент -m
	if (target_month > 0) {
		monthly_stats(date, count, year, target_month);
	
	} else {
   
		// Вывод статистики по всем месяцам
		for (int month = 1; month <= 12; month++) {
			monthly_stats(date, count, year, month);
		}
		
    // И годовая статистика
    yearly_stats(date, count, year);
}
	

	
	
	return 0;
}
