/*
добавление узлов реализовано через функцию:

Ключевая таблица значений:
Переменная				Тип			Адрес в памяти			Значение			Что означает

head (main)			struct Node*		0x1000	        NULL (0x0000)			Указатель на первый узел

head_ref (func)		struct Node**		0x2000			0x1000					Указатель на указатель head

*head_ref			struct Node*		0x1000			NULL					Разыменование: доступ к head

**head_ref			truct Node	-	-	Двойное разыменование (пока не используется)
 
У нас есть head в функции main. Сейчас там лежит NULL.

У нас есть head_ref в функции add_node. В нем лежит адрес переменной head.

head_ref — это "адрес переменной head".
*head_ref — это команда "иди по адресу, который лежит в head_ref". Куда мы придем? Мы придем прямо в саму переменную head! 
**head_ref — это команда "иди по адресу, который лежит в head_ref (мы пришли в head), А ЗАТЕМ иди по тому адресу, который записан внутри head".
 А что записано внутри head? Там записано NULL.
 
 Если вы напишете **head_ref, то программа сделает два шага. Первый шаг приведет её к head. Из head она достанет NULL 
 и попытается сделать второй шаг — пойти по адресу NULL. 
 Это приведет к немедленному падению программы (Segmentation fault).
 
 Разыменовывать NULL нельзя. Если бы мы передали add_node(head, 10); То есть значение NULL, вместо адреса head
 тогда функция была бы такой void add_node(struct Node *head_ref, int data) { ....
 теперь head_ref содержит NULL, давая команду *head_ref - мы даем команду иди по адресу который записан внутри head_ref, а там NULL
 Прогрмма падает
 
 старый пример int a =5; int *x; x = &a; сейчас x содержит адрес a (не значение а, но адрес)
 *x = 10; мы даем команду иди внутрь, там находим адрес a, по которому меняем значение.
 */



#include <stdio.h>
#include <stdlib.h>

// Объявляем структуру узла
struct Node {
    int data;
    struct Node *next;
};

// Функция добавления нового узла в конец списка
//апись **head_ref предполагает, что указатель head_ref указывает на указатель head
//то есть переменная head_ref записала в себя адрес head
//Если адрес head был 0x1000, а адрес head_ref 0x2000, 
//то сама переменная head_ref инициализирована адресом 0x1000 и его содержит
//теперь разыменовывая head_ref мы меняем адрес куда смотрит head, то есть head остается на своем маесте по 0x1000, но смотреть будет туда куда укажем
// по сути рызымновывая head_ref мы смотри на тот же участок памяти, что и head. Поэтому если head_ref = new_node, то head = new_node;
void add_node(struct Node **head_ref, int data) { 
    struct Node* new_node = malloc(sizeof(struct Node)); //выделяем память на структуру и возвращаем указатель на нее, адрес записываем в указатель new_node 
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error!");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL; // Следующий узел не задан, так как это только что созданный узел

    // Если список пустой, новый узел становится головой -спаведливо в самом начале, когда узлов нет, а есть только head=NULL, дальше мы сюда не попадаем
    if (*head_ref == NULL) { //через разыменование мы смотрим куда смотрит head из main. Если NULL, тогда условие:
        *head_ref = new_node; //теперь head смотрит на новую выделенную область памяти, туда же, куда и new_node, то есть адрес, который записали в new_node, теперь через разыменование записали в head 
        return; //вышли из первого узла в main, вниз не спускаемся
    }

    // Ищем последний узел в списке  
    struct Node *current = *head_ref; // здесь *head_ref смотрит на прошлый узел. Когда мы создаем второй, *head_ref еще смотри на первый
    while (current->next != NULL) {		// current->next во время определения второго узла смотрит на NULL, поэтому сюда не попадаем
        current = current->next;	//это строка сработает, когда
    }

    // Присоединяем новый узел к концу списка
    current->next = new_node;			//а вот теперь мы вернулись в первый узел и подключили второй
    return;
}

// Главная функция
int main() {
    struct Node *head = NULL; // Инициализация пустого списка - 0x0000
    
    // Создаем и добавляем узлы через функции
    //head - указатель типа struct Node* , &head - берём адрес этого указателя
    add_node(&head, 10); // Первый узел
    add_node(&head, 20); // Второй узел, здесь мы отправляем адрес head- первого узла
    add_node(&head, 30); // Третий узел, здесь мы отправляем адрес head- первого узла
    
    // Выводим список
    printf("Output of list elements:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // Обновление указателя current
    }

    // Освобождаем память
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;  
}






/*

почему для этого вызова head = add_node(head, 10); функция struct Node* add_node(struct Node *head, int value), 
а для вызова add_node(&head, 10); функция void add_node(struct Node **head_ref, int data)? 

В первом случае в записи вызова head = add_node(head, 10) мы записью head передаем копию адреса, 
который записан внутри head? А в head записан адрес NULL?! 

Во втором случае в вызове add_node(&head, 10); 
мы передаем не содержимое head, а адрес, где head находится в памяти! 
Соответственно в функции void add_node(struct Node **head_ref, int data) 
запись **head_ref означает указатель на адрес?, соответственно когда мы разыменовываем head_ref мы меняем адрес куда смотрит head!


В первом вызове head = add_node(head, 10); вы передаете копию адреса, который хранится в head, и, если он равен NULL, 
функция создает новый узел и возвращает его адрес, который затем присваивается обратно в head.
Во втором вызове add_node(&head, 10); вы передаете адрес переменной head. 
Это позволяет функции изменять сам указатель head, так как head_ref указывает на head, и вы можете изменять, 
куда он указывает, непосредственно в функции, используя *head_ref.
*/

//~ #include <stdio.h>
//~ #include <stdlib.h>

//~ // Объявляем структуру узла
//~ struct Node
//~ {
    //~ int data;
    //~ struct Node *next;
//~ };

//~ // Функция добавления нового узла в конец списка
//~ struct Node* add_node(struct Node *head, int value) {
    //~ // Создаем новый узел
    //~ struct Node *new_node = malloc(sizeof(struct Node));
    //~ if (new_node == NULL) {
        //~ fprintf(stderr, "Memory allocation error!\n");
        //~ exit(1);
    //~ }
    //~ new_node->data = value;
    //~ new_node->next = NULL;
    
    //~ // Если список пустой, новый узел становится головой
    //~ if (head == NULL) {
        //~ return new_node;
    //~ }
    
    //~ // Ищем последний узел в списке
    //~ struct Node *current = head;
    //~ while (current->next != NULL) {
        //~ current = current->next;
    //~ }
    
    //~ // Присоединяем новый узел к концу списка
    //~ current->next = new_node;
    //~ return head;
//~ }

//~ int main()
//~ {
    //~ struct Node *head = NULL;  // Инициализация пустого списка
    
    //~ // Добавляем узлы через функцию
    //~ head = add_node(head, 10);  // Первый узел
    //~ add_node(head, 20);         // Второй узел
    //~ add_node(head, 30);         // Третий узел
    
    //~ // Выводим список
    //~ printf("Output of list elements:\n");
    //~ struct Node *current = head;
    //~ while (current != NULL) {
        //~ printf("%d ", current->data);
        //~ current = current->next;
    //~ }
    
    //~ // Освобождаем память
    //~ current = head;
    //~ while (current != NULL) {
        //~ struct Node *temp = current;
        //~ current = current->next;
        //~ free(temp);
    //~ }
    
    //~ return 0;
//~ }
