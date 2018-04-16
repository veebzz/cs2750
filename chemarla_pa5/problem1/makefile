C = gcc
CFLAGS = -Wall -g -std=c99 -lm
TARGET = wc
OBJS = fileStat.c

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

fileStat.o: fileStat.c
	$(CC) $(CFLAGS) -c fileStat.c


clean:
	/bin/rm -f *.o $(TARGET)
