/*
### Макросы:
1. `#define ONE printf ("DEBUG\n")`
   - Определяет макрос `ONE`, который заменяется на `printf("DEBUG\n")`.

2. `#define TWO ONE; ONE`
   - Определяет макрос `TWO`, который заменяется на `ONE; ONE`. 
   - После подстановки `ONE` получим: `printf("DEBUG\n"); printf("DEBUG\n");`.

3. `#define FOUR TWO; TWO`
   - Определяет макрос `FOUR`, который заменяется на `TWO; TWO`.
   - Подставляем `TWO` и получаем: `printf("DEBUG\n"); printf("DEBUG\n");; printf("DEBUG\n"); printf("DEBUG\n");`.
   - Обратите внимание на лишнюю точку с запятой (две подряд). Однако в C это допустимо (пустой оператор).
   
### Что происходит при раскрытии макросов?
1. Сначала препроцессор заменит `FOUR` на `TWO; TWO`.
2. Затем каждое `TWO` заменится на `ONE; ONE`.
3. Затем каждое `ONE` заменится на `printf("DEBUG\n")`.

Таким образом, строка `FOUR;` превратится в:
```c
printf("DEBUG\n"); printf("DEBUG\n");; printf("DEBUG\n"); printf("DEBUG\n");
 */


#include <stdio.h>

#define ONE printf ("DEBUG\n")
#define TWO ONE; ONE
#define FOUR TWO; TWO

int main(void) {
    FOUR;  // Раскрывается в: 
           //   TWO; TWO 
           //   → (ONE; ONE); (ONE; ONE)
           //   → printf("DEBUG\n"); printf("DEBUG\n"); printf("DEBUG\n"); printf("DEBUG\n");
    return 0;
}
