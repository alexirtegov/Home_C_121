/*
 Шаг 2: Добавляем массив студентов и функцию печати
Задача: Реализовать массив студентов и функцию print для вывода всех.
Изменения:

Добавляем константу STUDENT_NUMBER (например, 200).
Создаём массив course из структур student.
Пишем функцию void print(struct student* course, int number), 
которая выводит всех студентов.
Заполняем 2-3 студентов вручную в main.
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define STR_SIZE 30
#define STUDENT_NUMBER 200

struct student{
	char surname[STR_SIZE];
	char name [STR_SIZE];
	uint8_t age;
};

//ШАГ 2
void print(struct student course[], int count)
{
	for(int i = 0; i<count; i++){
	printf("%s %s %d\n", course[i].surname, course[i].name, course[i].age);
	}
}



int main(int argc, char **argv)
{
	//~ struct student s = {"Ivanov", "Ivan", 18};
	
	//~ strcpy(s.surname, "Ivanov");
	//~ strcpy(s.name, "Ivan");
	//~ s.age = 18;
	
	//~ printf("%s %s %d\n", s.surname, s.name, s.age);
	
	//ШАГ 2
	struct student course [STUDENT_NUMBER];
	int count = 0;
	   
	   // Добавляем первого студента
	course[count++] = (struct student){"Ivanov", "Ivan", 18};
	
	  // Добавляем второго студента
	course[count++] = (struct student){"Sidorov", "Dima", 16};

    
	print(course, count);
	
	return 0;
}
