/*
C7-Число N в P-ую систему

Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.

Input format
Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

Output format
Одно целое число


Input
25 5
Output
100
 */


#include <stdio.h>

int to_base(int N, int P) {
    // Особый случай: если N = 0, сразу возвращаем 0
    if (N == 0) {
        return 0;
    }

    int result = 0;   // сюда будем собирать переведённое число
    int place  = 1;   // текущий разряд (1, 10, 100, ...)

    // Пока в N есть цифры в десятичном представлении
   
 /*
 допустим N=10 P=2 - это 1010
 
 иттерация №1:
 10%2 =0 digit = 0
 result += digit*place = 0+0*1 =0
 N=N/P = 10/2 = 5
 place = place * 10 = 1*10 = 10
 
  иттерация №2:
  5%2 =0 digit = 1
  result += digit*place = 0+1*10 =10
  N=N/P = 5/2 = 2
  place = place * 10 = 10*10 = 100
   
   иттерация №3:
   2%2 =0 digit = 0
   result += digit*place = 10+0*100 =10
   N=N/P = 2/2 = 1
   place = place * 10 = 100*10 = 1000 
    
     иттерация №3:
     1%2 =1 digit = 1
     result += digit*place = 10+1*1000 =1010
     N=N/P = 1/2 = 0 выходим
     place = place * 10 = 1000*10 = 10000
 
 
 */
    while (N > 0) {
        int digit = N % P;    // последняя цифра в системе P
        result  += digit * place; // помещаем её в нужный десятичный разряд
        N       /= P;         // «списываем» эту цифру из N
        place   *= 10;        // переходим к следующему «десятичному» разряду
    }

    return result;
}

                 
int main(int argc, char **argv)
{
	int N, P;
	
	// читаем два числа: N (>= 0) и P (2 ≤ P ≤ 9)
    if (scanf("%d %d", &N, &P) != 2) {
        printf("Input error\n");
        return 1;
    }
   
    // проверяем ограничения задачи
    if (N < 0 || P < 2 || P > 9) {
        printf("Constraints violated: N >= 0 and 2 <= P <= 9\n");
        return 1;
    }
    
      // вызываем функцию
    int converted = to_base(N, P);
    printf("%d\n", converted);  
    	
	return 0;
}

