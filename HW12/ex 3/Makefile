all:main_ex3.exe

main_ex3.exe: main_ex3.o max_ex3.o
	gcc -o main_ex3.exe main_ex3.o max_ex3.o 

main_ex3.o: main_ex3.c max_ex3.h
	gcc -c -o main_ex3.o main_ex3.c

max_ex3.o: max_ex3.c max_ex3.h
	gcc -c -o max_ex3.o max_ex3.c

clean:
	del *.o
	del main_ex3.exe
