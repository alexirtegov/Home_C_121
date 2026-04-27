/*
Курсовая:
Создание консольного приложения - Статистика температуры.
Необходимо реализовать консольное приложение, которое
осуществляет считывание текстового файла csv, состоящего из
строк следующего формата:

YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE
dddd;mm;dd;hh;mm;temperature
dddd - год 4 цифры
mm - месяц 2 цифры

dd - день 2 цифры

hh - часы 2 цифры

mm - минуты 2 цифры

temperature - целое число от -99 до 99



В файле хранится статистика собранная датчиком температуры за
1 календарный год. Предполагается, что датчик собирал
информацию не чаще чем 1 раз в минуту и сохранял в заданном
формате каждое значение в текстовый файл с новой строки. В
какой-то момент времени датчик мог не работать, тогда данные по
этому периоду могут отсутствовать. Пример входного файла:

YEAR MONTH DAY HOUR MINUTE TEMPERATURE
2021    1   1   23    1        -5
2021    1   1   23    3        -6
2021    1   1   23    1        -7
2021    1   2    7    5        -10
 
Необходимо вывести статистику по каждому месяцу, с учетом
исходных данных:

• среднемесячная температура

• минимальная температура в текущем месяце

• максимальная температура в текущем месяце

Также необходимо вывести статистику за год:

• среднегодовая температура

• минимальная температура

• максимальная температура

 
Приложение должно обрабатывать аргументы командной строки:
минимальный набор поддерживаемых ключей:
• -h Описание функционала приложения. Список ключей, которые
обрабатывает данное приложение и их назначение.
• -f <filename.csv> входной файл csv для обработки.
• -m <номер месяца> если задан данный ключ, то выводится
только статистика за указанный месяц.

Приложение должно корректно работать на любых входных
данных, если формат csv файла не соответствует заданному, то
необходимо указать номер строки файла csv, в которой
обнаружена ошибка и не учитывать данную строку.

Приложение должно собираться при помощи утилиты make.

Все прототипы функций используемые в приложении должны быть
вынесены в отдельный файл temp_functions.h
Тексты функций - в файл temp_functions.c.
Для реализации приложения рекомендуется использовать массив
из структурного типа данных для хранения показаний датчика.

●	temperature_small.csv — укороченный файл с ошибками для тестирования
__________________________________________________________

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
.\temperature.exe -f temperature_big.csv

Поиск строк с ошибками:
.\temperature.exe -f temperature_big.csv -e

Статистика за конкретный месяц (1-12):
.\temperature.exe -f temperature_big.csv -m 5
Пример: статистика за май

Указание года (1900-2100, по умолчанию 2021):
.\temperature.exe -f temperature_big.csv -y 2021

Печать всех записей:
.\temperature.exe -f temperature_big.csv -p

Сортировка записей по дате/времени:
.\temperature.exe -f temperature_big.csv -s

Удаление записи по индексу (начиная с 0):
.\temperature.exe -f temperature_big.csv -d 2

Пример: удаление записи с индексом 2
Добавление новой записи (формат: yyyy;mm;dd;hh;mm;temp):
.\temperature.exe -f temperature_big.csv -a "2023;12;31;23;59;5"


Комбинированные примеры:
Добавление + печать:
.\temperature.exe -f temperature_big.csv -a "2023;12;31;23;59;5" -p

Удаление + печать:
.\temperature.exe -f temperature_big.csv -d 2 -p

Сортировка + печать:
.\temperature.exe -f temperature_big.csv -s -p

Статистика за май + печать:
.\temperature.exe -f temperature_big.csv -m 5 -p

Работа с другим годом:
.\temperature.exe -f temperature_big.csv -y 2022 -m 3

Особенности работы:
При запуске без аргумента -m выводит статистику по всем месяцам + годовую сводку
Файл данных должен содержать записи в формате:
2021;1;5;12;00;-7
При добавлении/удалении автоматически сохраняются изменения в памяти (но не в исходном файле)
 */






#include <stdio.h>
#include <stdlib.h>     // Для malloc/realloc/free, atoi, exit
#include <limits.h>     // Для INT_MAX, INT_MIN
#include <string.h>     // Для strcspn, strtok, sscanf
#include <unistd.h>     // Для getopt

// Структура — одна запись температуры
struct temperature {
    int year;        // Год (4 цифры)
    int month;       // Месяц (1-12)
    int day;         // День (1-31)
    int hour;        // Час (0-23)
    int minute;      // Минута (0-59)
    int temperature; // Температура (-99..99)
};

