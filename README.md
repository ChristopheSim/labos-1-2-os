# labos-1-2-os
This repository contains two projects.
This repository is a work about parallel programming with a Linux operating systems:
- Processes
- Threads

## The subject
The aim of the project is to compute the number of letters in a text file and render a frequency table (with the occurency of each letter).

## Compile the projects
There is a *makefile* in each project.
To compile each projects, you need to run `make` in each specific folder.

## Clean the projects
You must run `make clean` in each specific folder to clean the projects.

## Run projects
To run a project, you need to run the executable file from the specific folder.

To execute test on the projects, you can use these two lines:
```
sudo time -v ./app.exe
```
```
sudo perf stat -d ./app.exe
```

We also create a *bash file* `run.sh` in each folder who compile and run the project.
To execute the *bash file* you need to make them executable with the command:
```
sudo chmod +x run.sh
```
