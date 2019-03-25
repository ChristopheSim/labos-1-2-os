all: lab

lab: main.o thread.o
	gcc -o app.exe main.o thread.o -lpthread

main.o: main.c
	gcc -o main.o -c main.c

thread.o: thread.c thread.h
	gcc -o thread.o -c thread.c

clean:
	rm -rf app.exe
	rm -rf *.o
