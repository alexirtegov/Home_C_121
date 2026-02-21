/*
D3-В обратном порядке

В обратном порядке
Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.

Input format
Одно не отрицательное целое число

Output format
Последовательность цифр введенного числа в обратном порядке через пробел


Input
15
Output
5 1
 */


#include <stdio.h>

void reverse_the_number(int N)
{ 
	
if(N==0){
	return;
}

printf("%d ", N%10);

reverse_the_number(N/10);


}

/*
Пояснение работы на примере N=1234:

print_digits_rev(1234)
— печатает 1234 % 10 = 4,
— вызывает print_digits_rev(123)
print_digits_rev(123)
— печатает 3, вызывает print_digits_rev(12)
print_digits_rev(12)
— печатает 2, вызывает print_digits_rev(1)
print_digits_rev(1)
— печатает 1, вызывает print_digits_rev(0)
print_digits_rev(0)
— базовый случай, сразу возвращается, и цепочка вызовов разворачивается.
Вывод в итоге:
4 3 2 1
*/


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
