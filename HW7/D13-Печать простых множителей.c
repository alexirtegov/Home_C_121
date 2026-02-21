/*
D13-Печать простых множителей

Составить рекурсивную функцию, печать всех простых множителей числа.

Input format
Натуральное число

Output format
Последовательность из всех простых делителей числа через пробел


Input
12
Output
2 2 3

Input
120
Output
2 2 2 3 5
 */


#include <stdio.h>

void print_simple(int n, int i, int first)
{
    if (n <= 1) return;

    if (n % i == 0) {
        if (!first) printf(" ");
        printf("%d", i);
        print_simple(n / i, i, 0);
    } else {
        print_simple(n, i + 1, first);
    }
}

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1 || N < 1) return 1;  // натуральное: от 1

    if (N > 1) print_simple(N, 2, 1);            // для 1 ничего не печатаем
    printf("\n");
    return 0;
}

//вариант 2 обычный
//~ #include <stdio.h>

//~ void print_simple(int n){
    //~ // Проходим по потенциальным простым делителям от 2 до n
    //~ for (int i = 2; i <= n; i++) {
        //~ // Пока i — делитель n, выводим i и уменьшаем n
        //~ while (n % i == 0) { 
            //~ printf("%d ", i);
            //~ n /= i;
        //~ }
    //~ }
	
//~ }

//~ int main()
//~ {
	//~ int N;
	//~ if(scanf("%d", &N)!=1){
		//~ printf("Error input");
		//~ return 1;
	//~ }
	
	//~ print_simple(N);
	
	//~ return 0;
//~ }
