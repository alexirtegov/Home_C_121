/*
 * 
Создайте массив из 3 книг (struct Book books[3]).
Инициализируйте их вручную (как Book_one и Book_two).
Напишите цикл, который выводит информацию о всех книгах через print_book().
Используйте указатель для изменения данных одной из книг.


ДОБАВИМ ПОИСК ПО АВТОРУ

Мы работаем с массивом структур. Каждая структура представляет книгу и содержит поля: title, author, year, price.
 Нам нужно найти все книги в массиве, у которых автор совпадает с заданным (например, "F. Scott Fitzgerald").

 Для этого мы создаем функцию find_books_by_author. Она принимает:
  1. Указатель на массив структур Book (struct Book *books) - это начало массива.
  2. Количество элементов в массиве (int count) - чтобы знать, сколько книг перебрать.
  3. Строку с именем автора (const char *search_author) - это то, что мы ищем.

 Внутри функции:
  - Мы перебираем все книги от 0 до count-1.
  - Для каждой книги сравниваем поле author с переданной строкой search_author.
  - Если они совпадают (без учета регистра), то выводим эту книгу.

 В вызове функции:
   find_books_by_author(books, 3, "F. Scott Fitzgerald");
   - books: это имя массива, которое автоматически преобразуется в указатель на первый элемент.
   - 3: размер массива (у нас 3 книги).
   - "F. Scott Fitzgerald": строка, которую мы ищем.
 Почему мы передаем массив как указатель? 
 Потому что в C имя массива в выражениях 
 (кроме оператора sizeof) превращается в указатель на первый элемент.
 
 
 1. Объявляем функцию:
      void find_books_by_author(struct Book *books, int count, const char *search_author)

 2. Внутри:
      printf("\nSearching for books by \"%s\":\n", search_author);
      int found = 0;   // флаг, найдена ли хотя бы одна книга

 3. Цикл по всем книгам:
      for(int i = 0; i < count; i++) {

 4. Сравниваем автора текущей книги (books[i].author) с искомым автором (search_author):
        if(strcasecmp(books[i].author, search_author) == 0) {

 5. Если совпали, вызываем функцию print_book (которая у нас уже есть) для вывода книги и устанавливаем флаг found в 1.

 6. После цикла проверяем, был ли найден хоть один автор:
        if(!found) {
            printf("No books found for author \"%s\"\n", search_author);
        }
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

//поиск книги по автору
void find_books_by_author(struct Book books[], int total_books, char author_to_find[])
{
	printf("\nfind book by author: %s\n", author_to_find);
	int found =0; // счетчик найденных книг
	
	for(int i =0; i<total_books; i++){
		int match = 1;  //предпологаем что авторы совпадают
		int j = 0;
		
		//пока не конец строки автора в книге и не конец искомого автора
		while (books[i].author[j] != '\0' && author_to_find[j] != '\0'){
			//сравниваем символы
			char ch1 = books[i].author[j];
			char ch2 = author_to_find[j];
			
			if(ch1 != ch2){
				match = 0; //не совпали
				printf("No such book");
				break;
			}
			j++;
		}

		
		if(match == 1){
			print_book(&books[i]);
			found ++;
		}
		//~ if (found == 0) {
        //~ printf("No such book\n");
		//~ }
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
	for(int i =0; i<3; i++){
		print_book(&books[i]); // Правильный вызов функции
	}
	
	//работа с указателями
	struct Book *ptr = &books[1];
	ptr->year = 2025;
	ptr ->price = 50;
	
	printf("\nAfter modification:\n");
    print_book(ptr); // Проверяем изменения можно print_book(&books[1])
    
        // Поиск книг по автору
    //~ find_books_by_author(books, 3, "F. Scott Fitzgerald");
    
    //~ find_books_by_author(books, 3, "George Orwell");
    find_books_by_author(books, 3, "J.K. Rowling");  // Несуществующий автор
	
	return 0;
}
