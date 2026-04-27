/*
Первый вызов: enqueue_recurs(&pq, data1);

*pl это pq, сейчас там NULL, выделяем память под первый элемент, например по адресу 100.
В поле pq запишется адрес 100.

pq
 |
 v
+----------------------+
| data1 | next = NULL  |  (адрес 100)
+----------------------+

Второй вызов: enqueue_recurs(&pq, data2);
*pl это pq, теперь там хранится адрес 100 (то есть первый элемент).
*pl != NULL, поэтому рекурсивно вызываем: enqueue_recurs(&((*pl)->next), data2)
(*pl)->next — это поле next у первого элемента (адрес 100). Там сейчас NULL.
Выделяем память под второй элемент, пусть адрес 200. В [100]->next кладём 200.
pq
 |
 v
+----------------+     +------------------+
| data1 | 200 ---+---> | data2 | next=NULL|  (адрес 100, адрес 200)
+----------------+     +------------------+

Третий вызов: enqueue_recurs(&pq, data3);
*pl = pq (адрес 100, первый элемент), *pl != NULL, рекурсивно:
enqueue_recurs(&((*pl)->next), data3)
(*pl)->next (у второго элемента) = NULL.
Выделяем память под третий элемент, пусть адрес 300.
В [200]->next кладём 300.

pq
 |(100)
 v
+----------------+     +----------------+     +------------------+
| data1 | 200 ---+---> | data2 | 300 ---+---> | data3 | next=NULL|
+----------------+     +----------------+     +------------------+
   (100)                (200)                   (300)

Вот важный момент:
*pl — это первый элемент (struct list *), скажем, по адресу 100.
(*pl)->next — это поле в первом элементе (значение — адрес второго элемента, например, 200).
&((*pl)->next) — это адрес поля next в первом узле.

pq (0x100) -> [1|*->0x200] -> [2|*->0x300] -> [3|*->0x400] -> [4|*->0x500] -> [5|NULL]
*/


#include <stdio.h>
#include <stdlib.h>

struct list
{
    int value; //поле для данный
    struct list *next; //указатель типа структура
};

_Bool empty_queue(struct list *p)
{
    return p == NULL;
}

int dequeue(struct list **p)
{
    struct list *ptmp = *p;
    int c;
    if (empty_queue(*p))
    { // Попытка взять из пустой очереди
        fprintf(stderr, "Error. Queue is empty\n");
        exit(1);
    }
    c = ptmp->value;
    *p = ptmp->next;//теперь pq будет указывать на следующий после первого
    free(ptmp);	//Теперь первый элемент уничтожен, pq теперь указывает на второй элемент списка
    return c;
}

void enqueue(struct list **pl, int data) //итеративный подход (через цикл while).
{
    struct list *ptmp = *pl,//ptmp = pq 
                *elem;
    elem = malloc(sizeof(struct list));
    elem->value = data;
    elem->next = NULL;
    if (*pl == NULL) //сюда попадаем только первый раз
    {
        *pl = elem;
        return; // <--- ВЫХОД ИЗ ФУНКЦИИ!
    }
    while (ptmp->next!=NULL){
        ptmp = ptmp->next;
	}
	
    ptmp->next = elem;
}

void enqueue_recurs(struct list **pl, int data) //рекурсивный подход (когда функция вызывает саму себя для перебора списка до конца).
{
    if (*pl == NULL) //перенаправили pq через разыменование (*pl) = malloc(sizeof(struct list)); на подходящую для хранения структуры память 
    {
        (*pl) = malloc(sizeof(struct list)); 
        (*pl)->value = data;
        (*pl)->next = NULL;
        return;  
    }
    else 
    {
        enqueue_recurs(&((*pl)->next), data); //Переходим в else, вложенный вызов: рекурсивно вызываем enqueue_recurs(&((*pl)->next), 2);
    }
}

void print_list(struct list *pl)
{
    while (pl)
    {
        printf("%d ", pl->value);
        pl = pl->next;
    }
    printf("\n");
}

int main()
{
    struct list *pq = NULL; //указатель на структуру с тэгом list. Указатель содержит адрес NULL
    
    for (int i = 1; i <= 5; i++)
        enqueue(&pq, i); //передаем в функцию адрес нашего указателя &pq на начало списка и копию данных i

    for (int i = 1; i <= 5; i++)
        printf("%d\n", dequeue(&pq));
    return 0;
}
