/*

main.c              # Главная программа
math_operations.h   # Объявления математических функций
io_operations.h     # реализация функции  check
square.c            # Реализация квадрата числа
even_check.c        # Реализация проверки на четность
 */


#include <stdio.h>

#include "math_operations.h" //реализация функции square(number) и print_square(number, sq)
//~ int square(int number)
//~ {
	//~ return number*number;
//~ }

//~ void print_square(int number, int sq)
//~ {
	//~ printf("Square of %d is %d\n", number, sq);
//~ }


#include "io_operations.h" //реализация функции  check_even(number) и 
//~ void check_even(int number)
//~ {
	//~ if(number%2 == 0){
		//~ printf("%d is even\n", number);
	//~ } else {
		//~ printf("%d is odd\n", number);
	//~ }
//~ }


int main() {
    int number;
    printf("please input the number: ");
    scanf("%d", &number);
    
    // Вычисляем квадрат
    int sq = square(number);
    print_square(number, sq);
    
    // Проверяем четность
    check_even(number);
    
    return 0;
}
