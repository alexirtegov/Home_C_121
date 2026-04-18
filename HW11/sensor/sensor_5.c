/*
Шаг 5: Сортировка по дате
Задача: Реализовать сортировку по возрастанию даты.

Доработай:

Создай функцию DateToInt(), 
преобразующую дату в число формата ГГГГММДД:
	
	Функция преобразует дату в одно целое число по схеме:
	return data->year << 16 | data->month << 8 | data->day;
	Пример:
		Год 2023, месяц 5, день 15 -> 
		
		year << 16: Сдвигает год на 16 бит влево 
		место для месяца и дня)
		2023 << 16 = 2023 * 65536 = 132644864
		
		month << 8: Сдвигает месяц на 8 бит.
		5 << 8 = 5 * 256 = 1280
		
		day: Остаётся как есть.
		день = 15
		
		Итого: 132644864 + 1280 + 15 = 132646159
		
			Таким образом, битовая маска для даты будет:
			- Биты 24-31 и 16-23: год (старшие 16 бит, но так как сдвинуто на 16, то занимает биты 16-31)
			- Биты 8-15: месяц
			- Биты 0-7: день
				
				Пример с датой 2023 год, 5 месяц, 15 день:
				2023 в двоичном виде: 00000111 11100111 (но так как это 32 бита, то: 0x000007E7)
				Сдвигаем на 16 бит влево: 0x07E70000
				5 сдвигаем на 8 бит: 0x00000500
				15: 0x0000000F
				Объединяем с помощью OR: 0x07E70000 | 0x00000500 | 0x0000000F = 0x07E7050F

				2023 << 16  →  0x07E70000  // 00000111 11100111 00000000 00000000
				5    << 8   →  0x00000500  // 00000000 00000000 00000101 00000000
				15          →  0x0000000F  // 00000000 00000000 00000000 00001111
				Оператор | (битовое ИЛИ) объединяет битовые маски:
											  00000111 11100111 00000101 00001111
		В шестнадцатеричном виде: 
		0x000007E7 0x05 0x0F -> 0x000007E7050F 
		(но на самом деле, так как мы используем 32-битное число, 
		то будет 0x07E7050F).

		Функция `SortByDate` использует этот метод для сравнения дат. 
		Вместо того чтобы сравнивать структуры напрямую, 
		мы сравниваем полученные целые числа.
		
		Так как мы используем побитовые сдвиги, важно, 
		чтобы поля `year`, `month`, `day` были беззнаковыми 
		(или неотрицательными) и помещались в отведенные биты. 

Реализуй сортировку в SortByDate() 
(аналогично SortByT(), но используя DateToInt)

Добавь вывод в main() после этой сортировки
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

//ШАГ4 сортировка по возрастанию температуры.
void swap(struct sensor *i, struct sensor *j){ //мы ничего не возвращаем так как работаем меняем сразу по адресам
	struct sensor temp =*i;
	*i = *j;
	*j = temp;
}

void SortByTemperature (struct sensor *info, int count)
{
		for (int i=0; i<count; i++){
			for(int j=i; j<count; j++){
				if(info[i].t>info[j].t){
					swap(&info[i], &info[j]); // передаём указатели (адреса) на соответствующеие структуры
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				}
			}
		}
}
//ШАГ 5 сортировка по дате через битовое преобразования и операцию или (+)
 //~ unsigned int DateToInt(struct sensor* data) 
 //~ {
	//~ return data->year << 16 | data->month << 8 | data->day;
 //~ }

void SortByDate (struct sensor *info, int count)
{
	for (int i=0; i<count; i++){
		unsigned int value_i = info[i].year << 16 | info[i].month << 8 | info[i].day;
			for(int j=i; j<count; j++){
				unsigned int value_j = info[j].year << 16 | info[j].month << 8 | info[j].day;
				if(value_i > value_j){
					swap(&info[i], &info[j]);
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				}
				
				
				//через DateToInt
				//~ if(DateToInt(&info[i]) > DateToInt(&info[j])){ // передаём указатели (адреса) на соответствующеие структуры
					//~ swap(&info[i], &info[j]);
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				//~ }
			}
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
	printf ("before sort:\n");
	Print(info, Count);
	
	//ШАГ 2 объявлем функцию записи в массив структур info 
	//~ int count =0;	
	//~ AddRecord(info, count++, 2023, 5, 15, 20);  //индекс 0
	//~ AddRecord(info, count++, 2022, 12, 31, -5); //индекс 1
		
	//ШАГ 4 сортировка по температуре
	SortByTemperature(info, Count);
	printf ("\nSort by temperature: \n");
	Print(info, Count);
	
	//ШАГ 5 сортировка по дате
	SortByDate(info, Count);
	printf ("\nSort by Date: \n");
	Print(info, Count);
	
	return 0;
}
