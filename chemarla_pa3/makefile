#Vibhav Chemarla
#cs2750 PA 3
#03/18/2018

CC = gcc
 CFLAGS = -Wall -g -std=c99
 TARGET = sieve
 OBJS = main.o avg.o sum.o min.o max.o
 $(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c sum.h max.h min.h avg.h
	$(CC) $(CFLAGS) -c main.c
avg.o: avg.c sum.h avg.h
	$(CC) $(CFLAGS) -c avg.c
sum.o: sum.c 
	$(CC) $(CFLAGS) -c sum.c
min.o: min.c 
	$(CC) $(CFLAGS) -c min.c
max.o: max.c 
	$(CC) $(CFLAGS) -c max.c

clean:
	/bin/rm -f *.o $(TARGET)
