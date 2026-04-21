
all:main.exe

main.exe: main.o square.o even_check.o 
	gcc -o main.exe main.o square.o even_check.o

main.o: main.c math_operations.h io_operations.h
	gcc -c -o main.o main.c

square.o: square.c math_operations.h
	gcc -c -o square.o square.c

even_check.o: even_check.c io_operations.h
	gcc -c -o even_check.o even_check.c
	
	

clean:
	del *.o
	del main.exe
