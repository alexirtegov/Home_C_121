/*
🔹 Шаг 3: Функция добавления студента

Задача: Создать функцию AddStudent для добавления студентов в массив.

Изменения:
Пишем функцию:
void AddStudent(struct student* course, int number, char* surname, char* name, int age).
Она копирует данные в массив course на позицию number.
В main добавляем студентов через эту функцию.
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
//ШАГ3
void AddStudent(struct student course[], int number, char* surname, char* name, int age)
{
	strcpy(course[number].surname, surname);
	strcpy(course[number].name, name);
	course[number].age = age;
}


//ШАГ 2
void print(struct student* course, int count)
{
	for(int i = 0; i<count; i++){
	printf("Surname: %-10s name: %-10s %d\n", course[i].surname, course[i].name, course[i].age);
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
	   
	   //~ // Добавляем первого студента
	//~ course[count++] = (struct student){"Ivanov", "Ivan", 18};
	
	  //~ // Добавляем второго студента
	//~ course[count++] = (struct student){"Sidorov", "Dima", 16};

    //ШАГ 3
    AddStudent(course, count++, "Ivanov", "Ivan", 18);
    AddStudent(course, count++, "Sidorov", "Dima", 16);
    AddStudent(course, count++, "Petrov", "Petr", 19);
    AddStudent(course, count++, "Sidorov", "Nikita", 20);
    
	print(course, count);
	
	return 0;
}
