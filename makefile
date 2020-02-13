#Makefile Matrix Testbench

PROG = MatrixTB
CC = gcc
CF = -c -Wall -pedantic -ansi
LF = -lm

OBJ = matrices_tb.o matrices_io.o matrices.o

$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(lm)
	rm $(OBJ)

%.o: %.c
	$(CC) $(CF) $< -DLOAD
