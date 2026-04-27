/*
 * temp_api.c
 * 
 * Copyright 2025 AlexeyIrtegov <AlexeyIrtegov@GLING>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <limits.h> // Для INT_MAX и INT_MIN
#define SIZE 30
//добавляем:
#include <stdlib.h> // Для atoi(), exit()
#include <string.h> // Для strtok(), strcspn()
#include <unistd.h> // Для getopt()

#include "temp_api.h"

//функцию, внесения записей
int add_record(struct temperature *date, int *count, int year, int month, int day, int hour, int minute, int temperature) 
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
