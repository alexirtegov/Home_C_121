/*
Шаг 7:   файл находится в "C:/FILE/temperature.txt"
добавим чтение из файла

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

//ШАГ 6
int ManualInput (struct sensor* info)
{
	int count = 0;
	printf ("maximum amount of memory for data input (max %d): ", SIZE);
	printf("Enter number of records (max %d): ", SIZE);
    scanf("%d", &count);
    
    if(count > SIZE){
		count = SIZE;
	}
	
	for (int i =0; i<count; i++){
		unsigned int year, month, day;
        int t;  // int вместо int8_t
        
        printf("Record #%d (year month day temperature): ", i+1);
        scanf("%u %u %u %d", &year, &month, &day, &t);
        
        // Проверка и приведение типов
        if (year> 65535) year = 65535;
        if (month > 255) month = 255;
        if (day > 255) day = 255;
        if (t < -128) t = -128;
        if (t > 127) t = 127;
        
        AddRecord(info, i, (uint16_t)year, (uint8_t)month, (uint8_t)day, (int8_t)t);
	}
	return count;
}

// ШАГ 7: Функция для чтения данных из файла
int FileInput(struct sensor* info) {
    FILE* file = fopen("C:\\FILE\\temperature.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;
    unsigned int year, month, day;
    int t;

    while (count < SIZE && 
           fscanf(file, "%u %u %u %d", &year, &month, &day, &t) == 4) {
        // Проверка и приведение типов
        if (year > 65535) year = 65535;
        if (month > 255) month = 255;
        if (day > 255) day = 255;
        if (t < -128) t = -128;
        if (t > 127) t = 127;
        
        AddRecord(info, count, (uint16_t)year, (uint8_t)month, (uint8_t)day, (int8_t)t);
        count++;
    }
    
    fclose(file);
    return count;
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
	
	
	//ШАГ 3 считаем количество сделанных записей
	//~ int Count = AddInfo(info); //при scanf не нужно
	//ШАГ 6 ввод данных через scanf c сохранением AddInfo
	//~ int Count = 0;
	//~ char mode;
	
    //~ printf("Use (a)uto data or (m)anual input? [a/m]: ");
    //~ scanf(" %c", &mode);
    
    //~ if (mode == 'm' || mode == 'M') {
        //~ Count = ManualInput(info);
    //~ } else {
        //~ Count = AddInfo(info);  // Стандартные тестовые данные
    //~ }
	
	//ШАГ 7 ввод данных через файл
	
	int Count = 0;
    char mode;
    
    printf("Use (a)uto data, (m)anual input or (f)ile? [a/m/f]: ");
    scanf(" %c", &mode);
    
    if (mode == 'm' || mode == 'M') {
        Count = ManualInput(info);
    } 
    else if (mode == 'f' || mode == 'F') {
        Count = FileInput(info);
    } 
    else {
        Count = AddInfo(info);
    }
	
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
