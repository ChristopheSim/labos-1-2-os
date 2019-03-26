# labos-1-2-os
This project contains two ways to use parralel programming with a Linux operating systems:
	- Processes
	- Threads
## The subject
The aim of the project is to compute the number of letters in a text file and render a frequency table (with the occurency of each letter).
That kind of algorithm can be used to compress the file with for example the Huffman coding.

## To compile the threads part
The following commands are requested.
1. To compile
```
	gcc -pthread -o example.exe example.c
```

1. To launch
```
	./example.exe
```

## To compile the processes part
With the *makefile* in the processes part, you can use the following command to compile the project:
```
	make
```
When you are run this command use :
```
	make clean
```
for cleaning the folder (remove the .o files).

When you are run the commands, you can execute *processes.exe* with
```
	./processes.exe
```