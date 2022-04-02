CFLAGS = -g
CC = gcc
all : Main
Main : main.c 
	$(CC) $(CFLAGS)  main.c -g -o Run