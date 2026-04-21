all:main_ex2

main_ex2: main_ex2.o max_ex2.o
	gcc -o main_ex2.exe main_ex2.o max_ex2.o 

main_ex2.o: main_ex2.c
	gcc -c -o main_ex2.o main_ex2.c

max_ex2.o: max_ex2.c
	gcc -c -o max_ex2.o max_ex2.c

clean:
	del *.o
	del main_ex2.exe
