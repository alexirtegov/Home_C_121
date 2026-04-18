/*
Шаг 3: Функция для инициализации данных
Задача: Вынести добавление записей в отдельную функцию.

Доработай:

Создай функцию AddInfo(), которая:
Принимает массив структур
Добавляет 4 записи (см. ниже)
Возвращает количество добавленных записей
Данные для добавления:
   {2021, 9, 16, 9}
   {2022, 9, 2, -9}
   {2021, 1, 7, 8}
   {2021, 9, 5, 1}
 */

#include <stdio.h>
#include <stdint.h>
#define SIZE 30 

//ШАГ 1
struct sensor {
    uint8_t day;       // День (1-31) (диапазон 0-255), так как дни/месяцы не превышают 31.
    uint8_t month;     // Месяц (1-12) (диапазон 0-255), так как дни/месяцы не превышают 12.
    uint16_t year;     // Год (4 цифры)
    int8_t t;          // Температура (диапазон 0-255), (температура от -128 до +127). Этого достаточно для большинства регионов.
};

//ШАГ 2
void AddRecord(struct sensor* info, int index, uint16_t year, uint8_t month, uint8_t day, int8_t t) //Функция принимает указатель на массив структур, индекс, а также значения для полей. Заполняет структуру по указанному индексу.
{ 																									//Заполняет поля конкретного элемента массива
	info[index].year = year;
	info[index].month = month;
	info[index].day = day;
	info[index].t = t;
}

//ШАГ 3
int AddInfo(struct sensor* info)
{
	int count =0;	
	AddRecord(info, count++, 2021, 9, 16, 9);  //индекс 0
	AddRecord(info, count++, 2022, 9, 2, -9); //индекс 1
	AddRecord(info, count++, 2021, 1, 7, 8); //индекс 2
	AddRecord(info, count++, 2021, 9, 5, 1); //индекс 3
	
	return count; //возвращаем в main количество записей
}

//ШАГ 1
void Print (struct sensor* info, int count)
{
	printf("===================================\n");
	for(int i =0; i<count; i++){
		printf("%04d - %02d - %02d temperature = %3d\n",
		info[i].year,
		info[i].month,
		info[i].day,
		info[i].t);
		}
}


int main(int argc, char **argv)
{
		//Было в шаге 1, в шаге 2 перенесли в функцию AddRecord, а вывод в PrintAll
		//~ struct sensor data = {15, 5, 2023, 20};
		//альтернативная инициализация
		//~ struct sensor data;
		//~ data.day = 15;
		//~ data.month = 5;
		//~ data.year = 2023;
		//~ data.t = 20;
		//~ printf("day: %d month: %d year: %d temperature: %d", data.day, data.month, data.year, data.t);
	
		
	//ШАГ 1 
	struct sensor info [SIZE]; // шаг 2 массив структур с тегом sensor из SIZE записей
	
	//ШАГ3 считаем количество сделанных записей
	int Count = AddInfo(info);
	
	//ШАГ 1
	Print(info, Count);
	
	//ШАГ 2 объявлем функцию записи в массив структур info 
	//~ int count =0;	
	//~ AddRecord(info, count++, 2023, 5, 15, 20);  //индекс 0
	//~ AddRecord(info, count++, 2022, 12, 31, -5); //индекс 1
		

	
	return 0;
}
