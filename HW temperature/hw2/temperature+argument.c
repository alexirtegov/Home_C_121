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
#define SIZE 30
//добавляем:
#include <stdlib.h> // Для atoi(), exit()
#include <string.h> // Для strtok(), strcspn()
#include <unistd.h> // Для getopt()

//определяемся с структурой данных
struct temperature {
	
        int year;   // dddd (4 цифры)
        int month;  // mm (2 цифры)
        int day;    // dd (2 цифры)
        int hour;   // hh (2 цифры)
        int minute; // mm (2 цифры)
        int temperature; // от -99 до 99
	
};

//функцию, внесения записей
int add_record(struct temperature *date, int *count, //мы получили адрес,а не значение
               int year, int month, int day, 
               int hour, int minute, int temperature) 
//count — это указатель на переменную, которая хранит текущее количество записей в базе.
//Зачем указатель? Чтобы функция могла изменить значение переменной в том месте, откуда её вызвали.
{
    if (*count >= SIZE) {
        printf("Error: Database is full (max %d records)\n", SIZE);
        return 0;
    }
    
    // Проверка корректности данных
    if (year < 1900 || year > 2100 || temperature < -99 || temperature > 99) {
        printf("Invalid data!\n");
        return 0;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31 ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid data!\n");
        return 0;
    }
    
    date[*count].year = year;
    date[*count].month = month;
    date[*count].day = day;
    date[*count].hour = hour;
    date[*count].minute = minute;
    date[*count].temperature = temperature;
    
    (*count)++;  //*count_ptr++; ОПАСНО: увеличиваем сам указатель (сдвигаем адрес)!
    return 1;
}

//заменим функцию  addinfo() на:
int load_from_csv(struct temperature *date, const char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (!f) {
        perror(filepath);
        exit(1);
    }
    
    int count = 0;
    int year, month, day, hour, minute, temperature;
    
    while (count < SIZE && 
           fscanf(f, "%d;%d;%d;%d;%d;%d", 
                  &year, &month, &day, &hour, &minute, &temperature) == 6) {
					  
        add_record(date, &count, year, month, day, hour, minute, temperature);
        
    }
    
    fclose(f);
    return count;
}



 //3. Вычислить минимальную, максимальную и среднюю температуру для этого месяца.
void monthly_stats(struct temperature *date, int count, int year, int month)
{
		int min_temperature = INT_MAX; //самое большое интовое число - больше нет
		int max_temperature = INT_MIN; //самое маленькое интовое число - меньше нет
		int sum = 0;
		int num = 0;
		
		//проходим по всем записям по каждому месяцу
		for(int i =0; i<count; i++){
			if(date[i].year == year && date[i].month == month){  //Отфильтровать записи, которые соответствуют заданному году и месяцу.
				int temp = date[i].temperature;
				sum += temp;
				num ++;
				
				if(temp<min_temperature){
					min_temperature = temp; //находим максимальную температуру
				}
				if(temp>max_temperature){ // находим минимальную температуру
					max_temperature = temp;
				}
			}
		}
		
		// Выводим результат только если есть данные
		if(num>0){
			float average_temperature = (float)sum/num;
			printf("Month %d: average temperature = %.1f, coldest = %d, hottest = %d\n",month, average_temperature, min_temperature, max_temperature);
		} else {
			printf("Month %d: no data\n", month);
		}
	
		
	
}

void yearly_stats(struct temperature *date, int count, int year) 
{
		int min_temperature = INT_MAX; //самое большое интовое число - больше нет
		int max_temperature = INT_MIN; //самое маленькое интовое число - меньше нет
		int sum = 0;
		int num = 0;
	
		//проходим по всем записям за год
		for(int i =0; i<count; i++){
			if(date[i].year == year){  //Отфильтровать записи, которые соответствуют заданному году и месяцу.
				int temp = date[i].temperature;
				sum += temp;
				num ++;
				
				if(temp<min_temperature){
					min_temperature = temp; //находим максимальную температуру
				}
				if(temp>max_temperature){ // находим минимальную температуру
					max_temperature = temp;
				}
			}
		}
		
		// Выводим результат только если есть данные
		if(num>0){
			float average_temperature = (float)sum/num;
			printf("\nYear %d: average temperature = %.1f, coldest = %d, hottest = %d\n",year, average_temperature, min_temperature, max_temperature);
		} else {
			printf("Year %d: no data\n", year);
		}
	
		
}

//Функция печати всего массива (вывод всех записей)
void print_all(struct temperature *date, int count) {
    printf("\nAll temperature records:\n");
    printf("----------------------------------------------------\n");
    printf("   Date     |  Time  | Temperature\n");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%04d-%02d-%02d | %02d:%02d | temperature = %d C\n", 
               date[i].year, date[i].month, date[i].day,
               date[i].hour, date[i].minute,
               date[i].temperature);
    }
    printf("----------------------------------------------------\n");
    printf("Total records: %d\n", count);
}

//функция удаления записей
void delete_record(struct temperature *date, int *count, int index) {
    // 1. Проверка валидности индекса
    if (index < 0 || index >= *count) { //index >= *count: Защита от индексов за пределами массива
        printf("Invalid index! Must be between 0 and %d\n", *count-1);
        return;
    }
    
    // 2. Сдвиг элементов массива
    for (int i = index; i < *count - 1; i++) {
        date[i] = date[i + 1];
    }
    
    // 3. Уменьшение счётчика
    (*count)--;
    printf("Record %d deleted successfully\n", index);
}

//функция сортировки по тдате и времени
void sort_records(struct temperature *date, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // Сравниваем даты
            if (date[j].year > date[j+1].year ||
                (date[j].year == date[j+1].year && date[j].month > date[j+1].month) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day > date[j+1].day) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day == date[j+1].day && date[j].hour > date[j+1].hour) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day == date[j+1].day && date[j].hour == date[j+1].hour && date[j].minute > date[j+1].minute)) {
                
                // Меняем местами
                struct temperature temp = date[j];
                date[j] = date[j+1];
                date[j+1] = temp;
            }
        }
    }
    printf("Records sorted by date and time!\n");
}

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
