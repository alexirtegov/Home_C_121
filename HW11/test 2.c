/*

Создайте массив из 3 книг (struct Book books[3]).
Инициализируйте их вручную (как Book_one и Book_two).
Напишите цикл, который выводит информацию о всех книгах через print_book().
Используйте указатель для изменения данных одной из книг.

 */


#include <stdio.h>
#include <string.h>

struct Book {
	char title [100];
	char author [50];
	int year;
	float price;
};

void print_book(struct Book *b)
{
	printf("Book: %-30s | Author: %-20s | Year %d | Price: $%.2f\n",
	b->title,
	b->author,
	b->year,
	b->price);
}

int main(int argc, char **argv)
{
	//создаем массив где в каждой ячейке памяти будет структура
	struct Book books[3];
	
	//Инициализация по элементам
	strcpy(books[0].title, "The C Programming Language");
	strcpy(books[0].author, "K&R");
	books[0].year = 1978;
	books[0].price = 29.99;
	
	//инициализируем при объявлении
	struct Book temp = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99};
	books[1] = temp;
	
	
	//Инициализация по элементам
	strcpy(books[2].title, "1984");
    strcpy(books[2].author, "George Orwell");
    books[2].year = 1949;
    books[2].price = 9.99;

	//вывод книг через цикл
	printf("Original books:\n"); 
	for(int i =0; i<3; i++){
	print_book(&books[i]); // Правильный вызов функции
	}


	
	
	//работа с указателями
	struct Book *ptr = &books[1];
	ptr->year = 2025;
	ptr ->price = 50;
	
	printf("\nAfter modification:\n");

    
	
	return 0;
}
