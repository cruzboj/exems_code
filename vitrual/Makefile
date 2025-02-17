FLAGS=-Wall -Werror
EXEC = prog
OBJS = virtual.h medicalStudent.h base.h
CC = g++

#only virtual.h medicalStudent.h a virtual class
run1: prog1
		./prog1

prog1: main.o
	g++ *.o -o prog1

main.o: main.cpp virtual.h medicalStudent.h
	g++ -c main.cpp


#only base.h a pure virtual class
run2: prog2
		./prog2

prog2: main.o
	g++ *.o -o prog2

main.o: main.cpp base.h
	g++ -c main.cpp



clean:
	rm -f *.o prog1 prog2