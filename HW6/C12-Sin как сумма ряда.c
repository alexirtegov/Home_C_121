/*
C12-Sin как сумма ряда

Вычислить sin
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
float sinus(float x)

Input format
Одно число от 0 до 90

Output format
Вещественное число в формате "%.3f"


Input
45
Output
0.707
 */


#include <stdio.h>

/* Задаём требуемую точность */
#define EPS 0.001f

/* Функция для вычисления синуса через ряд Тейлора */
float sinus(float x_deg) {
    /* 1. Переводим угол из градусов в радианы */
    const float PI = 3.14159265358979323846f;
    float x = x_deg * PI / 180.0f;

    /* 2. Начальное значение первого члена ряда и суммы */
    float term = x;   /* первый член = x^(2*0+1) / (2*0+1)! = x */
    float sum  = term;

    /* 3. Будем на каждом шаге получать следующий член через
       отношение с предыдущим: 
       term_next = - term * x^2 / ((2n)*(2n+1)),
       где n — номер шага (начинаем с n=1) */
    int n = 1;
    while (term > EPS || term < -EPS) {
        term = -term * x * x / ( (2*n) * (2*n + 1) );
        sum += term;
        n++;
    }

    return sum;
}

int main(void) {
    float angle;
    /* Считываем угол в градусах */
    if (scanf("%f", &angle) != 1) {
        printf("Error input\n");
        return 1;
    }

    /* Печатаем синус с тремя знаками после точки */
    printf("%.3f\n", sinus(angle));
    return 0;
}
