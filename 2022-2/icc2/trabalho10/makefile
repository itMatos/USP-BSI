CC = gcc
CFLAGS = -Wall
objects = main.o Fila.o

main: trabalho.c
	$(CC) -o main Fila.o main.c

run: trabalho
	./trabalho
	
# Fila.o: Fila.c Fila.h
# 	$(CC) -c Fila.c
	
clean:
	rm main $(objects)
