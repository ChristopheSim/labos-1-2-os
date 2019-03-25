all : processes.exe

processes.exe: main.o config.o sort_frequencies.o size_file.o count_letters.o
	gcc -o processes.exe main.o config.o sort_frequencies.o size_file.o count_letters.o

config.o: ./src/config.c ./src/config.h
	gcc -o config.o -c ./src/config.c

sort_frequencies.o: ./src/sort_frequencies.c ./src/functions.h ./src/config.h
	gcc -o sort_frequencies.o -c ./src/sort_frequencies.c

size_file.o: ./src/size_file.c ./src/functions.h ./src/config.h
	gcc -o size_file.o -c ./src/size_file.c

count_letters.o: ./src/count_letters.c ./src/functions.h ./src/config.h
	gcc -o count_letters.o -c ./src/count_letters.c

main.o: main.c ./src/functions.h ./src/config.h
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
