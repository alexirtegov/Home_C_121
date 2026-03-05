// 1. Сообщаем компилятору о существовании функций ядра Windows.
// Они нужны, чтобы получить доступ к экрану терминала напрямую.
void* __attribute__((stdcall)) GetStdHandle(unsigned long nStdHandle);
int __attribute__((stdcall)) WriteConsoleA(void* hConsoleOutput, const void* lpBuffer, 
                  unsigned long nNumberOfCharsToWrite, unsigned long* lpNumberOfCharsWritten, 
                  void* lpReserved);

// 2. Пишем НАШУ СОБСТВЕННУЮ логику вывода числа, подобно printf
int my_printf(const char *format, int number) {
    // Задача: превратить числовое значение (например, 15) в текст ('1' и '5')
    char buffer[20];
    int length = 0;
    
    // Переводим математическое число в символы
    int temp = number;
    while (temp > 0) {
        // Берем последнюю цифру (например от 15: 15 % 10 = 5) 
        // и прибавляем код символа '0', чтобы получить символ '5'
        buffer[length] = (temp % 10) + '0'; 
        temp = temp / 10;                     
        length++;
    }
    
    // Поскольку мы доставали цифры с конца, число "15" записалось как "51"
    // Нам нужно перевернуть строку в правильный порядок
    char final_text[20];
    for (int i = 0; i < length; i++) {
        final_text[i] = buffer[length - 1 - i];
    }
    
    // 3. Обращаемся к самой операционной системе Windows для отрисовки текста
    // -11 означает запрос доступа к "Экрану вывода" (STD_OUTPUT_HANDLE)
    void* console = GetStdHandle((unsigned long)-11); 
    
    unsigned long charsWritten = 0;
    // Печатаем наш final_text на экран
    WriteConsoleA(console, final_text, length, &charsWritten, 0);
    
    return length;
}

// 3. Запускаем вашу программу
int main(void) {
    int a = 15; 
    
    // Вызываем нашу собственную логику, а не системную
    my_printf("%d", a); 
    
    return 0;
}
