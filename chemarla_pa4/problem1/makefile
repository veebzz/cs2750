#Vibhav Chemarla
#cs2750 PA 4
#04/01/2018

CC = gcc

CFLAGS = -Wall -g -std=c99 -Wno-unused-variable

TARGET = deater

OBJS = main.o input.o subInput.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c input.h subInput.h
	$(CC) $(CFLAGS) -c main.c
input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c
subInput.o: subInput.c subInput.h
	$(CC) $(CFLAGS) -c subInput.c

clean:
	/bin/rm -f *.o $(TARGET)
