#Vibhav Chemarla
#cs2750 PA 4
#04/01/2018

CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET = phone
OBJS = phone.o phone_fmt.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

phone.o: phone.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone.c
phone_fmt.o: phone_fmt.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone_fmt.c

clean:
	/bin/rm -f *.o $(TARGET)
