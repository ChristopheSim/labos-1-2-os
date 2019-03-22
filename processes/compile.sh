#!/bin/bash

gcc -o processes.exe main.c ./src/config.c ./src/sort_frequencies.c ./src/size_file.c 
./processes.exe