/*
🔹 Шаг 5: Подсчёт студентов по имени
Задача: Функция SameNameNumber, которая считает студентов с заданным именем.
Изменения:

Функция: int SameNameNumber(struct student* course, int number, char* name).
Использует strcmp для сравнения имён.
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
void print(struct student course[], int count)
{
	for(int i = 0; i<count; i++){
	printf("Surname: %-10s name: %-10s %d\n", course[i].surname, course[i].name, course[i].age);
	}
}

//ШАГ 4
int Eldest(struct student course[], int number)
{
	int max = course[0].age; //принимаем за максимум Ивана 18 лет
	
	for (int i = 1; i < number; i++) {
		if(course[i].age> max){
			max = course[i].age;
		}
	}
	return max;
} //если мы хотим вывести всего студента, то мы должны запомнить индекс структуры из массива струтур

// Измененная функция: возвращает индекс старшего студента
int Eldest2(struct student course[], int number) {
    int max_index = 0;
    for (int i = 1; i < number; i++) {
        if(course[i].age > course[max_index].age) {
            max_index = i;
        }
    }
    return max_index;
}

//ШАГ 5
int SameNameNumber(struct student course[], int number, char* name){ //На каждом шаге цикла функция берет имя текущего студента course[i].name и сравнивает его с переданным именем name (то есть с "Ivan").
	int counter = 0;
	for(int i = 0; i<number; i++){
		if(strcmp(course[i].name, name) == 0){
		counter++;
		}
	}
	return counter;
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
	
	//ШАГ 4
	printf("\nEldest student = %d\n", Eldest(course, count));
	    // Получаем индекс старшего студента
    int eldest_index = Eldest2(course, count);
	printf("Surname: %s\nName: %s\nAge: %d\n", 
           course[eldest_index].surname, 
           course[eldest_index].name, 
           course[eldest_index].age);
	
	//ШАГ5
	char* name = "Ivan";
	printf("\nName %s number = %d\n", name, SameNameNumber(course, count, name));
	
	return 0;
}
