/*
D20-Возвести в степень

Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.

int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Input format
Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100

Output format
Одно целое число n в степени p


Input
2 3
Output
8
 */


//вариант 2 через рекурсию

#include <stdio.h>

int recurs_power(int n, int p) { //2  3
    if (p == 0) {
       
        return 1;
    }
   
    return n * recurs_power(n, p - 1); //2* (2, 2)=2*4=8 //2*(2,1)=2*2=4 // 2*(2,0)=2*1=2
}



int main(int argc, char **argv)
{
	int n, p;
	
	if(scanf ("%d %d", &n, &p)!=2){
		printf("Error");
		return 1;
	}
	
	if (n<-100 || n>100){
		printf("wronng input -100 <= n <= 100 and 0 <= p <= 100");
		return 0;
	}
	
	if (p<0 || p>100){
		printf("wronng input -100 <= n <= 100 and 0 <= p <= 100");
		return 0;
	}
	
	
	int result = recurs_power(n, p);
	printf("%d", result);
	
	return 0;
}







//вариант 1 через цикл

//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	//~ int n, p;
	
	//~ if(scanf ("%d %d", &n, &p)!=2){
		//~ printf("Error");
		//~ return 1;
	//~ }
	//~ int res = 1;
	//~ for(;p>=1; p--){//2^3 =2*2 n=4 p=2, 4*2 n=8 p=1
		//~ res*=n;
	//~ }
	
	//~ printf("%d", res);
	
	//~ return 0;
//~ }
