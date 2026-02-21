/*
D16-Точная степень двойки


Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)

Input format
Одно натуральное число.

Output format
YES или NO


Input
8
Output
YES
 */


//вариант через рекурсию

#include <stdio.h>

int is2pow(int n)
{
	if(n==1){
		return 1;
		}
		
		if(n%2!=0){
			return 0;
		}
		
		return is2pow(n/2);
}


int main(int argc, char **argv)
{
	int number;

	if(scanf("%d", &number)!=1){
	printf("ERROR");
	return 1;
	}
	
	if (is2pow(number)){
	printf("YES");
	}else{
		printf("NO");
	}

	
	
	return 0;
}





//вариант 1 через цикл

//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	//~ int number;

	//~ if(scanf("%d", &number)!=1){
	//~ printf("ERROR");
	//~ return 1;
	//~ }
	
	//~ int N=number;
	//~ for(int A; N>1;){
		//~ A=N%2;
		//~ if(A!=0){
			//~ printf("NO");
			//~ return 0;
		//~ }
		//~ N=N/2;
	//~ }
	
		//~ printf("YES");
	
	
	//~ return 0;
//~ }
