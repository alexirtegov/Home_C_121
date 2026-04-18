/*
✏️ Задание 1: Создайте свою первую структуру
Задача:
Создайте структуру Book с полями:

title (строка 100 символов)
author (строка 50 символов)
year (целое число - год издания)
price (дробное число - цена)

В функции main:
Объявите переменную типа Book
Присвойте значения полям (например: "The C Programming Language", "K&R", 1978, 29.99)
Выведите информацию о книге в формате:
"[Название]" by [Автор] ([Год]), $[Цена]
Требование:
Используйте printf для вывода. Для строк используйте %s, для целых чисел %d, для дробных %.2f.
 */


#include <stdio.h>
#include <string.h>

struct Book {
	char title [100];
	char author [50];
	int year;
	float price;
};

int main(int argc, char **argv)
{
	//вариант 1 Поэлементное присваивание после объявления
	struct Book Book_one; 
		strcpy(Book_one.title, "The C Programming Language");
		strcpy(Book_one.author, "K&R");
		Book_one.year = 1978;
		Book_one.price = 29.99;
	
	printf("Book name: %s, author: %s, year: %d, price: %.2f\n", Book_one.title, Book_one.author, Book_one.year, Book_one.price);
	
	//вариант 2 инициализация при объявлении
	struct Book Book_two = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99};
	printf("Book name: %s, author: %s, year: %d, price: %.2f\n", Book_two.title, Book_two.author, Book_two.year, Book_two.price);
	
	
	
	return 0;
}
