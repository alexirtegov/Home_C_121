/*
D14-Печать все нечетные


Дана последовательность целых чисел через пробел, завершающаяся числом 0. Выведите все нечетные числа из этой последовательности, сохраняя их порядок.

Input format
Последовательность не нулевых целых чисел. В конце число 0.

Output format
Введенная последовательность, кроме четных чисел в том же порядке. Число 0 не выводить.


Input
12 13 173 28 19 0
Output
13 173 19
 */


//вариант2 через рекурсию

#include <stdio.h>
void print_rec(void){
	
	int number;
	
	if (scanf("%d", &number)!=1){
			printf("Error");
			return;
		}
		
		if(number==0){
			return;
		}
	
			if(number%2!=0){
			printf("%d ", number);
		}
		
		print_rec();
		
		
		
	}
	


int main(int argc, char **argv)
{
	print_rec();
	return 0;
}





//вариант1 через цикл

//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	
	//~ int number;
	
	//~ if (scanf("%d", &number)!=1){
			//~ printf("Error");
			//~ return 1;
		//~ }
	
	//~ while(number!=0){
		
		
		//~ if(number%2!=0){
			//~ printf("%d ", number);
		//~ }
		
		//~ if (scanf("%d", &number)!=1){
			//~ printf("Error");
			//~ return 1;
		//~ }
		
		
	//~ }
	
	
	//~ return 0;
//~ }
