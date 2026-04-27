/*
 * temp_api.h

 */

#ifndef TEMP_API_H
#define TEMP_API_H

#define SIZE 30

//определяемся с структурой данных
struct temperature {
	
        int year;   // dddd (4 цифры)
        int month;  // mm (2 цифры)
        int day;    // dd (2 цифры)
        int hour;   // hh (2 цифры)
        int minute; // mm (2 цифры)
        int temperature; // от -99 до 99
	
};
 
 
//прототипы функций:

//функцию, внесения записей
int add_record(struct temperature *date, int *count, int year, int month, int day, int hour, int minute, int temperature);

//чтение из файла
int load_from_csv(struct temperature *date, const char *filepath);

 //3. Вычислить минимальную, максимальную и среднюю температуру для этого месяца.
void monthly_stats(struct temperature *date, int count, int year, int month);

//4.Вычислить минимальную, максимальную и среднюю температуру для года.
void yearly_stats(struct temperature *date, int count, int year);

//Функция печати всего массива (вывод всех записей)
void print_all(struct temperature *date, int count);

//функция удаления записей
void delete_record(struct temperature *date, int *count, int index);

//функция сортировки по тдате и времени
void sort_records(struct temperature *date, int count);

#endif