// -------------------------------------
// ДИНАМИЧЕСКОЕ чтение CSV-файла в массив
// -------------------------------------
//
// date_ptr - адрес указателя на массив (чтобы функция могла изменить его)
// filepath - путь к csv-файлу
// capacity_ptr - адрес переменной "ёмкость" (capacity)
// error_check_flag - если 1, то просто выводим ошибки в формате/диапазоне и не загружаем массив
//                    если 0, то реально читаем записи и пишем в массив
// возвращает сколько строк прочитано/добавлено в массив
int load_from_csv(struct temperature **date_ptr,
                  const char *filepath,
                  int *capacity_ptr,
                  int error_check_flag)
{
    FILE *f = fopen(filepath, "r");
    if (!f) {
        perror(filepath);
        exit(1);
    }

    int count = 0;                // Сколько реально считано записей
    int capacity = *capacity_ptr; // Текущая выделенная длина массива
    char buffer[128];
    int line_num = 0;

    while (fgets(buffer, sizeof(buffer), f)) {
        line_num++;
        buffer[strcspn(buffer, "\r\n")] = 0; // убрать перевод строки

        int year, month, day, hour, minute, temperature;
        int fields = sscanf(buffer, "%d;%d;%d;%d;%d;%d",
                            &year, &month, &day, &hour, &minute, &temperature);

        if (fields != 6) {
            if (error_check_flag)
                printf("Error in line %d: \"%s\" [format]\n", line_num, buffer);
            continue; // ошибка формата, не пытаемся читать дальше
        }
        // Проверка диапазона значений
        if (year < 1900 || year > 2100 ||
            month < 1 || month > 12 ||
            day < 1 || day > 31 ||
            hour < 0 || hour > 23 ||
            minute < 0 || minute > 59 ||
            temperature < -99 || temperature > 99) {
            if (error_check_flag)
                printf("Error in line %d: \"%s\" [values]\n", line_num, buffer);
            continue;
        }
        if (!error_check_flag) {
            // Проверяем — хватит ли места в массиве? Если нет — увеличим его через realloc
            if (count >= capacity) {
                int new_capacity = (capacity == 0) ? 100 : capacity * 2;
                struct temperature *newp =
                    realloc(*date_ptr, new_capacity * sizeof(struct temperature));
                if (!newp) {
                    fprintf(stderr, "Out of memory!\n");
                    fclose(f);
                    exit(1);
                }
                *date_ptr = newp;
                capacity = new_capacity;
                *capacity_ptr = capacity;
            }
            // Добавляем запись
            (*date_ptr)[count].year = year;
            (*date_ptr)[count].month = month;
            (*date_ptr)[count].day = day;
            (*date_ptr)[count].hour = hour;
            (*date_ptr)[count].minute = minute;
            (*date_ptr)[count].temperature = temperature;
            count++;
        }
    }
    fclose(f);
    return count;
}

// ---------------------------------------
// Добавление одной записи (через -a опцию)
// ---------------------------------------
int add_record(struct temperature **date_ptr, int *count_ptr, int *capacity_ptr,
               int year, int month, int day,
               int hour, int minute, int temperature)
{
    // Проверка диапазона
    if (year < 1900 || year > 2100 ||
        month < 1 || month > 12 ||
        day < 1 || day > 31 ||
        hour < 0 || hour > 23 ||
        minute < 0 || minute > 59 ||
        temperature < -99 || temperature > 99) {
        printf("Invalid data for record!\n");
        return 0;
    }

    // Места хватит? Если нет — увеличиваем
    if (*count_ptr >= *capacity_ptr) {
        int new_capacity = (*capacity_ptr == 0) ? 100 : (*capacity_ptr) * 2;
        struct temperature *newp =
            realloc(*date_ptr, new_capacity * sizeof(struct temperature));
        if (!newp) {
            fprintf(stderr, "Out of memory!\n");
            return 0;
        }
        *date_ptr = newp;
        *capacity_ptr = new_capacity;
    }
    // Добавляем запись
    (*date_ptr)[*count_ptr].year = year;
    (*date_ptr)[*count_ptr].month = month;
    (*date_ptr)[*count_ptr].day = day;
    (*date_ptr)[*count_ptr].hour = hour;
    (*date_ptr)[*count_ptr].minute = minute;
    (*date_ptr)[*count_ptr].temperature = temperature;
    (*count_ptr)++;
    return 1;
}

// ------------------------------------------------------
// Печать всех записей
// ------------------------------------------------------
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

// ------------------------------------------------------
// Удалить запись по её индексу (без утечек памяти)
// ------------------------------------------------------
void delete_record(struct temperature *date, int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("Invalid index! Must be between 0 and %d\n", *count-1);
        return;
    }
    for (int i = index; i < *count-1; i++) {
        date[i] = date[i+1]; // сдвиг влево
    }
    (*count)--;
    printf("Record %d deleted successfully\n", index);
}

// ------------------------------------------------------
// Сортировка записей по дате и времени (bubble sort)
// ------------------------------------------------------
void sort_records(struct temperature *date, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (date[j].year > date[j+1].year ||
                (date[j].year == date[j+1].year && date[j].month > date[j+1].month) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day > date[j+1].day) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day == date[j+1].day && date[j].hour > date[j+1].hour) ||
                (date[j].year == date[j+1].year && date[j].month == date[j+1].month && date[j].day == date[j+1].day && date[j].hour == date[j+1].hour && date[j].minute > date[j+1].minute)) {
                struct temperature temp = date[j];
                date[j] = date[j+1];
                date[j+1] = temp;
            }
        }
    }
    printf("Records sorted by date and time!\n");
}

