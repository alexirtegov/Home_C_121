/*
 * temp_api.c

 */

#include <stdio.h>
#include <limits.h> // Для INT_MAX и INT_MIN
#include "temp_api.h"
#define SIZE 30

//функцию, которая будет раскладывать по полям структуры по массиву
void AddRecord(struct temperature *date, int count, int year, int month,
				int day, int hour, int minute, int temperature)
{
	date[count].year = year;
	date[count].month = month;
	date[count].day = day;
	date[count].hour = hour;
	date[count].minute = minute;
	date[count].temperature = temperature;
}   

//функция внесения данных из программы
int addinfo(struct temperature *date)
{
	int count = 0;
	
	//вызываем другую функцию, которая будет раскладывать по полям структуры
	AddRecord(date, count++, 2021, 1, 10, 22, 50, -5);  //индекс 0
	AddRecord(date, count++, 2021, 1, 30, 22, 50, 1);  //индекс 0
	AddRecord(date, count++, 2021, 2, 1, 22, 50, 0);  //индекс 1
	AddRecord(date, count++, 2021, 2, 25, 22, 50, 3);  //индекс 1
	AddRecord(date, count++, 2021, 3, 1, 22, 50, 5);  //индекс 2
	AddRecord(date, count++, 2021, 3, 20, 30, 50, 8);  //индекс 2
	AddRecord(date, count++, 2021, 4, 1, 22, 50, 5);  //индекс 3
	AddRecord(date, count++, 2021, 4, 28, 30, 50, 15);  //индекс 3
	
	return count;
}



 //3. Вычислить минимальную, максимальную и среднюю температуру для этого месяца.
void monthly_stats(struct temperature *date, int count, int year)
{
	for(int month = 1; month <=12; month ++){ //Для каждого месяца (от 1 до 12) пройти по всем записям.
		
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
			printf("Month %d: no data\n", year);
		}
	
		
}
