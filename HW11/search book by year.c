/*
 План:
 1. Объявим новую функцию `find_books_by_year`, которая будет принимать:
    - массив структур Book (books)
    - количество книг в массиве (total_books)
    - год, по которому ищем (year_to_find)

 2. Внутри функции пройдемся по всем книгам и проверим, совпадает ли год книги с искомым годом.

 3. Если совпадает, выведем книгу с помощью функции `print_book`.

 4. Если ни одной книги не найдено, выведем сообщение об этом.

 5. В функции `main` добавим вызов этой функции для демонстрации

 */


#include <stdio.h>
#include <string.h>

struct Book {
	char title [100];
	char author [50];
	int year;
	float price;
};

void print_book(struct Book *b_1)
{
	printf("Book: %-30s | Author: %-20s | Year %d | Price: $%.2f\n",
	b_1 -> title, 
	b_1 -> author, 
	b_1 -> year, 
	b_1 -> price);
	
	
}

void find_books_by_year(struct Book books[], int total_books, int year_to_find)
{
	printf("\nFind books by year: %d\n", year_to_find);
	int found = 0; //сюда заносим сколько найдем
	
	//перебираем года в нашей базе и сравниваем с искомым годом
	for(int i =0; i<total_books; i++){
		if(books[i].year == year_to_find){
			print_book(&books[i]);
			found ++;
		}
	}
	if (found == 0){
		printf("there is no book: %d", year_to_find);
	}
	
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
	for (int i =0; i<3; i++){
		print_book(&books[i]);
	} 
	//~ print_book(&books[2]);   //альтернатива
	
	//поиск по году. вызов
	find_books_by_year(books, 3, 1925);
	
	return 0;
}