// ------------------------------------------------------
// Месячная статистика (минимум, максимум, среднее)
// ------------------------------------------------------
void monthly_stats(struct temperature *date, int count, int year, int month) {
    int min_temperature = INT_MAX;
    int max_temperature = INT_MIN;
    int sum = 0;
    int num = 0;
    for(int i = 0; i < count; i++) {
        if(date[i].year == year && date[i].month == month) {
            int temp = date[i].temperature;
            sum += temp;
            num++;
            if(temp < min_temperature)
                min_temperature = temp;
            if(temp > max_temperature)
                max_temperature = temp;
        }
    }
    if(num > 0) {
        float average_temperature = (float)sum / num;
        printf("Month %d: average temperature = %.1f, coldest = %d, hottest = %d\n", month, average_temperature, min_temperature, max_temperature);
    } else {
        printf("Month %d: no data\n", month);
    }
}

// ------------------------------------------------------
// Годовая статистика (минимум, максимум, среднее)
// ------------------------------------------------------
void yearly_stats(struct temperature *date, int count, int year) {
    int min_temperature = INT_MAX;
    int max_temperature = INT_MIN;
    int sum = 0;
    int num = 0;
    for(int i =0; i<count; i++){
        if(date[i].year == year){
            int temp = date[i].temperature;
            sum += temp;
            num ++;
            if(temp<min_temperature) min_temperature = temp;
            if(temp>max_temperature) max_temperature = temp;
        }
    }
    if(num>0){
        float average_temperature = (float)sum/num;
        printf("\nYear %d: average temperature = %.1f, coldest = %d, hottest = %d\n", year, average_temperature, min_temperature, max_temperature);
    } else {
        printf("Year %d: no data\n", year);
    }
}


// =====================================
//            MAIN
// =====================================
int main(int argc, char **argv)
{
    const char *filepath = NULL;                // Имя CSV-файла
    struct temperature *date = NULL;            // Динамический массив структур
    int capacity = 0;                           // Емкость массива (capacity)
    int count = 0;                              // Количество реально загруженных записей

    // Параметры запуска
    int error_check_flag = 0;
    int print_flag = 0;
    int sort_flag = 0;
    int delete_index = -1;
    int add_data = 0;
    int add_year, add_month, add_day, add_hour, add_minute, add_temp;
    int target_month = 0;
    int year = 2021; // Год по умолчанию

    // Парсинг аргументов (обратите внимание — добавлен 'e' в строку для getopt)
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:y:ipd:sa:e")) != -1) {
        switch (opt) {
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
                printf("  -e         Error search (don't load records, only show errors)\n");
                return 0;

            case 'f':
                filepath = optarg;
                break;
            case 'm':
                target_month = atoi(optarg);
                if (target_month < 1 || target_month > 12) {
                    fprintf(stderr, "Invalid month! Use 1-12\n");
                    return 1;
                }
                break;
            case 'y':
                year = atoi(optarg);
                if (year < 1900 || year > 2100) {
                    fprintf(stderr, "Invalid year! Use 1900-2100\n");
                    return 1;
                }
                break;
            case 'p':
                print_flag = 1;
                break;
            case 's':
                sort_flag = 1;
                break;
            case 'i':
                // Интерективный режим не реализован, можно доработать!
                break;
            case 'd':
                delete_index = atoi(optarg);
                break;
            case 'a':
                if(sscanf(optarg, "%d;%d;%d;%d;%d;%d",
                    &add_year, &add_month, &add_day, &add_hour, &add_minute, &add_temp)==6) {
                    add_data = 1;
                } else {
                    fprintf(stderr, "Invalid format for -a! Use yyyy;mm;dd;hh;mm;temp\n");
                    return 1;
                }
                break;
            case 'e':
                error_check_flag = 1;
                break;
            case '?':
                fprintf(stderr, "Unknown option! Use -h for help.\n");
                return 1;
        }
    }

    // Файл обязателен для загрузки (кроме -h)
    if (!filepath) {
        fprintf(stderr, "CSV file required! Use -f <file>\n");
        return 1;
    }

    // Загрузка из файла (save entries to dynamic array — если не -e)
    count = load_from_csv(&date, filepath, &capacity, error_check_flag);
    if (error_check_flag) {
        // Проверка ошибок завершена, ничего не загружаем, освобождаем память и выходим
        free(date);
        return 0;
    }

    // Добавление через -a (add record)
    if (add_data) {
        if (add_record(&date, &count, &capacity, add_year, add_month, add_day, add_hour, add_minute, add_temp)) {
            printf("New record added successfully!\n");
        }
    }

    // Удаление по индексу (delete record)
    if (delete_index != -1) {
        delete_record(date, &count, delete_index);
    }

    // Сортировка (sort records)
    if (sort_flag) {
        sort_records(date, count);
    }

    // Печать (print all)
    if (print_flag) {
        print_all(date, count);
    }

    // Статистика — по месяцу или по всем месяцам и за год
    if (target_month > 0) {
        monthly_stats(date, count, year, target_month);
    } else {
        for (int month = 1; month <= 12; month++)
            monthly_stats(date, count, year, month);
        yearly_stats(date, count, year);
    }

    // Очищаем память
    free(date);
    return 0;
}
