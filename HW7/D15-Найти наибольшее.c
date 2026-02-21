/*
D15-Найти наибольшее


Дана последовательность ненулевых целых чисел, завершающаяся числом 0. Ноль в последовательность не входит. 
Определите наибольшее значение числа в этой последовательности. Для решения задачи необходимо написать рекурсивную функцию вида:
int max_find(int max)

Input format
Последовательность не нулевых целых чисел. В конце последовательности число 0.

Output format
Одно число. Максимум последовательности.


Input
1 12 2 5 8 0
Output
12
 */


//вариант 2 рекурсия

#include <stdio.h>

int max_find(int CUR_max) // сюда мы передали x например 12
{
	int x;
	
	if (scanf("%d ", &x)!=1){
			printf("Error");
			return 1;
		}
	
		
		
	if (x == 0) {
        
        return CUR_max;
    }
	
	if (x>CUR_max){
			CUR_max=x;
		}
		
		return max_find(CUR_max);
	}
		

int main(int argc, char **argv)
{
	
	int x;
	
	if (scanf("%d ", &x)!=1){
			printf("Error");
			return 1;
		}
		
	int max = max_find(x);
		
	printf ("%d", max);
	return 0;
}











//вариант1 через цикл

//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	
	//~ int x;
	
	//~ if (scanf("%d ", &x)!=1){
			//~ printf("Error");
			//~ return 1;
		//~ }
		
	//~ if (x == 0) {
        //~ printf("Error");
        //~ return 1;
    //~ }
	
	//~ int max = x;
	
	//~ while(x!=0){
		//~ if (x>max){
			//~ max=x;
		//~ }
		
		//~ if (scanf("%d ", &x)!=1){
			//~ printf("Error");
			//~ return 1;
		//~ }
	//~ }
		
	//~ printf ("%d", max);
	//~ return 0;
//~ }
