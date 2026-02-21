/*
D4-В прямом порядке

В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
void print_num(int num)

Input format
Одно целое неотрицательное число

Output format
Все цифры числа через пробел в прямом порядке.


Input
15
Output
1 5
 */


#include <stdio.h>

void reverse_the_number(int N)
{ 
	
if(N==0){
	return;
}



reverse_the_number(N/10);
printf("%d ", N%10);

}


int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	if (number == 0) {
        printf("0\n");
     }else{
		 reverse_the_number(number);
		 printf("\n");
	 }
	
	return 0;
}
